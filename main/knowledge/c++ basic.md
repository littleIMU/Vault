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

#cpp/basic

# Reference

# Union

- Each time a new variable is initialized from the union it overwrites the previous in C language but in C++ we also don’t need this keyword and uses that memory location.
- This is most useful when the type of data being passed through **[functions](https://www.geeksforgeeks.org/functions-in-c/)** is unknown, using a union which contains all possible data types can remedy this problem.

```cpp
// C++ program to illustrate the use
// of the unions
#include <iostream>
using namespace std;

// Defining a Union
union GFG {
	int Geek1;
	char Geek2;
	float Geek3;
};

// Driver Code
int main()
{
	// Initializing Union
	union GFG G1;

	G1.Geek1 = 34;

	// Printing values
	cout << "The first value at "
		<< "the allocated memory : " << G1.Geek1 << endl;

	G1.Geek2 = 34;

	cout << "The next value stored "
		<< "after removing the "
		<< "previous value : " << G1.Geek2 << endl;

	G1.Geek3 = 34.34;

	cout << "The Final value value "
		<< "at the same allocated "
		<< "memory space : " << G1.Geek3 << endl;
	return 0;
}
```

Output

```cpp
The first value at the allocated memory : 34
The next value stored after removing the previous value : "
The Final value value at the same allocated memory space : 34.34
```

## struct in union

all member variables share the same memory and start in the same location

```cpp
#include <stdio.h>  
#include <string.h>  
int main()  
{   
	union {                   /*定义一个联合*/
		  char i[60];
		  int x;
		  struct {             /*在联合中定义一个结构*/
			  char first;
			  char second;
			  char third;
			  char fourth;
			  char five;
		  }str;
	  }number;
	  strcpy(number.i, "abcde");
	  printf("%s\n",number.i);//输出结果"abcde"
	  printf("%c%c\n", number.str.first, number.str.second);//输出结果"ab"
	  printf("%c%c%c\n", number.str.third, number.str.fourth, number.str.five);//输出结果"abcde"
	  printf("%d\n",sizeof(number));//输出结果60
      return 0;
}
```

# Enum

```cpp
// C++ program to illustrate the use
// of the Enums

#include <bits/stdc++.h>
using namespace std;

// Defining an enum
enum GeeksforGeeks { Geek1,
					Geek2 = 3,
					Geek3 };

GeeksforGeeks G1 = Geek1;
GeeksforGeeks G2 = Geek2;
GeeksforGeeks G3 = Geek3;

// Driver Code
int main()
{
	cout << "The numerical value "
		<< "assigned to Geek1 : "
		<< G1 << endl;

	cout << "The numerical value "
		<< "assigned to Geek2 : "
		<< G2 << endl;

	cout << "The numerical value "
		<< "assigned to Geek3 : "
		<< G3 << endl;

	return 0;
}
```

Output:

```cpp
The numerical value assigned to Geek1 : 0
The numerical value assigned to Geek2 : 3
The numerical value assigned to Geek3 : 4
```

## Enum class

**What is the difference between the two?**

- `enum class`es - enumerator names are **local** to the enum and their values do *not* implicitly convert to other types (like another `enum` or `int`)
- Plain `enum`s - where enumerator names are in the same scope as the enum and their values implicitly convert to integers and other types

Example:

```cpp
enum Color { red, green, blue };                    // plain enum 
enum Card { red_card, green_card, yellow_card };    // another plain enum 
enum class Animal { dog, deer, cat, bird, human };  // enum class
enum class Mammal { kangaroo, deer, human };        // another enum class

void fun() {

    // examples of bad use of plain enums:
    Color color = Color::red;
    Card card = Card::green_card;

    int num = color;    // no problem

    if (color == Card::red_card) // no problem (bad)
        cout << "bad" << endl;

    if (card == Color::green)   // no problem (bad)
        cout << "bad" << endl;

    // examples of good use of enum classes (safe)
    Animal a = Animal::deer;
    Mammal m = Mammal::deer;

    int num2 = a;   // error
    if (m == a)         // error (good)
        cout << "bad" << endl;

    if (a == Mammal::deer) // error (good)
        cout << "bad" << endl;

}
```

# Function Pointer

A function’s name can also be used to get functions’ address.

```cpp
#include <stdio.h>
// A normal function with an int parameter
// and void return type
void fun(int a)
{
    printf("Value of a is %d\n", a);
}
  
void fun1(int a) { printf("fun1's value is %d\n"); }

void wrapper(void (*fun)(int), int a){
	fun(a);
}

int main()
{
    // fun_ptr is a pointer to function fun() 
    void (*fun_ptr)(int) = fun;
  
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
  
    // Invoking fun() using fun_ptr
    fun_ptr(10);
	wrapper(fun1, 5);
    return 0;
}
```

Output:

```cpp
Value of a is 10
funn1's value of a is 5
```

# =delete

Compiler disable function which is tailed with “=delete”

```cpp
class A{    
public:
	A(int x) : m(x) {}
	A& operator = (const A &) = delete;  // 声明拷贝赋值操作是删除函数
    A(const A&) = delete;                // 声明构造拷贝是删除函数

private:
   int m;
};

int main(){
  A a1(1), a2(2), a3(3);
  a1 = a2;     // 报错，拷贝赋值已经删除
  a3 = A(a2);  // 报错，拷贝构造已经删除
}
```

# ifndef & pragma

`#ifndef`的方式受C/C++语言标准支持。它不光可以保证同一个文件不会被包含多次，也能保证内容完全相同的两个文件（或者代码片段）不会被不小心同时包含。

`#pragma`
once一般由编译器提供保证：同一个文件不会被包含多次。注意这里所说的“同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。你无法对一个头文件中的一段代码作pragma once声明，而只能针对文件。

# tuple and tie

tie create a lvalue reference while tuple creates a data member with value and the assignment assigns the value to the data member reference.

```cpp
#include<iostream>
#include<tuple>

using namespace std;

int main(void)
{
    int i; double d; string s;
    tuple<int, double, string> t3 = {1, 2.0, "3"};
    tie(i,d,s) = t3;
    cout << i << " " << d << " " << s << endl;
    // tie(i,d,s) = {1,2.0,"s"}; // initialization is not legit for tie
    
    return 0;
}
```

# char[] and std::string

char[] can be allocated on the stack when you initialize it with a specified size or allocated on the heap using malloc() or new().

a string is a class that contains a char array with other information like the size of it. The string object definition is stored on the stack but its implementation to construct an object uses memory on the heap.

Comparing between them, string is faster than heap-allocated char arrays for short texts and protect you from buffer overruns. However, C++ string occupy more memory space and is not very suitable for usage across DLL boundaries.

When main() want to use a dynamic library, it add .h file  into the code and compile into .o file. The implementation is realized by get the address of .so file and the offset address of referred variables or function. While only .so file change, e.g., add some debug sentences, the entrance address of variables and functions will  be bias from the original ones. This would cause program error in runtime.
- [ ] #Ques why add some debug sentences, the entrance address of v and f will change? 🛫 2022-11-14 

[Difference between string and char[] types in C++](https://stackoverflow.com/questions/1287306/difference-between-string-and-char-types-in-c#comment1146663_1287357)

# explicit

if a class has a constructor which can be called with a single argument, then this constructor becomes a conversion constructor.

```cpp
#include <iostream>
using namespace std;
 
class Complex {
private:
    double real;
    double imag;
 
public:
   
    // Default constructor
    explicit Complex(double r = 0.0,
            double i = 0.0) : real(r),
                              imag(i)
    {
    }
 
    // A method to compare two
    // Complex numbers
    bool operator == (Complex rhs)
    {
        return (real == rhs.real &&
                imag == rhs.imag);
    }
};
 
// Driver Code
int main()
{
    // a Complex object
    Complex com1(3.0, 0.0);
 
	    if (com1 == 3.0)  //3.0 can not be implicitly converted into a Complex type
        cout << "Same";
    else
        cout << "Not Same";
    return 0;
}
```

Output

```cpp
Compiler Error : no match for 'operator==' in 'com1 == 3.0e+0'
```

# std::move

## Example 1

//? why std::move does not work for interger

```cpp
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
 
int main()
{
		int ix = 1;
    int iy = std::move(ix);   
    std::cout << ix << std::endl; // ix is still 1 

    std::string str = "Salut";
    std::vector<std::string> v;
 
    // uses the push_back(const T&) overload, which means 
    // we'll incur the cost of copying str
    v.push_back(str);
    std::cout << "After copy, str is " << std::quoted(str) << '\n';
 
    // uses the rvalue reference push_back(T&&) overload, 
    // which means no strings will be copied; instead, the contents
    // of str will be moved into the vector.  This is less
    // expensive, but also means str might now be empty.
    v.push_back(std::move(str));
    std::cout << "After move, str is " << std::quoted(str) << '\n';
 
    std::cout << "The contents of the vector are { " << std::quoted(v[0])
                                             << ", " << std::quoted(v[1]) << " }\n";
}
```

## Possible result

```bash
1   
After copy, str is "Salut"
After move, str is ""
The contents of the vector are { "Salut", "Salut" }
```

## Example 2

```cpp
#include <iostream>
using namespace std;

struct X
{
    std::string s_;

    X() {}
    X(std::string s) : s_(s) {}
    X(const X &other) : s_{other.s_} {}

    X(X &&other)
    noexcept : s_{std::move(other.s_)} {}
    // other is an lvalue, and other.s_ is an lvalue too
    // use std::move to force using the move constructor for s_
    // don't use other.s_ after std::move (other than to destruct)

    ~X() { cout << "dec" << endl; }
};

int main()
{
		X a("hello");
    cout << a.s_ << endl;
    X b = std::move(a);
    cout << a.s_ << endl; // a.s_ is null
    cout << b.s_ << endl;

    // a is an lvalue
    // use std::move to convert to a rvalue,
    // xvalue to be precise,
    // so that the move constructor for X is used
    // don't use a after std::move (other than to destruct)

}
```

## Result

```cpp
hello

hello
dec
dec
```

# std::forward

```cpp
std::map<std::string, std::function<void()>> commands;

template<typename ftor>
void install_command(std::string name, ftor && handler)
{
  commands.insert({
    std::move(name),
    std::forward<ftor>(handler)
  });
}
```

The std::map has an insert overload that accepts an templated rvalue referencefor the key/value pair to insert. For the key we can provide an rvalue using std::move because really we don’t need name any more. If we did not use std::move we would do a silly copy. For the value we provide whatever we the install_command was called with for the handler. We use std::forward to retrieve the original value category. If for the handler we provided an rvalue then insert will move from it. If for the handler we provided an lvalue then insert will copy it.

# std::vector

## reserve

It indicates that the vector is created such that it can store at least the number of the specified elements without having to reallocate memory.

```cpp
// CPP program to demonstrate use of
// std::vector::reserve
#include <chrono>
#include <iostream>
#include <vector>
 
using std::vector;
using std::cout;
using namespace std::chrono;
 
int main()
{
    // No of characters
    int N = (int)1e6;
 
    vector<int> v1, v2;
 
    // Reserve space in v2
    v2.reserve(N);
 
    // Start filling up elements in v1
    // To measure execution time in C++, refer below
    // https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
 
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i)
        v1.push_back(i);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Method I took " << duration.count() << " microseconds\n";
 
    // Start filling up elements in v2
    start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i)
        v2.push_back(i);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
 
    cout << "Method II took " << duration.count()
         << " microseconds \n";
 
    return 0;
}
```

Output

```
Method I took 18699 microseconds
Method II took 16276 microseconds
```

## emplace_back

1. **push_back()** copies a string into a vector. First, a new string object will be implicitly created initialized with provided char*. Then push_back will be called which will copy this string into the vector using the move constructor because the original string is a temporary object. Then the temporary object will be destroyed.
2. **emplace_back()** constructs a string in-place, so no temporary string will be created but rather emplace_back() will be called directly with char* argument. It will then create a string to be stored in the vector initialized with this char*. So, in this case, we avoid constructing and destroying an unnecessary temporary string object.

can be used together with std::vector::reserve, e.g.

```cpp
std::vector<std::string> topics;
	// Requests that the vector capacity be at least enough to contain n elements
  topics.reserve(num_topics);
  for (int i = 0; i < num_topics; ++i) {
    topics.emplace_back(topic + "_" + std::to_string(i + 1));
  }
```

## set

```cpp
// C++ program to implement
// the above approach
#include<bits/stdc++.h>
using namespace std;
 
// Function to display elements
// of the set
void display(set<int> s)
{
  // Printing the elements of
  // the set
  for (auto itr : s)
  {
    cout << itr << " ";
  } 
}
// Driver code
int main()
{
  // Empty set container
  set<int> s;
 
  // Insert elements in random order
  s.insert(10);
  s.insert(20);
  s.insert(30);
  s.insert(40);
  s.insert(50);
	s.insert(50);  // this will be ignored
   
  // Invoking display() function
  display(s);
  return 0;
}
```

Output

```cpp
10 20 30 40 50 [1] + Done
```

## rvalue reference &&

```cpp
#include<bits/stdc++.h>
using namespace std;
 
// he && token can be used to mean an "rvalue reference".
// it signifies that the function accepts an Rvalue reference
// that is, a reference to an argument that is about to be destroyed.
void func(int&& a){
}

// Driver code
int main()
{
    int a = 1;
    int &b = a;           // pass, the address of "a" is store in "b"
    //int &b = 20;        // error, no address fo "20"
    const int &c = 20;    // pass, a temporary address for "20"
    // c = 50;            // illegal operation, c is a constant
    int &&d = 20;         // pass, rvalue reference
    d = 50;
    return 0;
}
```

# using

## alias template

```cpp
template<class T> 
using Vec = vector<T, Alloc<T>>;
Vec<int> v; // same as vector<int, Alloc<int>> v;
```

## alias function

```cpp
using func = void (*) (int, int);
// the name 'func' now denotes a pointer to function:
void example(int, int) {}
func f = example;
```

# inheritance

- A derived class doesn’t inherit ***access*** to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.
- When a base class is privately inherited by the derived class, public members of the base class becomes the private members of the derived class and therefore, the public members of the base class can only be accessed by the member functions of the derived class. They are inaccessible to the objects of the derived class.
- 局路径规划插件实现时要继On the other hand, when the base class is publicly inherited by the derived class, public members of the base class also become the public members of the derived class. Therefore, the public members of the base class are accessible by the objects of the derived class as well as by the member functions of the derived class.
  
  Inheritance key word
```c++
class Base {
  public:
    int x;
  protected:
    int y;
  private:
    int z;
};

class PublicDerived: public Base {
  // x is public
  // y is protected
  // z is not accessible from PublicDerived
};

class ProtectedDerived: protected Base {
  // x is protected
  // y is protected
  // z is not accessible from ProtectedDerived
};

class PrivateDerived: private Base {
  // x is private
  // y is private
  // z is not accessible from PrivateDerived
};
```
# virtual function

[Virtual Function in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/virtual-function-cpp/)

```cpp
// CPP program to illustrate
// working of Virtual Functions
#include<iostream>
using namespace std;

class base {
public:
	void fun_1() { cout << "base-1\n"; }
	virtual void fun_2() { cout << "base-2\n"; }
	virtual void fun_3() { cout << "base-3\n"; }
	virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base {
public:
	void fun_1() { cout << "derived-1\n"; }
	void fun_2() { cout << "derived-2\n"; }
	void fun_4(int x) { cout << "derived-4\n"; }
};

int main()
{
	base *p;
	derived obj1;
	p = &obj1;

	// Early binding because fun1() is non-virtual according to the type of pointer
	// in base
	p->fun_1();

	// Late binding (RTP)
	p->fun_2();

	// Late binding (RTP)
	p->fun_3();

	// Late binding (RTP)
	p->fun_4();

	// Early binding but this function call is
	// illegal (produces error) because pointer
	// is of base type and function is of
	// derived class
	// p->fun_4(5);
	
	return 0;
}
```

```
Output:
	base-1
	derived-2
	base-3
	base-4
```

![Untitled](c++%20basic%2066c6e1e8cfbf457c81a0f61cf5aa5855/Untitled.png)

Early binding (Runtime, non-virtual function) is done in accordance with the content of pointer (i.e. location pointed to by pointer) and Late binding (Compile time, virtual function) is done according to the type of pointer.

# auto &

• `auto &` guarantees that you are sharing the variable with something else. It is always a reference and never to a temporary.

• `auto const &` is like `auto &&`, but provides read-only access.

Use `auto &&`when you don't care if the object is local or not. Technically, this will always produce a reference, but if the initializer is a temporary (e.g., the function returns by value), it will behave essentially like your own local object.

# Reference_type Function Returns

Functions can be declared to return a reference type. There are two reasons to make such a declaration:

- The information being returned is a large enough object that returning a reference is more efficient than returning a copy.
- The type of the function must be an l-value.
- The referred-to object will not go out of scope when the function returns.

```cpp
class Point
{
public:
// Define "accessor" functions as
//  reference types.
unsigned& x();
unsigned& y();
private:
// Note that these are declared at class scope:
unsigned obj_x;
unsigned obj_y;
};

unsigned& Point :: x()
{
return obj_x;
}
unsigned& Point :: y()
{
return obj_y;
}
```

Warning:

If you declare an object at local scope, that object will be destroyed when the function returns. If the function returns a reference to that object, that reference will probably cause an access violation at runtime if the caller attempts to use the null reference.

```cpp
// C4172 means Don’t do this!!!
Foo& GetFoo()
{
    Foo f;
    ...
    return f;
} // f is destroyed here
```

# variadic temlates

[qicosmos](https://www.cnblogs.com/qicosmos/p/4325949.html)

```cpp
template <class... T>
void f(T... args)
{    
    cout << sizeof...(args) << endl; //打印变参的个数
}

f();        //0
f(1, 2);    //2
f(1, 2.5, "");    //3
```

上面的例子中，f()没有传入参数，所以参数包为空，输出的size为0，后面两次调用分别传入两个和三个参数，故输出的size分别为2和3。由于可变模版参数的类型和个数是不固定的，所以我们可以传任意类型和个数的参数给函数f。这个例子只是简单的将可变模版参数的个数打印出来，如果我们需要将参数包中的每个参数打印出来的话就需要通过一些方法了。展开可变模版参数函数的方法一般有两种：一种是通过递归函数来展开参数包，另外一种是通过逗号表达式来展开参数包。下面来看看如何用这两种方法来展开参数包。

# const

## const pointer and const variable

[Const keyword in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/const-keyword-in-cpp/)

```cpp
"the pointer variable point to a const value"
const int* i = &x;

"const pointer(i) pointing to the var x's location"
int* const i = &x;

"const pointer(i) pointing to a const value (the locatioin of the var x)"
int x{ 9 };
const int* const i = &x;the var x's location

"float x is read only" 
int RoundToInt(const float x){
	~~x = 6;~~  // illegal operation
	return x;
}
int x = 5; int y = RoundToInt(5); 
```

## const data member in class

A `const` variable has to be declared within the class, but it cannot be defined in it. We need to define the const variable outside the class.

```cpp
#include <iostream>
#include <vector>
#include <map>

class pose{
    public:
    pose(int _a, double _b, char _c)
        :a(_a), b(_b), c(_c){}
    
    const int a;
    // const int a = 2; // same as "const int a"
    const double b;
    char c;
};

int main(){
    pose test(1, 2.0,'c');
    std::cout << test.a << std::endl;
    //test.a = 4;  // assignment of read-only variable
    return 0;
}
```

## Const object as data member in other object

```cpp
#include <iostream>
#include <vector>
#include <map>

class orientation{
public:
    orientation(int x_): x(x_){}
    int get_x() const { return x; } 
    int get_y() { return y; }
    int y;
private:
    const int x;
};

class pose{
public:
    pose(int _a, int x)
    : a(_a), orient_(x) {}

    const orientation& func() const{
        return orient_;  
    }

private:
    int a;
    const orientation orient_;
};

class position{
public:
    int w;
    position(int w_): w(w_){}
    int get_w() const { return w; }
};

int main(){
    const int x = 1;
    orientation o(1);
    std::cout << o.get_x() << std::endl;

    pose p(3, 2);
    orientation t = p.func();
    std::cout << p.func().y << std::endl;
    std::cout << t.get_y() << std::endl;
    
    // binding reference of type ‘orientation&’ to ‘const orientation’ discards qualifiers
    // std::cout << p.func().get_y() << std::endl; 
    std::cout << p.func().y << std::endl; 
    // const object can only access const member functions
    std::cout << p.func().get_x() << std::endl;

    return 0;
}
```

OUTPUT

```cpp
1
-10624
-10624
-10624
2
```

# Lambda function

This illustration shows the parts of a lambda:

![https://learn.microsoft.com/en-us/cpp/cpp/media/lambdaexpsyntax.png?view=msvc-170](https://learn.microsoft.com/en-us/cpp/cpp/media/lambdaexpsyntax.png?view=msvc-170)

1. *capture clause* (Also known as the *lambda-introducer* in the C++ specification.)
2. *parameter list* Optional. (Also known as the *lambda declarator*)
3. *mutable specification* Optional.
4. *exception-specification* Optional.
5. *trailing-return-type* Optional.
6. *lambda body*.

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>

class pose{
public:
    int a;
    pose(int a_):a(a_){}

    int plus(int x){
        return x + a; 
    }
    int func(int b){
        int a = 
        [this](){
           return plus(5);
        }();;
        return a;
    }
};

int main()
{
    pose P(1);
    std::cout << P.func(2) << std::endl;
    return 0;
}
```

## capture clause

By default, variables are captured by const value.This means when the lambda is created, the lambda captures a constant copy of the outer scope variable, which means that the lambda is not allowed to modify them.

```cpp
#include <iostream>

int main()
{
  int ammo{ 10 };

  // Define a lambda and store it in a variable called "shoot".
  auto shoot{
    [ammo]() { // Illegal, ammo was captured as a const copy.
			  
      --ammo;
		
      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };

  // Call the lambda
  shoot();

  std::cout << ammo << " shot(s) left\n";

  return 0;
}
```

```cpp
// mutable copy
[ammo]() mutable {} // mutable copy
	      
// &ammo means ammo is captured by reference
[&ammo]() {}
 
// Capture health and armor by value, and enemies by reference.
[health, armor, &enemies](){};

// Capture enemies by reference and everything else by value.
[=, &enemies](){};

// Capture armor by value and everything else by reference.
[&, armor](){};

// Illegal, we already said we want to capture everything by reference.
[&, &armor](){};

// Illegal, we already said we want to capture everything by value.
[=, armor](){};

// Illegal, armor appears twice.
[armor, &health, &armor](){};

// Illegal, the default capture has to be the first element in the capture group.
[armor, &](){};
```