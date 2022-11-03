add_executable(main main.c)
include_directories(/usr/include/hello)
# can not work, why????
# LINK_DIRECTORIES(<specificDir>)
target_link_libraries(main hello)