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


Uploaded Files

### Reference

[C++ std::move and std::forward](https://bajamircea.github.io/coding/cpp/2016/04/07/move-forward.html)



# **References as function parameters (are lvalues)**

There are two types of reference declarations in C++.

- The pre-C++ 11 is called now `lvalue reference` (and uses one `&`)
- The new C++ 11 called `rvalue reference` (that looks like `&&`).

```cpp
struct X {};

// overloads
void fn(X &) { std::cout<< "X &\n"; }
void fn(const X &) { std::cout<< "const X &\n"; }
void fn(X &&) { std::cout<< "X &&\n"; }

int main()
{
  X a;
  fn(a);
  // lvalue selects fn(X &)
  // fallbacks on fn(const X &)

  const X b;
  fn(b);
  // const lvalue requires fn(const X &)

  fn(X());
  // rvalue selects fn(X &&)
  // and then on fn(const X &)
}
```

# **Template argument deduction and reference collapsing rules**

```cpp
template<typename T>
void foo(T &&); // forwarding reference here
// T is a template parameter for foo

template<typename T>
void bar(std::vector<T> &&); // but not here
// std::vector<T> is not a template parameter,
// only T is a template parameter for bar
```

The rules allow the function `foo` above to be called with either an `lvalue` or an `rvalue`:

- When called with an `lvalue` of type `X`, then `T` resolves to `X &`
- When called with and `rvalue` of type `X`, then `T` resolves to `X &&`

When applying these rules we end up with an argument being `X & &&`. So there are even more rules to collapse the outcome:

- `X & &` collapses to `X &`
- `X & &&` collapses to `X &`
- `X && &` collapses to `X &`
- `X && &&` collapses to `X &&`

Combining these two rules, we get

```cpp
template<typename T>
void fn(T &&) { std::cout<< "template\n"; }

int main()
{
  X a;
  fn(a);
  // argument expression is lvalue of type X
  // resolves to T being X &
  // X & && collapses to X &

  fn(X());
  // argument expression is rvalue of type X
  // resolves to T being X
  // X && stays X &&
}
```

# **static_cast<X &&>**

Once we have an expression of a value category, we can convert it to an expression of a different value category. If we have a `rvalue` we can assign it to a variable, or take a reference, hence becoming a `lvalue`. If we have a `lvalue` we can return it from a function, so we get a `rvalue`.

But one important rule is that: **one can covert from a `lvalue` to a `rvalue` (to an `xvalue` more precisely) by using static_cast<X &&> without creating temporaries**. And this is the last piece of the puzzle to understand `std::move` and `std::forward`.

# Possible implementations for std::move

```cpp
template<typename T> struct remove_reference { typedef T type; };
template<typename T> struct remove_reference<T&> { typedef T type; };
template<typename T> struct remove_reference<T&&> { typedef T type; };

template<typename T>
constexpr typename remove_reference<T>::type && move(T && arg) noexcept
{
  return static_cast<typename remove_reference<T>::type &&>(arg);
}
```

# Possible implementations for std::forward

```cpp
template<typename T> struct is_lvalue_reference { static constexpr bool value = false; };
template<typename T> struct is_lvalue_reference<T&> { static constexpr bool value = true; };

template<typename T>
constexpr T&& forward(typename remove_reference<T>::type & arg) noexcept
{
  return static_cast<T&&>(arg);
}

template<typename T>
constexpr T&& forward(typename remove_reference<T>::type && arg) noexcept
{
  static_assert(!is_lvalue_reference<T>::value, "invalid rvalue to lvalue conversion");
  return static_cast<T&&>(arg);
}
```