#!/bin/bash

usage() {
    echo "./test.sh [-h] [-r] [-d] [-i ws]"
    echo "-h, --help            Display a short help-message and exit."
    echo "-r, --relwithdebinfo  Run RelWithDebInfo version (default)"
    echo "-d, --debug           Run Debug version"
    echo "-i, --i3ws workspace  Run using i3-msg to specify workspace"
}

require_argument() {
    if [[ $# -eq 0 ]]; then
        echo "Missing argument"
        usage
        exit
    fi
}

config=RelWithDebInfo
i3ws=0

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
        -i|-i3ws)
            require_argument $@
            i3ws="$1"
            shift
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

if [[ $i3ws -ne 0 ]]; then
    i3-msg "workspace $i3ws"
fi

./PathCAD_Gui

