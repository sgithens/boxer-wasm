# Simple executable build

```lisp
;;; sgithens@Stevens-MacBook-Air boxer-wasm % ecl
;;; Loading "/Users/sgithens/quicklisp/setup.lisp"
;;; Loading #P"/opt/homebrew/Cellar/ecl/21.2.1_1/lib/ecl-21.2.1/asdf.fas"
> (compile-file "hello.lisp" :system-p t)

;;;
;;; Compiling hello.lisp.
;;; OPTIMIZE levels: Safety=2, Space=0, Speed=3, Debug=0
;;;
;;; End of Pass 1.
;;; Finished compiling hello.lisp.
;;;
#P"/Users/sgithens/code/boxer-wasm/hello.o"
NIL
NIL
> (c:build-program "hello" :lisp-files '("hello.o"))

#P"hello"
>

;; Building a static library
> (c:build-static-library "libhello" :lisp-files '("hello.o") :init-name "init_hello")

#P"liblibhello.a"
```

