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

[Why "using namespace std" is considered bad practice - GeeksforGeeks](https://www.geeksforgeeks.org/using-namespace-std-considered-bad-practice/)

“using namespace” in C++ may not be a good habit for programmer. It can cause name conflict easily.

Consider using:

```bash
// 1. Full name
// Use cout of std library
std::cout << "Something to display";
// Use cout of foo library
foo::cout < "Something to display";

// 2. typedef
typedef std::cout cout_std;
typedef foo::cout cout_foo;
cout_std << "Something to write";
cout_foo << "Something to write";

// 3. impost a single identifier
using std::cout;
```