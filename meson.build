project('raytest', 'c')

libm= meson.get_compiler('c').find_library('m')

cmake = import('cmake')

raylib = cmake.subproject('raylib')

deps = [
     raylib.dependency('raylib'),
     libm
     ]

executable('raytest', 'src/main.c', dependencies : deps)