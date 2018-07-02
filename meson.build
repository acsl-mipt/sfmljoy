project('sfmljoy', 'cpp', default_options : 'cpp_std=c++11')

cc = meson.get_compiler('cpp')

src = [
  'src/SFML/System/Clock.cpp',
  'src/SFML/System/Err.cpp',
  'src/SFML/System/String.cpp',
  'src/SFML/System/Time.cpp',
  'src/SFML/Window/Joystick.cpp',
  'src/SFML/Window/JoystickManager.cpp',
]

deps = []

if target_machine.system() == 'windows'
  src += 'src/SFML/System/Win32/ClockImpl.cpp'
  src += 'src/SFML/Window/Win32/JoystickImpl.cpp'
  deps += cc.find_library('winmm', required : true)
elif target_machine.system() == 'linux'
  src += 'src/SFML/System/Unix/ClockImpl.cpp'
  src += 'src/SFML/Window/Unix/JoystickImpl.cpp'
  deps += dependency('libudev', required : true)
#  deps += cc.find_library('rt', required : true)
else
  error('Unsupported OS')
endif

deps += dependency('threads', required : true)

sfmljoy_lib = static_library('sfmljoy',
  name_prefix : 'lib',
  sources : src,
  include_directories : include_directories('include', 'src'),
  dependencies: deps,
)

sfmljoy_dep = declare_dependency(
  link_with : sfmljoy_lib,
  include_directories : include_directories('include', is_system : true),
  dependencies : deps,
)
