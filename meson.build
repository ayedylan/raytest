project('raytest', 'c')

cmake = import('cmake')

raylib = cmake.subproject('raylib')

deps = raylib.dependency('raylib')

executable('raytest', 'main.c', dependencies : deps)