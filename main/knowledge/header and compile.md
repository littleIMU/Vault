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
Up Level: (parent:: [Programming](Programming.md))


### Demo

[header_example.tar.xz](header%20and%20compile/header_example.tar.xz)

### Reference

[Header files (C++)](https://docs.microsoft.com/en-us/cpp/cpp/header-files-cpp?view=msvc-170)
[Compiling and Executing Programs](https://www.cs.odu.edu/~cs252/Book/compilation.html)
[Learn How To Compile a C++ Program](https://betterprogramming.pub/learn-how-to-compile-a-c-program-382c4c690bdc)
[SeparateCompilation.pdf](header%20and%20compile/SeparateCompilation.pdf)

---

# Generation flow

![Untitled](header%20and%20compile/Untitled.png)

_main.cpp_

```cpp
#include "add.h" // Insert contents of add.h at this point.  Note use of double quotes here.
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << '\n';
    return 0;
}
```

_add.h_

```cpp
#ifndef ADD_H
#define ADD_H

int add(int x, int y);

#endif // !ADD_H
```

_add.cpp_

```cpp
#include "add.h" // Insert contents of add.h at this point. Note: use of double quotes here.

int add(int x, int y)
{
    return x + y;
}
```

## Pre-processing

For example, when the preprocessor processes the `#include "add.h"`line, it copies the contents of add.h into the current file at that point. Because our *add.h* contains a forward declaration for function *add,* that forward declaration will be copied into *main.cpp*. The end result is a program that is functionally the same as the one where we manually added the forward declaration at the top of *main.cpp.*

This can result in a dramatic increase in the amount of code that actually gets processed. The code shown here, for example, is pretty basic. But the `#include` statements bring in an entire library of I/O and string-related declarations from the C++ standard library.

You can read more about pre-processor directives [here](https://docs.microsoft.com/en-us/cpp/preprocessor/preprocessor-directives?view=vs-2019).

## Compilation

C++ compilation is itself a two-step process. First, the compiler takes the source code and converts it into *assembly language*. Assembly language is a low-level programming language that more closely resembles the machine instructions of a CPU.

Second, the source code now converted into assembly language is converted again into actual machine code using an *assembler*. The resulting output is a set of files stored in an intermediary file format known as an *object file (machine code)*.

## Linking

The final stage of the process is *linking,* which is concerned with taking our output from the previous step and linking it all together to produce the actual executable or library.

# Building

# Makefile

```cpp
CFLAGS = -O
CC = g++
NumTest:main.o add.o
	$(CC) $(CFLAGS) -o NumTest main.o add.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
add.o: add.cpp
	$(CC) $(CFLAGS) -c add.cpp
clean: 
	rm -f core *.o
```

A geany makefile example

[Creating A Geany Project](https://raspberry-projects.com/pi/programming-in-c/compilers-and-ides/geany/creating-a-project)

# Difference from hpp file

.hpp file can include both declaration and definition, based on this, there are some coding that can not be written in .hpp file. For more information, check the following link

[C++ 中的.hpp文件_夏之七的博客-CSDN博客_c++ hpp](https://blog.csdn.net/locahuang/article/details/119025666)

# Compile using g++

```
   g++ -g -c file1.cpp
   g++ -g -c file2.cpp
   g++ -g -c file3.cpp
   g++ -g -o programName file1.o file2.o file3.o -lm

==>
	g++ -g -o programName file1.cpp file2.cpp file3.cpp
```

![Untitled](header%20and%20compile/Untitled%201.png)

# Compilation tool

## compiling viewer

vscode, press **F9** to insert break point, and **F5**, in **Debug Console** below, add 

```bash
-exec disassemble /m main
```

### Output

```bash

int a = 1;
=> 0x0000555555555204 <+27>:	mov    DWORD PTR [rbp-0x2c],0x1

9	 int b = a;
   0x0000555555555178 <+15>:	mov    eax,DWORD PTR [rbp-0x8]
   0x000055555555517b <+18>:	mov    DWORD PTR [rbp-0x4],eax

10	  int &b = a;           // pass, the address of "a" is store in "b"
   0x000055555555520b <+34>:	lea    rax,[rbp-0x2c]
   0x000055555555520f <+38>:	mov    QWORD PTR [rbp-0x20],rax

11	  //int &b = 20;        // error, no address fo "20"
12	  const int &c = 20;    // pass, a temporary address for "20"
   0x0000555555555213 <+42>:	mov    eax,0x14
   0x0000555555555218 <+47>:	mov    DWORD PTR [rbp-0x28],eax
   0x000055555555521b <+50>:	lea    rax,[rbp-0x28]
   0x000055555555521f <+54>:	mov    QWORD PTR [rbp-0x18],rax

13	  int &&d = 20;         // pass,
   0x0000555555555223 <+58>:	mov    eax,0x14
   0x0000555555555228 <+63>:	mov    DWORD PTR [rbp-0x24],eax
   0x000055555555522b <+66>:	lea    rax,[rbp-0x24]
   0x000055555555522f <+70>:	mov    QWORD PTR [rbp-0x10],rax

14	    int b = a + 1;
   0x00005555555552df <+246>:	mov    eax,DWORD PTR [rbp-0x70]
   0x00005555555552e2 <+249>:	add    eax,0x1
   0x00005555555552e5 <+252>:	mov    DWORD PTR [rbp-0x6c],eax
```

exa: register which can store data

PTR: point

QWORD PTR <dest> <src>: move the data from <src> to <dest> 

## elf viewer

readelf -a main.o

[SPARC Assembly Language Reference Manual](https://docs.oracle.com/cd/E37838_01/html/E61063/elf-23207.html)

**The following sections are commonly present in an ELF file:**

- Section header.
- Executable text.
- Read-only data.
- Read-write data.
- Read-write uninitialized data (section header only)

## specifying max stack size

```bash
gcc test.c -o test.x -Wl,--stack=0x20000 -Wl,-Map=output.map

size -A -d test.x

nm test.x  | grep __size_of_stack_reserve__
```

## objdump
```bash
objjump -D test.o
```