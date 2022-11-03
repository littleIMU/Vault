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
link_knowledge: "[Cmake](../knowledge/Cmake.md)"
---

### Questions

- [ ]  is cmake combined with vcpkg or conan by default?
- [x]  Are the two arguments arbitrary? YES, you can define whatever name you like.

### reference

[Integrating Google Test Into CMake Projects](https://matgomes.com/integrate-google-test-into-cmake/)

[https://github.com/matheusgomes28/cmake-google-tests](https://github.com/matheusgomes28/cmake-google-tests)

http://www.deanbodenham.com/learn/cpp-googletest-example3.html

- [gtest_exa.tar.xz](gtest/gtest_exa.tar.xz)

If your project is very simple, and you have no more third-party dependencies aside from GoogleTest, then the `FetchContent` way is perfectly acceptable. With this purely CMake method, you don’t need to install further tools to integrate GTest.

However, beware that `FetchContent` only works well for other CMake dependencies, and it’s a lot harder to integrate non-CMake packages with it. In addition, the pulled dependencies are essentially copied and pasted into your build! Meaning that you may encounter target name clashes or other interferences with CMake.

```cpp
TEST(TestSuiteName, TestName) {
  ... test body ...
}
```

The first argument is the name of the test suite, and the second argument is the test’s name within the test suite. Both of them are customized.

using CLI: /turn

```bash
g++ <file_names> -lgtest -lgtest_main -pthread
```

gmock

[几个GTest、GMock的例子_一只公羊的博客-CSDN博客](https://blog.csdn.net/qq_33177268/article/details/125966567)

[gMock for Dummies](https://google.github.io/googletest/gmock_for_dummies.html)

[gmock_test.cpp](gtest/gmock_test.cpp)

```bash
g++ gmock_test.cpp -lgtest -lgtest_main -lgmock -pthread
```

Output

```bash
wisheldon:gmock_exa/ $ ./a.out                                                  [14:06:51]
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from TestField
[ RUN      ] TestField.foo
Returned Value: Hello World!
Returned Value: 100
Returned Value: 200
Returned Value: 200
Returned Value: 200
gmock_test.cpp:32: Failure
Mock function called more times than expected - returning default value.
    Function call: getArbitraryString()
          Returns: ""
         Expected: to be called once
           Actual: called twice - over-saturated and active
Returned Value: Hello World!
[  FAILED  ] TestField.foo (0 ms)
[----------] 1 test from TestField (0 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (0 ms total)
[  PASSED  ] 0 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] TestField.foo

 1 FAILED TEST
```