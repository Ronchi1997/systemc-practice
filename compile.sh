#!/bin/bash
g++ $1 -I /home/ronchi/systemc/include -L /home/ronchi/systemc/lib-linux64 -o $2 -lsystemc
