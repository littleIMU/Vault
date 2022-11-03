---
priority: 3rd
status: dormant
url: 
category: 
parent: 
children: 
link_action: 
link_topic: 
link_project: 
link_course: 
link_notes: 
---
Up Level: (parent:: [Linux](Linux.md))

# Demo

[cmake_exa.tar.xz](Cmake/cmake_exa.tar.xz)

# Question

- [ ]  In what situation we use find_library and find_path?

# Create and Install

code is in`/t2`, key code 

```makefile
add_subdirectory(src)  // placed in the top directory, add the position of to-be-compiled files

# do not put there two sentences before, except for "install" command
add_exercutable(output_name output_source)
target_link_libraries(link_source link_destination)
```

A project structure template is shown as below;

```bash
<MainDIR>
	CMakelists.txt
	README
	COPYRIGHT
	xxx.sh
	<DOC>
		document
	<SRC>
		code
		CMakeLists.txt
```

---

enter /build

```bash
cmake -DCMAKE_INSTALL_PREFIX=<DIR> ..
make 
make install
```

# Dynamic and Static Lib

code is in`/t3`, key code

```makefile
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
```

enter /build

```bash
# other location like destop can cause link failure in /t4 "/usr/bin/ld: cannot find -lhello", why?????
cmake -DCMAKE_INSTALL_PREFIX=/tmp/usr/t2 ..
```

# Link lib

code is in `/t4`, key code

```makefile
add_executable(main main.c)
include_directories(/usr/include/hello)
# can not work, why????
# LINK_DIRECTORIES(<specificDir>)
target_link_libraries(main hello)
```

enter /build

```bash
cmake
```

# Debug Cmake

1. Read the output of CMake
2. Debug with --debug-output (for debug output) --trace (complete trace) and --trace-expand (trace and expanded variables).
3. Check the generated files like the CMakeCaches.txt, CmakeError.log and CMakeOuput.log