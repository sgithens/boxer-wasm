#!/bin/bash

function build-just-wasm () {
    echo "Building..."
    emcc -O2 \
         -sASYNCIFY -sASYNCIFY_STACK_SIZE=1048576 \
         -sASYNCIFY_IMPORTS=[cl_eval,js_test,js_read] \
         -sSTACK_SIZE=1048576 \
         -s TOTAL_MEMORY=197656576 \
         -sERROR_ON_UNDEFINED_SYMBOLS=0 \
         -sEXPORTED_RUNTIME_METHODS=ccall,cwrap,stringToNewUTF8,UTF8ToString \
         --embed-file "boxer-wasm.lisp" --embed-file "boxerdata" \
         --embed-file "asdf.lisp" --embed-file "help.doc"\
         -I/home/sgithens/code/ecl/ecl-emscripten/ \
         libecl{,gc,gmp}.a boxer-wasm.cpp -I./ -o boxer-wasm.js
}

build-just-wasm
