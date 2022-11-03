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

### Demo

- [examples](protocol%20buffer/examples.tar.xz) | [How to use it](protocol%20buffer.md#How%20to%20use%20it)

### Reference 

1. [Protobuf - Quick Guide](https://www.tutorialspoint.com/protobuf/protobuf_quick_guide.htm)
2. [Protocol Buffer Basics: C++ | Protocol Buffers | Google Developers](https://developers.google.com/protocol-buffers/docs/cpptutorial)

### Question

---

# What is serialization

Serialization is the process of converting an object (of any language) into bytes and storing them in persistent memory system.

# Why use google protobuf

- **anguage independent** − Multiple languages have protobuf library, few famous ones being Java, Python, Go, etc. So, a Java object can be serialized into bytes from a Java program and can be deserialized to a a Python object.
- **Efficient Data Compaction** − In microservice environment, given that multiple communications take place over a network, it is critical that the data that we are sending is as succinct as possible. We need to avoid any superfluous information to ensure that the data is quickly transferred. Google Protobuf has that as one of the focus areas.
- **Efficient serialization and deserialization** − In microservice environment, given that multiple communications take place over a network, it is critical how fast can we serialize and deserialize. Google Protobuf ensures that it is as quick as possible in serializing and deserializing the data.
- **Simple to use** − Protobuf library auto-generates serialization code (as we will see in the upcoming chapters), has a versioning scheme to ensure that the creator of data and the user of data can have separate versions of the serialization definition, etc.

# How to use it

Following link includes several compiling method.

[protobuf/README.md at main · protocolbuffers/protobuf](https://github.com/protocolbuffers/protobuf/blob/main/examples/README.md)

procedure:

*.proto* file→.h nad .cc file → execution

```makefile
...
syntax = "proto3";
package tutorial;  // In C++, your generated classes will be placed
							     // in a namespace matching the package name.
import "google/protobuf/timestamp.proto";
									// import messages from other .proto file
message Person {
  string name = 1;
  int32 id = 2;  // Unique ID number for this person.
  string email = 3;

  enum PhoneType {
    MOBILE = 0;
    HOME = 1;
    WORK = 2;
  }

  message PhoneNumber {
    string number = 1;
    PhoneType type = 2;
  }

  repeated PhoneNumber phones = 4;

  google.protobuf.Timestamp last_updated = 5;
}
// The " = 1", " = 2" markers on each element identify the unique "tag" that field uses in the binary encoding. Tag numbers 1-15 require one less byte to encode than higher numbers
// repeated: the field may be repeated any number of times (including zero). The order of the repeated values will be preserved in the protocol buffer. Think of repeated fields as dynamically sized arrays.
```

If using make

```bash
in "example" directory, run make cpp

./add_person_cpp addressbook.data
./list_people_cpp addressbook.data

## output
Person ID: 1
  Name: zhan shaodong
  E-mail address: 694115582@qq.com
  Updated: 2022-08-29T09:25:18Z
```