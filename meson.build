project(
    'foo_app', 
    'c', 'cpp',
    version : '0.1',
    default_options : [
      'c_std=c99',
      'cpp_std=c++17',
      'warning_level=everything',
      'default_library=static',
      'build_type=debugoptimized',
    ],
)

inc_dir = include_directories('src')

executable(
    'foo_app', 
    'src/foo.c',
    include_directories : inc_dir,
)
