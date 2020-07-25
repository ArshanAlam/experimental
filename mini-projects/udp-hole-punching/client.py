#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
  Arshan Alam

  client.py

  Create a simple client, that is behind a NAT firewall,
  for communicating with other clients using hole punching.
"""

import socket
import ast

BUFFER_SIZE_BYTES = 1024
BROKER_IP = "35.182.224.13"
BROKER_PORT = 49237
BYTE_DECODING = "utf-8"
BYTE_ENCODING = BYTE_DECODING

def init_socket():
  """
    init_server
    
    Initialize the UDP socket and bind it to the given host and port. 
  """
  sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  sock.bind(("", 0))
  return sock

def close_socket(sock):
  """
    close_socket

    @param sock - The socket to close

    Close a socket that was created using init_socket(...)
  """
  sock.close()

def beacon(sock, broker_ip, broker_port):
  """
    beacon

    @param sock - The socket to use
    @param broker_ip - IP of the broker (server)
    @param broker_port - Port of the broker

    Begin the client beacon that sends integers to another client.
  """
  sock.sendto(str(sock.getsockname()).encode(BYTE_ENCODING), (broker_ip, broker_port))
  data, addr = sock.recvfrom(BUFFER_SIZE_BYTES)

  for i in range(1, 10):
    sock.sendto(str(sock.getsockname()).encode(BYTE_ENCODING), (broker_ip, broker_port))
    data, addr = sock.recvfrom(BUFFER_SIZE_BYTES)

  if (data != b'0'):
    peer_addr_list = ast.literal_eval(data.decode(BYTE_DECODING))
    print("Peer Address list {}".format(peer_addr_list))
    
    for i in range(0, 10):
      sock.sendto(b'0', peer_addr_list[1])
      """
      for peer_addr in peer_addr_list:
        sock.sendto(b'0', peer_addr)
      """
    res, addr = sock.recvfrom(BUFFER_SIZE_BYTES)
    print("addr {} res {}".format(addr, res.decode(BYTE_DECODING)));
  
  for i in range(0, 65535):
    sock.sendto(str(i).encode(BYTE_ENCODING), addr)
    res, addr_delta = sock.recvfrom(BUFFER_SIZE_BYTES)
    print("addr {} res {}".format(addr, res.decode(BYTE_DECODING)));

if __name__ == "__main__":
  s = init_socket()
  # TODO: Figure out a way to close the socket
  beacon(s, BROKER_IP, BROKER_PORT)
  close_socket(s)
