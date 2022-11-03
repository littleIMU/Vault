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
Up Level: (parent:: [c++](c++.md))

# __attribute__((__packed__))

**Padding** [aligns](http://en.wikipedia.org/wiki/Data_structure_alignment) structure members to "natural" address boundaries - say, `int` members would have offsets, which are `mod(4) == 0` on 32-bit platform. Padding is on by default. It inserts the following "gaps" into your first structure:

```
struct mystruct_A {
    char a;
    char gap_0[3]; /* inserted by compiler: for alignment of b */
    int b;
    char c;
    char gap_1[3]; /* -"-: for alignment of the whole struct in an array */
} x;

```

**Packing**, on the other hand prevents compiler from doing padding - this has to be explicitly requested - under GCC it's `__attribute__((__packed__))`, so the following:

```
struct __attribute__((__packed__)) mystruct_A {
    char a;
    int b;
    char c;
};

```

would produce structure of size `6` on a 32-bit architecture.

A note though - unaligned memory access is slower on architectures that allow it (like x86 and amd64), and is explicitly prohibited on *strict alignment architectures* like SPARC.

# `#pragma`

Other way to unalign memory of a struct is using `#pragma`

[C++ Struct memory alignment](https://carlosvin.github.io/langs/en/posts/cpp-pragma-pack/)

```matlab
#pragma pack (1)
struct SampleStructPack1
{
    bool flag;
    unsigned int timeout;
};
#pragma pack(0)
```