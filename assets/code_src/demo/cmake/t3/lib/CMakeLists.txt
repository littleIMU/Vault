set(libhello hello.c)
add_library(hello SHARED ${libhello})
add_library(hello_static STATIC ${libhello})
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")
# SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)
# SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1) 
# SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

INSTALL(TARGETS hello hello_static
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
INSTALL(FILES hello.h DESTINATION include/hello)