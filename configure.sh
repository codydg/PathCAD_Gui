#!/bin/bash

config=RelWithDebInfo
cmake -S . -B build/$config -DCMAKE_BUILD_TYPE=$config
