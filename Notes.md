Chapter 18
==========

section 18.2 Operator Functions
------------

### 18.2.2 Predefined meaning
‘=’, ‘&’, ‘,’ have predefined meanings for class. But they can be deleted.

### 18.2.3 Operators and User Defined Type
An operator function must be a member function or at least take one argument as user defined type.
This ensures use can not change the meaning of an expression unless the expression contains user defined objects.
If we want to a operator take built-in type, it can not be an member function

### 18.2.4 Passing objects
For small object, we use pass by value. For large object, we pass by reference. If we do not intend to change it, we pass by const reference.
For return value, we normally do not return reference or pointer. But if we return a one of the arguments, we normally return reference.

Chapter 19 Special operators
==========

section 19.1 Introduction
-------------------------
The special operators are
[], (), ->, ++, --, new, delete

subscripting, function call, dereference

### section 19.2.1 subscripting

If you want to get a reference of a vector element.
use for (auto& x: vec) {...}
not for (auto x: vec) {...}

The subscripting operator has to be non-static member function.

### section 19.2.2 function call

Overloading the function call operator seems to be useful primarily for defining types
that have only a single operation and for types for which one operation is predominant. The call
operator is also known as the application operator.

1. operator() provides function call syntax for object.
2. These objects are called function objects.
3. allow us to write code that take nontrivial operations as parameters.
4. In many cases, function objects need to hold data to perform their operations.
