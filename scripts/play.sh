#!/usr/local/bin/bash

if [[ "$OSTYPE" == "linux-gnu" ]]; then
    ../build/algosynth | aplay
elif [[ "$OSTYPE" == "darwin"* ]]; then
    ../build/algosynth | play -traw -b8 -eunsigned-integer -r8000 -
fi
