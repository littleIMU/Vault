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
Up Level: (parent:: [c++ advance](c++%20advance.md))



### Reference

[Scope & Lifetime](https://redirect.cs.umbc.edu/~chang/cs202.f15/Lectures/modules/m05-scope/slides.php?print)

### Question

- [ ]  Is memory allocated to the declaration of a static function?

---

# Lifetime

- **Static:** A static variable is stored in the data segment of the "object file" of a program. Its lifetime is the entire duration of the program's execution.
- **Automatic:** An automatic variable has a lifetime that begins when program execution enters the function or statement block or compound and ends when execution leaves the block. Automatic variables are stored in a "function call stack".
- **Dynamic:** The lifetime of a dynamic object begins when memory is allocated for the object (e.g., by a call to  or using ) and ends when memory is deallocated (e.g., by a call to  or using ). Dynamic objects are stored in "the heap". Like malloc, new, free, delete.

**Memory is not allocated until that function is executed**. Memory created inside a function is an example of local scope memory.