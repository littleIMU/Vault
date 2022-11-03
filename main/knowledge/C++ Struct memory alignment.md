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
Up Level: (parent:: [DataType](DataType.md))



# Reference

[Structure padding and packing](https://stackoverflow.com/questions/4306186/structure-padding-and-packing)

[Alignment and Packing](https://en.algorithmica.org/hpc/cpu-cache/alignment/)

[why is data structure alignment important for performance?](https://stackoverflow.com/questions/2006216/why-is-data-structure-alignment-important-for-performance)

[计算机缓存Cache以及Cache Line详解](https://zhuanlan.zhihu.com/p/37749443)


# Question

- [ ]  For aligned struct, is there any chance to cross the cache lines? or, can i interpret that aligned struct has less possibility to cross the cache line boundary than non-aligned ones?

# Why

- Suppose the data begins in an address not dividable by 4 say for the sake of simplicity at address 1, the CPU must take data from address 0 and then apply some algorithm to dump the byte at the 0 address , to gain access to the actual data at byte 1. this takes time and therefore lowers preformance. so it is much more efficient to have all data addresses aligned. This potentially wastes space but saves a lot of CPU cycles. This trade-off is mostly beneficial, so structure alignment is enabled by default in most compilers.
- The fact that the memory is partitioned into 64B [cache lines](https://en.algorithmica.org/hpc/cpu-cache/cache-lines) makes it difficult to operate on data words that cross a cache line boundary. When you need to retrieve some primitive type, such as a 32-bit integer, you really want to have it located on a single cache line — both because retrieving two cache lines requires more memory bandwidth and stitching the results in hardware requires precious transistor space.

# Memory align (for struct)

**Rules:**

- Before each individual member, there will be padding so that to make it start at an address that is divisible by its size.e.g on 64 bit system,`int` should start at address divisible by 4, and `long` by 8, `short` by 2.
- `char` and `char[]` are special, could be any memory address, so they don't need padding before them.
- For `struct`, other than the alignment need for each individual member, the size of whole struct itself will be aligned to a size divisible by size of largest individual member, by padding at end.e.g if struct's largest member is `long` then divisible by 8, `int` then by 4, `short` then by 2.

**Order of member:**

- The order of member might affect actual size of struct, so take that in mind. e.g the `stu_c` and `stu_d` from example below have the same members, but in different order, and result in different size for the 2 structs.

---

## Address in memory (for struct)

**Rules:**

- **64 bit system**Struct address starts from `(n * 16)` bytes. (*You can see in the example below, all printed hex addresses of structs end with `0`.*)**Reason**: the possible largest individual struct member is 16 bytes (`long double`).
- ***(Update)*** If a struct only contains a `char` as member, its address could start at any address.

**Empty space**:

- Empty space between 2 structs could be used by non-struct variables that could fit in.e.g in `test_struct_address()` below, the variable `x` resides between adjacent struct `g` and `h`.No matter whether `x` is declared, `h`'s address won't change, `x` just reused the empty space that `g` wasted.Similar case for `y`.

---

# Example

(*for 64 bit system*)

**memory_align.c**:

```matlab
/**
 * Memory align & padding - for struct.
 * compile: gcc memory_align.c
 * execute: ./a.out
 */ 
#include <stdio.h>

// size is 8, 4 + 1, then round to multiple of 4 (int's size),
struct stu_a {
    int i;
    char c;
};

// size is 16, 8 + 1, then round to multiple of 8 (long's size),
struct stu_b {
    long l;
    char c;
};

// size is 24, l need padding by 4 before it, then round to multiple of 8 (long's size),
struct stu_c {
    int i;
    long l;
    char c;
};

// size is 16, 8 + 4 + 1, then round to multiple of 8 (long's size),
struct stu_d {
    long l;
    int i;
    char c;
};

// size is 16, 8 + 4 + 1, then round to multiple of 8 (double's size),
struct stu_e {
    double d;
    int i;
    char c;
};

// size is 24, d need align to 8, then round to multiple of 8 (double's size),
struct stu_f {
    int i;
    double d;
    char c;
};

// size is 4,
struct stu_g {
    int i;
};

// size is 8,
struct stu_h {
    long l;
};

// test - padding within a single struct,
int test_struct_padding() {
    printf("%s: %ld\n", "stu_a", sizeof(struct stu_a));
    printf("%s: %ld\n", "stu_b", sizeof(struct stu_b));
    printf("%s: %ld\n", "stu_c", sizeof(struct stu_c));
    printf("%s: %ld\n", "stu_d", sizeof(struct stu_d));
    printf("%s: %ld\n", "stu_e", sizeof(struct stu_e));
    printf("%s: %ld\n", "stu_f", sizeof(struct stu_f));

    printf("%s: %ld\n", "stu_g", sizeof(struct stu_g));
    printf("%s: %ld\n", "stu_h", sizeof(struct stu_h));

    return 0;
}

// test - address of struct,
int test_struct_address() {
    printf("%s: %ld\n", "stu_g", sizeof(struct stu_g));
    printf("%s: %ld\n", "stu_h", sizeof(struct stu_h));
    printf("%s: %ld\n", "stu_f", sizeof(struct stu_f));

    struct stu_g g;
    struct stu_h h;
    struct stu_f f1;
    struct stu_f f2;
    int x = 1;
    long y = 1;

    printf("address of %s: %p\n", "g", &g);
    printf("address of %s: %p\n", "h", &h);
    printf("address of %s: %p\n", "f1", &f1);
    printf("address of %s: %p\n", "f2", &f2);
    printf("address of %s: %p\n", "x", &x);
    printf("address of %s: %p\n", "y", &y);

    // g is only 4 bytes itself, but distance to next struct is 16 bytes(on 64 bit system) or 8 bytes(on 32 bit system),
    printf("space between %s and %s: %ld\n", "g", "h", (long)(&h) - (long)(&g));

    // h is only 8 bytes itself, but distance to next struct is 16 bytes(on 64 bit system) or 8 bytes(on 32 bit system),
    printf("space between %s and %s: %ld\n", "h", "f1", (long)(&f1) - (long)(&h));

    // f1 is only 24 bytes itself, but distance to next struct is 32 bytes(on 64 bit system) or 24 bytes(on 32 bit system),
    printf("space between %s and %s: %ld\n", "f1", "f2", (long)(&f2) - (long)(&f1));

    // x is not a struct, and it reuse those empty space between struts, which exists due to padding, e.g between g & h,
    printf("space between %s and %s: %ld\n", "x", "f2", (long)(&x) - (long)(&f2));
    printf("space between %s and %s: %ld\n", "g", "x", (long)(&x) - (long)(&g));

    // y is not a struct, and it reuse those empty space between struts, which exists due to padding, e.g between h & f1,
    printf("space between %s and %s: %ld\n", "x", "y", (long)(&y) - (long)(&x));
    printf("space between %s and %s: %ld\n", "h", "y", (long)(&y) - (long)(&h));

    return 0;
}

int main(int argc, char * argv[]) {
    test_struct_padding();
    // test_struct_address();

    return 0;
}
```

# Optimizing Member Order

```cpp
structData {
    int c;
    short b;
    char a;
    char d;
};
// each of them is aligned without any padding, and the size of the structure is just 8 bytes
```

# Packing

```cpp
struct __attribute__ ((packed)) Data {
    long long a;
    bool b;
};
// This makes the instances of Data take just 9 bytes instead of the 16 required by alignment, at the cost of possibly fetching two cache lines to reads its elements.
```