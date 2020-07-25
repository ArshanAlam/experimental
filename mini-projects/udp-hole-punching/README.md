# UDP Hole Punching

A simple client and server to setup **UDP Hole Punching** for NAT traversal.

The clients contact the server and informs the server of their public IPs.

The server informs the clients of their peers IP.

The peers try to contact each other using the IP they got from the server.
