project(
  'window',
  'c',
  version : '1.0',
  license: 'MIT',
  default_options : [
    'warning_level=3',
    'werror=true',
    'buildtype=debugoptimized',
    'c_std=c99',
  ],
)

curses = dependency('ncursesw')

executable('window', 'src/window.c',dependencies : curses)
message(
  'Building game of life v@0@\n\n'.format(meson.project_version())
)

