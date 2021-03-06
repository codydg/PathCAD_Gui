#!/bin/bash

usage() {
    echo "./build.sh [-h] [-r] [-d]"
    echo "-h, --help            Display a short help-message and exit."
    echo "-r, --relwithdebinfo  Build RelWithDebInfo (default)"
    echo "-d, --debug           Build Debug"
}

require_argument() {
    if [[ $# -eq 0 ]]; then
        echo "Missing argument"
        usage
        exit
    fi
}

config=RelWithDebInfo

while [[ $# -gt 0 ]]; do
    key="$1"
    shift
    case $key in
        -d|--debug)
            config=Debug
            ;;
        -r|--relwithdebinfo)
            config=RelWithDebInfo
            ;;
        -h|--help)
            usage
            exit
            ;;
        *)
            echo "Unknown Argument: $key"
            usage
            exit
            ;;
    esac
done

cd build/$config
make

