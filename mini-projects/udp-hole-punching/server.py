#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
  Arshan Alam

  server.py

  Create a simple server that acts as a broker,
  between clients behind a NAT firewall, and
  facilitates a p2p UDP connection using hole punching.
"""

import socket
import ast

BUFFER_SIZE_BYTES = 1024
HOST = ""
PORT = 49237
BYTE_ENCODING = "utf-8"
BYTE_DECODING = BYTE_ENCODING

def init_socket(host, port):
  """
    init_server
    
    @param host - Host that this socket will bind on
    @param port - Port that this socket will be listening on

    Initialize the UDP socket and bind it to the given host and port. 
  """
  sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  sock.bind((host, port))
  return sock

def close_socket(sock):
  """
    close_socket

    @param sock - The socket to close

    Close a socket that was created using init_socket(...)
  """
  sock.close()

def broker(sock):
  """
    broker

    @param sock - The socket to use

    Begin the broker on the given socket.
  """
  while True:
    data_A, addr_A = sock.recvfrom(BUFFER_SIZE_BYTES)
    data_B, addr_B = sock.recvfrom(BUFFER_SIZE_BYTES)
    local_addr_A = ast.literal_eval(data_A.decode(BYTE_DECODING))
    local_addr_B = ast.literal_eval(data_B.decode(BYTE_DECODING))
    sock.sendto(str([local_addr_B, addr_B]).encode(BYTE_ENCODING), addr_A)
    sock.sendto(str([local_addr_A, addr_A]).encode(BYTE_ENCODING), addr_B)
    print("Broker connection between A {} and B {}".format(addr_A, addr_B))

if __name__ == "__main__":
  s = init_socket(HOST, PORT)
  broker(s)
  # TODO: Figure out a way for the broker to return so we could close the socket
  close_socket(s)
