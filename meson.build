project('raytest', 'c')

cmake = import('cmake')

raylib = cmake.subproject('raylib')
libm = cmake.subproject('openlibm')


deps = [
     raylib.dependency('raylib'),
     libm
     ]

executable('raytest', 'src/main.c', dependencies : deps)
