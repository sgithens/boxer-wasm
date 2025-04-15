# Boxer WASM

This is a work in progress prototype of the Boxer frontend running in a browser using
the ECL (Embedded Common Lisp) compiler, Emscripten, and three.js.

Currently it requires a number of binary and other source assets as part of the
directory to build. You can find a full version of these, as well as a full build
that can be run with a static webserver in one of the releases. Simply,

```sh
# Download, unzip, and enter the release build
python3 -m http.server
# load http://localhost:8000/boxer-wasm.html in your browser
```

# Notes / Todo

- The `asdf.lisp` file is currently being included as part of the build manually due
  to some errors occuring when trying to use the ecl switches to bundles it.
- The `help.doc` file is required to be present when loading asdf else an error occurs.
- `libecl.a`, `libeclgc.a`, `libeclgmp.a` are used from the current directory when
  building. These are the result of compiling ECL against the emscripten target.
- Currently, the `-I` include to the ecl-emscripten headers is hardcoded in the
  `make.sh` script.
- A folder named `boxerdata` needs to be present that includes the Boxer source as well
  as the quicklisp directory with all the dependencies. If you download the release zip
  file, these are all bundled.
- When all of these assets are present you can build and serve with:
  `./make.sh ; python3 -m http.server` or whatever your favorite static file server is.
