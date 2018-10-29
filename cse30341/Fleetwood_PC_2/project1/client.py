#!/afs/nd.edu/user14/csesoft/2017-fall/anaconda3/bin/python3.6
# -*- coding: UTF-8 -*-

# Eric Layne (elayne) & Gabriel King (gking5)
# ZMQ subscriber client to accept and display published messages

import sys
import signal
import zmq
import datetime

# create signal handler
def signal_handler(signal, frame):
	print('interrupt signal 2 received.')
	sys.exit(0)

# establish zmq context and create socket as subscriber

context = zmq.Context()
socket = context.socket(zmq.SUB)
socket.setsockopt_string(zmq.SUBSCRIBE, '')

# connect socket to port from launch args

port = 61717; # establish default port
if (len(sys.argv) > 1):
  port = sys.argv[1];
print("connecting to tcp://localhost:%s" % port)
socket.connect("tcp://localhost:%s" % port)

# loop indefinitely in anticipation of messages

while (1):
  # print message and timestamp
  print("waiting")
  signal.signal(signal.SIGINT, signal_handler)
  message = socket.recv_string()
  # print(message);  
  print(message + str(datetime.datetime.now()))
