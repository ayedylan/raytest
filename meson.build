project('raytest', 'c')

cc = meson.get_compiler('c')

deps = []

if host_machine.system() == 'windows'
  deps += [
    cc.find_library('winmm'),
  ]
elif host_machine.system() == 'darwin'
  link_args += [
    '-framework', 'AppKit',
    '-framework', 'IOKit',
  ]
elif host_machine.system() == 'linux'
  deps += [
    cc.find_library('m'),
    cc.find_library('dl'),
  ]
elif host_machine.system() == 'emscripten'
  link_args += [
    '-s', 'ENVIRONMENT=web',
    '-s', 'USE_GLFW=3',
  ]
  name_suffix = 'html'
endif

cmake = import('cmake')
raylib = cmake.subproject('raylib')
deps += [
     raylib.dependency('raylib'),
     ]

executable('raytest', 'src/main.c', dependencies : deps)
