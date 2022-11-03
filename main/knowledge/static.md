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

[](https://www.geeksforgeeks.org/static-keyword-cpp/?ref=gcse)

---
# Static variables in a function

## Static variables in a class

As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables **in a class are shared by the objects.**
A static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator outside the class as shown below:

```bash
// C++ program to demonstrate static
// variables inside a class

#include<iostream>
using namespace std;

class GfG
{
public:
	static int i;
	
	GfG()
	{
		// Do nothing
	};
};

int GfG::i = 1;

int main()
{
	GfG obj1;
  	GfG obj2;
  	obj2.i = 3;
	// prints value of i
	cout << obj1.i << " " << obj2.i;
}
```

# Static object

# Static functions in a class

```cpp
// CPP Program to demonstrate the implementation in Map
// divyansh mishra --> divyanshmishra101010
#include <iostream>
#include <vector>
  
class test{
public:
    int a;
    int b;
    test(int _a, int _b):a(_a),b(_b){
        
    }
    ~test(){
        std::cout << "1" << std::endl;
    }
    static void printMsg()
    {
        std::cout<<"Welcome to GfG!"<< std::endl;
    }
};

int main()
{
    for(int i = 0; i < 1; i++){
        test x(1,2);

    }
    test::printMsg();
    std::cout << "The End" << std::endl;
    return 0;
}
```

Output:

```cpp
1
1
Welcome to GfG!
The End
```