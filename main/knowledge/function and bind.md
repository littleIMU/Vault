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
Up Level: (parent:: [c++ basic](c++%20basic.md))

### Reference

[std::function](https://en.cppreference.com/w/cpp/utility/functional/function)

[bind.hpp](https://cs.brown.edu/~jwicks/boost/libs/bind/bind.html#with_functions)

[Bind Function and Placeholders in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/bind-function-placeholders-c/)

---

# bind

```cpp
// bind covers the functionality of std::bind1st as well:
std::bind1st(std::ptr_fun(f), 5)(x);   // f(5, x)
bind(f, 5, _1)(x);                     // f(5, x)

// bind can handle functions with more than two arguments, and its argument substitution mechanism is more general:
bind(f, _2, _1)(x, y);                 // f(y, x)
bind(g, _1, 9, _1)(x);                 // g(x, 9, x)
bind(g, _3, _3, _3)(x, y, z);          // g(z, z, z)
bind(g, _1, _1, _1)(x, y, z);          // g(x, x, x)

// bind member funtions
bind(&X::f, ref(x), _1)(i);		// x.f(i)
bind(&X::f, &x, _1)(i);			//(&x)->f(i)
bind(&X::f, x, _1)(i);			// (internal copy of x).f(i)
bind(&X::f, p, _1)(i);			// (internal copy of p)->f(i)

// placeholder like _1, _2, etc. which of the number starts based on existing argument. 
void func(int a, int b, int c)
{
    cout << (a - b - c) << endl;
}
auto fn2 = bind(func, 2, _1, _2);
fn2(13, 1); // = 2 - 13 - 1
// the out is -12
~~auto fn2 = bind(func, 2, _2, _3);  //error: no match for call to~~

//
~~~~struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    int data = 10;
};
Foo foo;
~~~~auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
				//std::bind(member_function, pointer to an object, ..)
foo.data = 1000;
f3(5);
// the out is (95 + 5) = 100, and the vaule of data is 1000;
auto f3 = std::bind(&Foo::print_sum, foo, 95, _1);
foo.data = 1000;
f3(5);
// the out is (95 + 5) = 100, however the vaule of data is 10. Because this case, you are passing an object of type foo by value, resulting in a copy of an object of type Foo.

~~~~
```

# Function

```cpp
#include <functional>
#include <iostream>
 
struct Foo {
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_+i << '\n'; }
    int num_;
};
 
void print_num(int i)
{
    std::cout << i << '\n';
}
 
struct PrintNum {
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};
 
int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
 
    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();
 
    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();
 
    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    const Foo foo(314159);
    f_add_display(foo, 1);
    f_add_display(314159, 1);
 
    // store a call to a data member accessor
    std::function<int(Foo const&)> f_num = &Foo::num_;
    std::cout << "num_: " << f_num(foo) << '\n';
 
    // store a call to a member function and object
    using std::placeholders::_1;
    std::function<void(int)> f_add_display2 = std::bind( &Foo::print_add, foo, _1 );
    f_add_display2(2);
 
    // store a call to a member function and object ptr
    std::function<void(int)> f_add_display3 = std::bind( &Foo::print_add, &foo, _1 );
    f_add_display3(3);
 
    // store a call to a function object
    std::function<void(int)> f_display_obj = PrintNum();
    f_display_obj(18);
 
    auto factorial = [](int n) {
        // store a lambda object to emulate "recursive lambda"; aware of extra overhead
        std::function<int(int)> fac = [&](int n){ return (n < 2) ? 1 : n*fac(n-1); };
        // note that "auto fac = [&](int n){...};" does not work in recursive calls
        return fac(n);
    };
    for (int i{5}; i != 8; ++i) { std::cout << i << "! = " << factorial(i) << ";  "; }
}
```