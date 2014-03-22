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
