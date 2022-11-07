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

#cpp/advance

# Reference

[Algorithms for Modern Hardware](https://en.algorithmica.org/hpc/)


# Question

- [ ]  Same random when the Gaussian random generator starts off, why?


# [std::Make_unique](https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/memory/unique_ptr/make_unique.html)

Constructs an object of type `T` and wraps it in a [std::unique_ptr](https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/memory/unique_ptr.html).

# [constexpr](https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/)

Unlike **`const`**, **`constexpr`** can also be applied to functions and class constructor.  **`constexpr`** indicates that the value, or return value, is constant and, where possible, is computed at compile time.

A **`constexpr`** integral value can be used wherever a const integer is required, such as in template arguments and array declarations. And when a value is computed at compile time instead of run time, it helps your program run faster and use less memory.

```cpp
// C++ program to demonstrate constexpr function for product
// of two numbers. By specifying constexpr, we suggest
// compiler to to evaluate value at compile time
#include <iostream>
  
constexpr int product(int x, int y) { return (x * y); }
  
int main()
{
    constexpr int x = product(10, 20); // this will not be exercuted again in run time
    std::cout << x;
    return 0;
}
```

# std::thread

## mutex procedure

Creates a mutex, referenced by mutex, with attributes specified by attr. If attr is NULL, the default mutex attribute (NONRECURSIVE) is used.

If the mutex is already locked by another thread, the thread waits for the mutex to become available. The thread that has locked a mutex becomes its current owner and remains the owner until the same thread has unlocked it. When the mutex has the attribute of recursive, the use of the lock may be different. When this kind of mutex is locked multiple times by the same thread, then a count is incremented and no waiting thread is posted. The owning thread must call pthread_mutex_unlock() the same number of times to decrement the count to zero.

## Compare among std::thread, boost:thread and pthread

- `std::thread`
    - Pro: Is standard; guaranteed to be on all conforming platforms.
    - Con: Requires C++11, so it cannot be used with ancient. compilers. Only basic, lowest common denominator features. However, platform specific features can still be used through `std::thread::native_handle`.
- `boost::thread`
    - Pro: Is cross platform, is supported on ancient compilers.
    - Con: Is not standard; requires an external dependency. Similar feature set as standard threads.
- `pthread`:
    - Pro: Has more features such as schduling policy.
    - Con: Is only on POSIX systems, which excludes Windows. Non-RAII interface.

> When should one implementation be used over the others?
> 

`std::thread` is often a good default. If you need features of `pthread` that are not in the standard, you can use them with the help of `std::thread::native_handle` (with the implications on the portability that come with it). There's no reason to use `pthread` directly otherwise (that I know of) in C++.

`boost::thread` can be used if you need ancient pre-C++11 support, to remain portable to other systems.

# unique_ptr

The unique_ptr internally uses move member functions (constructor and assignment). Since, these members accepts only an R-value parameter, therefore unique_ptr will not accept any L-value unique_ptr. The reason behind this design is that a user must do an explicit move and pass an R-value. Therefore, there shall be no chance of unintended copy. Finally, the move shall transfer ownership of resource by explicit move of internal resource.

- A `unique_ptr`may alternatively own no object, in which case it is called *empty*.
- It disposes of that object when the `unique_ptr` goes out of scope.

There are two versions of `std::unique_ptr`:

1. Manages a single object (e.g. allocated with new)
2. Manages a dynamically-allocated array of objects (e.g. allocated with new[])

## implementation

```cpp
#include <iostream>  //main header
using namespace std; //namespace

template<typename T>
class the_unique_ptr  //smart pointers implementation
{
    T* up_data;

    public:
    the_unique_ptr(T* p) 
    {
        up_data = p;
    }
    
    the_unique_ptr(const the_unique_ptr& up_rhs) = delete; // construction with same point is illegal
    
    the_unique_ptr(the_unique_ptr&& up_rhs)
    {
        up_data = std::move(up_rhs.up_data);
        up_rhs.up_data = NULL;
    }
    the_unique_ptr& operator=
            (const the_unique_ptr& up_rhs) = delete; // = same point is illegal

    the_unique_ptr& operator=
            (the_unique_ptr&& up_rhs)
    {
        up_data = std::move(up_rhs.up_data);

        up_rhs.up_data = NULL;
        return (*this);
    }
    T& operator*()
    {
        return (*up_data);
    }
    T* operator->()
    {
        return up_data;
    }
    ~the_unique_ptr()
    {
        cout << "Automatic clean-up" 
             << endl;
        if(up_data)
            delete up_data;
        up_data = NULL;
    }
};

int main()
{
    the_unique_ptr<int> up1 = new int(2);
    the_unique_ptr<int> up2 = std::move(up1);
    *up2 = 4;
    cout << *up2 << endl;

    the_unique_ptr<std::string> up3 = 
                       new std::string("mainfunda");
    the_unique_ptr<std::string> up4 = std::move(up3);
    cout << *up4 << endl;
    cout << up4->size() << endl;

    return 0;
}
```

Output

```cpp
4
mainfunda
9
Automatic clean-up
Automatic clean-up
Automatic clean-up
Automatic clean-up
```

# auto_ptr

[Smart Pointers : Implementation of unique_ptr & auto_ptr | Main Funda](https://mainfunda.com/unique_ptr-auto_ptr/)

# lvalue and rvalue

An lvalue has an address that your program can access. Examples of lvalue expressions include variable names, including **`const`** variables, array elements, function calls that return an lvalue reference, bit-fields, unions, and class members.

A prvalue expression has no address that is accessible by your program. Examples of prvalue expressions include literals, function calls that return a non-reference type, and temporary objects that are created during expression evaluation but accessible only by the compiler.

# prvalue

- [ ]  #Ques Is the lifetime within a sentence?

If it has identity, but cannot be moved it’s an lvalue; otherwise it’s an rvalue. A typical lvalue is a variable name a.
If it can be moved, but has no identity is a prvalue (pure right value); otherwise it’s a glvalue (generalized left value). A typical prvalue is a temporary resulting from a function call/operator (with a non-reference return type) like s.substr(1, 2) or a + b or integral constant like 42.
If it has an identity and can be moved it’s an xvalue (because that was considered strange, and x is a good prefix for weird things). A typical xvalue is std::move(a).

```cpp
int main()
{
    int i, j, *p;

    // Correct usage: the variable i is an lvalue and the literal 7 is a prvalue.
    i = 7;

    // Incorrect usage: The left operand must be an lvalue (C2106).`j * 4` is a prvalue.
    7 = i; // C2106
    j * 4 = 7; // C2106

    // Correct usage: the dereferenced pointer is an lvalue.
    *p = i;

    // Correct usage: the conditional operator returns an lvalue.
    ((i < 3) ? i : j) = 7;

    // Incorrect usage: the constant ci is a non-modifiable lvalue (C3892).
    const int ci = 7;
    ci = 9; // C3892
}
```

# std::allocator

//? why ros generated msg has <ContainerAllocator>?

the following code:

```cpp
std::vector<X> v;
v.reserve(4);        // (1)
v.push_back( X{} );  // (2)
v.push_back( X{} );  // (3)
v.clear();           // (4)
```

Here line (1) must allocate enough memory for four objects, but not construct them yet. Then lines (2) and (3) must construct objects into the allocated memory. Then line (4) must destroy those objects, but not deallocate the memory. Finally, in the vector's destructor, all the memory can be deallocated.

# code optimization in compiler design

What is optimization in compiling

[Code Optimization in Compiler Design - GeeksforGeeks](https://www.geeksforgeeks.org/code-optimization-in-compiler-design/)

A practical journey

[Optimizations in C++ Compilers](https://queue.acm.org/detail.cfm?id=3372264)

# emplace, forward and variadic templates

[piecewise_construct存在的意义 - PKICA - 博客园](https://www.cnblogs.com/guxuanqing/p/11396511.html)

```cpp
#include <iostream>
#include <vector>
#include <map>

struct Bar {
public:
    Bar(int _a)
    : a(_a){}
    explicit Bar(int _a, double _b) 
    :a(_a),b(_b){}

    int a;
    double b;
};

int main(void)
{
    std::vector<Bar> bv;
    bv.push_back(1); // 隐式转换生成临时变量
    bv.push_back(Bar(1)); // 显示构造临时变量
    bv.emplace_back(1); // 没有临时变量

    //bv.push_back({1, 2.0}); // 无法进行隐式转换
    bv.push_back(Bar(1, 2.0)); // 显示构造临时变量
    bv.emplace_back(1, 2.0); // 没有临时变量
		// bv.emplace_back(1, 2.0, 3.0); // compile error, no matching function
    for (int i = 0; i < bv.size(); i++){
      std::cout << bv[i].b << std::endl;
    }

    return 0;
}
```

Output:

```cpp
4.63557e-310
4.63557e-310
0
2
2
```

# emplace_back object

[C++ | Difference between calling emplace_back and push_back](https://www.nextptr.com/question/qa1254410617/difference-between-calling-emplace_back-and-push_back)

```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Foo {
 Foo(int i) { 
  std::cout << "ctor "; 
 }

 Foo(const Foo& f) {
  std::cout << "cpy ";
 }

 Foo(Foo&&) {
   std::cout << "mov ";
 }

 //... more code ...

 ~Foo() {
    std::cout << "dtor ";
  }
};

int main()
{
    std::vector<Foo> v;
    /* Reserve space for at least 2 elements
      to avoid reallocation. */
    v.reserve(2);

    // insert
    v.push_back(10);

    // emplace
    v.emplace_back(20);

    std::cout << std::endl;
    std::cout << "The End" << std::endl;
    return 0;
} //vector and its elements are destroyed on exit
```

OUTPUT

```cpp
hello

hello
dec
dec
```

# std::piecewise_construct

[What's up with std::piecewise_construct and std::forward_as_tuple?](https://devblogs.microsoft.com/oldnewthing/20220428-00/?p=106540)

This is where std::piecewise_construct enters the story.

The std::pair wants to let you construct the components in place. The existing two-parameter constructor tries to construct the first element from the first parameter and the second element from the second parameter:

```cpp
struct T1
{
T1(int);
T1(int, std::string);
};

struct T2
{
T2(std::string);
T2();
};

auto f()
{
// uses T1(a1) and T2(a2)
return std::pair<T1, T2>(a1, a2);
}
```

If you want to use a T1 or T2 constructor that takes any number of parameters other than one, you can pack them into tuples, and use the marker value std::piecewise_construct to say, “Hey, like, don’t pass the tuples as-is to the constructors. Instead, unpack the tuples and invoke the constructors with the tuple elements.”

```cpp
auto f()
{
// without piecewise_construct: tries to use
//      T1(std::tuple<int, char const*>(42, "hello"))
// and  T2(std::tuple<>())
// (neither of which works)
return std::pair<T1, T2>(
std::make_tuple(42, "hello"),
std::make_tuple());
}

auto f()
{
// with piecewise_construct:
// uses T1(42, "hello")
// and  T2()
return std::pair<T1, T2>(
std::piecewise_construct,
std::make_tuple(42, "hello"),
std::make_tuple());
}
```

In particular, you’re likely to use it with std::map::emplace, since that takes a pair.

```cpp
std::map<T1, T2> m;

m.emplace(
    std::piecewise_construct,
    std::make_tuple(42, "hello"),
    std::make_tuple());
```

map with class inside 

```cpp
#include <iostream>
#include <map>

class pose{
public:
    int a;
    int b;
    pose(int a_, int b_):a(a_), b(b_){}
    int func(){
        return this->a;
    };
};

int main ()
{
  std::map<char,pose> mymap;

  mymap.emplace(
		// std::piecewise_construct, std::forward_as_tuple(99), // return c 
    std::piecewise_construct, std::forward_as_tuple('c'),
		// the construction of pose decide next tuple
    std::forward_as_tuple(
        1,2
			//'c', 2 // return 99  
    ));

  std::cout << "mymap contains:";
  for (auto& x: mymap)
    std::cout << " [" << x.first << ':' << x.second.func() << ']';
  std::cout << '\n';

  return 0;
}
```

Output:

```cpp
mymap contains: [c:2]
```

# GUARD_BY

通过代码注解（annotations ）告诉编译器哪些成员变量和成员函数是受哪个 mutex 保护，这样如果忘记了加锁，编译器会给警告。

```cpp
//* "GUARDED_BY" tells the compiler that local_slam_data_ is protected by mutex_
  //* Error appears in pre-compilation if you forget to lock the thread for local_slam_data_ 
  std::unordered_map<int,
                     std::shared_ptr<const LocalTrajectoryData::LocalSlamData>>
      local_slam_data_ GUARDED_BY(mutex_);

// case 
std::shared_ptr<const LocalTrajectoryData::LocalSlamData> local_slam_data;
    {
      absl::MutexLock lock(&mutex_);  // Error appeas when this sentence is not added
      if (local_slam_data_.count(trajectory_id) == 0) {
        continue;
      }
      local_slam_data = local_slam_data_.at(trajectory_id);
    }
```

# std::forward_as_tuple

```cpp
#include <iostream>
#include <map>
#include <tuple>
#include <string>
 
int main()
{
    std::map<int, std::string> m;
 
    m.emplace(std::piecewise_construct,
              std::forward_as_tuple(10),
              std::forward_as_tuple(20, 'a'));
    std::cout << "m[10] = " << m[10] << '\n';
 
    // The following is an error: it produces a
    // std::tuple<int&&, char&&> holding two dangling references.
    //
    // auto t = std::forward_as_tuple(20, 'a');
    // m.emplace(std::piecewise_construct, std::forward_as_tuple(10), t);
}
```

Output:

```cpp
m[10] = aaaaaaaaaaaaaaaaaaaa
```

# std::get

```cpp
#include <iostream>
#include <tuple>
#include <functional>
 
std::tuple<int, int> f() // this function returns multiple values
{
    int x = 5;
    return std::make_tuple(x, 7); // return {x,7}; in C++17
}
 
int main()
{
    // heterogeneous tuple construction
    int n = 1;
    auto t = std::make_tuple(10, "Test", 3.14, std::ref(n), n);
    n = 7;
    std::cout << "The value of t is "  << "("
              << std::get<0>(t) << ", " << std::get<1>(t) << ", "
              << std::get<2>(t) << ", " << std::get<3>(t) << ", "
              << std::get<4>(t) << ")\n";
 
    // function returning multiple values
    int a, b;
    std::tie(a, b) = f();
    std::cout << a << " " << b << "\n";
}
```

Output:

```cpp
The value of t is (10, Test, 3.14, 7, 1)
5 7
```