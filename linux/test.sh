#!/bin/bash
rm -rf STF
rm -rf settings
g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o STF -Wwrite-strings -Wnarrowing -std=c++17
g++ -o settings settings.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
DRI_PRIME=0 ./STF
