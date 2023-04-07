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

# Reference 

[Const member functions in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/const-member-functions-c/)

---

The idea of const functions is not to allow them to modify the object on which they are called.

```cpp
// Example: of Constant member function
 
#include<iostream>
using namespace std;
 
class Demo
{
    int x;
 
      public:
     
    void set_data(int a)
    {
        x=a;
    }
  
     int get_data() const           //constant member function
     {
         ++x;                 // Error while attempting to modify the data member
         return x;
     }
  
};
 
 
main()
{
    Demo d;
    d.set_data(10);
    cout<<endl<<d.get_data();
 
    return 0;

```

When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects.

```cpp
// Demonstration of constant object,
// show that constant object can only
// call const member function
#include<iostream>
using namespace std;
class Demo
{
	int value;
	public:
	Demo(int v = 0) {value = v;}
	void showMessage()
	{
		cout<<"Hello World We are Tushar, "
		"Ramswarup, Nilesh and Subhash Inside"
		" showMessage() Function"<<endl;
	}
	void display()const
	{
		cout<<"Hello world I'm Rancho "
		"Baba Inside display() Function"<<endl;
	}
};
int main()
{
//Constant object are initialised at the time of declaration using constructor
	const Demo d1;
	//d1.showMessage();Error occurred if uncomment.
	d1.display();
	return(0);
}
```

Diference from const argument
```c++
obj a;
void func(const &a){
	// the obj a can not be modified in this function
}
```