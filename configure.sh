#!/bin/bash

config=RelWithDebInfo
cmake -S src -B build/$config -DCMAKE_BUILD_TYPE=$config
