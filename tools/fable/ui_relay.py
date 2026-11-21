#!/usr/bin/env python3
"""Relay 0.0.0.0:6465 -> the app on 127.0.0.1:6464 so a Windows browser can reach it when WSL2 localhost forwarding is
broken after a restart: open http://<wsl ip>:6465/?k=<secret> (hostname -I gives the ip, it changes per WSL start).
The app only answers Host 127.0.0.1:6464 / localhost:6464, so every request's Host header is rewritten (keep-alive
connections carry many requests, so the rewrite is done on the whole client stream, not just the first request).
    nohup python3 tools/fable/ui_relay.py > /dev/null 2>&1 &"""
import asyncio, re

HOST = re.compile(rb"(?im)^host:[^\r\n]*")
TARGET = ("127.0.0.1", 6464)


async def client_to_server(r, w):
    buf = b""
    try:
        while True:
            try:
                data = await asyncio.wait_for(r.read(65536), timeout=0.05)
            except asyncio.TimeoutError:
                data = None
            if data is None:            # quiet: flush everything, even a possible partial line
                if buf:
                    w.write(HOST.sub(b"Host: 127.0.0.1:6464", buf)); buf = b""; await w.drain()
                continue
            if not data:
                break
            buf += data
            cut = buf.rfind(b"\n")      # hold back a trailing partial line (a split Host header)
            if cut == -1 or len(buf) - cut > 80:
                cut = len(buf)
            else:
                cut += 1
            w.write(HOST.sub(b"Host: 127.0.0.1:6464", buf[:cut])); buf = buf[cut:]; await w.drain()
        if buf:
            w.write(HOST.sub(b"Host: 127.0.0.1:6464", buf)); await w.drain()
    except Exception:
        pass
    finally:
        try: w.close()
        except Exception: pass


async def server_to_client(r, w):
    try:
        while True:
            data = await r.read(65536)
            if not data:
                break
            w.write(data); await w.drain()
    except Exception:
        pass
    finally:
        try: w.close()
        except Exception: pass


async def handle(cr, cw):
    try:
        sr, sw = await asyncio.open_connection(*TARGET)
    except Exception:
        cw.close(); return
    await asyncio.gather(client_to_server(cr, sw), server_to_client(sr, cw))


async def main():
    srv = await asyncio.start_server(handle, "0.0.0.0", 6465)
    async with srv:
        await srv.serve_forever()

asyncio.run(main())
