# Programming Language Project - Lab 5

**1) Does your language support objects or something similar (e.g., structs)?**
<br><br>C does not include built-in Object Oriented Programming in the way Java does, for example. However, C supports structures (struct data type) that can accomplish some of the functionality and goals of OOP. 
<br><br>Within a structure, you can include multiple variables of different data types. A structure in C encapsulates all of the specified information and, in that way, emulates some aspects of objects. Functions, including getters and setters, can be defined and used on instances of a structure. 

#### Code Example
 ```c
struct Person {
    // person attributes
    char name[50];
    char birthdate[50];
};
```

**2) Does your language have standard methods for functions that serve a similar purpose across all objects? For example, toString() in Java and __str__ in Python allow information about the objects to be printed. Are there similar functions in your language?**
<br><br>No, C does not have built-in standard methods such as toString() and __str__. The user would have to define a function with a name of their choice that prints the values of the structure's attributes.

**3) How does inheritance work (if it does)? Does your language support multiple inheritance?**
<br>C does not provide built-in inheritance apabilities.Some inheritance capabilities can be achieved by declaring an instance of a parent structure in a child structure. An instance of the child structure can then set attributes of the parent structure and call functions that modify or utilize the parent structure's attributes. 

#### Code Example
 ```c
struct Student {
    // set up inheritance capability
    struct Person p;
    char school[50];
    char major[50];
};

// set student's name and birthdate via parent class attributes
strcpy(s1.p.name, "John");
strcpy(s1.p.birthdate, "04/03/1961");
```

**4) If there is inheritance, how does your language deal with overloading method names and resolving those calls?**
<br> C doesn't have built-in method overloading. The rules of the programming language would apply -  if multiple functions of the same name are defined, the compiler would give an error because duplicate function definitions aren't allowed.

**5) Is there anything else that’s important to know about objects and inheritance in your language?**
<br> 



## Sources
https://www.geeksforgeeks.org/c-loops/
<br>https://computer.howstuffworks.com/c13.htm/
<br>https://www.w3schools.com/c/c_structs.php
<br>https://www.youtube.com/watch?v=J5CGGyNL9MU