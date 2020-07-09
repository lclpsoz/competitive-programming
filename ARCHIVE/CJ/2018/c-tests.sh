#!/bin/bash

while true
do
	g++ c.cpp -std=c++11 -o run && python3 testing_tool.py ./run
done
