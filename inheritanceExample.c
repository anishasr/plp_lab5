#include <stdio.h>
# include <string.h>

// Create Person struct
struct Person {
    // Declare attributes of Person
    char name[50];
    char birthdate[50];
};

/* Note - I didn't know most of these concepts before this lab. 
I had to learn from many tutorials and so I'm including what I learned with the sources. */

// constructor
// We are returning the pointer to the new person struct rather than the person struct itself
struct Person* create_person(struct Person* p, char name[], char birthdate[]) {

    /** Source: https://www.youtube.com/watch?v=w5XM1N7hLgc and https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/
    The -> operator is used when assigning member variables of a struct when dealing with a pointer to the struct vs. the struct itself
    My understanding here is that for OOP, we want changes to a person 'object' (struct) to be the same  
    everywhere, because that object may be accessed or used anywhere in the program and there should be no ambiguity with its values. */

    strcpy(p->name, name);
    strcpy(p->birthdate, birthdate);
    return p;
}

// Give the object functions
/* Note - I don't fully understand why exactly char* must be the return type and not char or char[]. The most clear/straightforward explanations I could found
   were on this Stack Overflow post https://stackoverflow.com/questions/45335619/why-does-the-function-have-to-return-a-char-but-not-a-char-array 
   I kept getting errors when trying the other return types. From what I've read, the compiler does not allow functions to return arrays directly */
char* get_name(struct Person* p) {
    return p->name;
}

void set_name(struct Person* p, char name[]) {
    strcpy(p->name, name);
}

char* get_birthdate(struct Person* p) {
    return p->birthdate;
}

void set_birthdate(struct Person* p, char birthdate[]) {
    strcpy(p->birthdate, birthdate);
}

int calculate_age(struct Person* p, char birthdate[]) {
    int current_year = 2023;
    int birth_year; 

    // extract year from birthdate string
    sscanf(birthdate, "%*d/%*d/%d", &birth_year);

    /* Source - https://www.geeksforgeeks.org/all-forms-of-formatted-scanf-in-c/ and https://dev.to/fahimfba/skip-any-value-in-scanf-function-in-c-programming-language-38jn
    I had a hard time trying to extract the birth year until I found the two articles above.
    %*d with the asterick tells the compiler to skip any numbers up to the delimiter '/', the last value does not include the asterick 
    so that is saved to the variable &birth_year */
    

    return current_year - birth_year;
}

// Using -> operator because we are working with a pointer to the person struct, not the struct that was originally passed in
void display_person(struct Person* p) {
    int age = calculate_age(p, p->birthdate);
    printf("Name is: %s\n", p->name);
    printf("Date of birth is: %s\n", p->birthdate);
    printf("Age is: %d\n", age);
}

// Create an object that inherits from the first object (e.g., Student) with some attributes
// and functions of its own

struct Student {
    // set up inheritance capability 
    struct Person p;
    char school[50];
    char major[50];
};

// constructor
struct Student* create_student(struct Student* s, char school[], char major[]) {
    // set student struct member variables
    strcpy(s->school, school);
    strcpy(s->major, major);
    return s;
}

char* get_school(struct Student* s) {
    return s->school;
}

void set_school(struct Student* s, char school[]) {
    strcpy(s->school, school);
}

char*  get_major(struct Student* s) {
    return s->major;
}

void set_major(struct Student* s, char major[]) {
    strcpy(s->major, major);
}

// Note - I passed in the pointer s struct's p variable because I felt it was clearer. 
// Would it be possible and/or better to access the s struct's p variable from s itself? And have just one argument passed into this function?
void display_student(struct Student* s, struct Person* p) {
    int age = calculate_age(p, p->birthdate);

    printf("\nName is: %s\n", p->name);
    printf("College is: %s\n", s->school);
    printf("Major is: %s\n", s->major);
    printf("Date of birth is: %s\n", p->birthdate);
    printf("Age is: %d\n", age);
}

int main() {

    // Test how to instantiate both types of objects, call their functions, and modify their
    // variables.

    // instantiate person object
    struct Person p1;
    /* create_person() is expecting a reference, not the struct p1 itself
    I found a clear and simple explanation of using & on this Stack Overflow post: https://stackoverflow.com/questions/28778625/whats-the-difference-between-and-in-c
    
    We want to pass &p1 because this passes the memory address location of p1 that was just declared.
    Then, that memory address is stored in the pointer variable that is created in the create_person function */

    create_person(&p1, "Bob", "12/24/1994");

    // another way to create a person struct
    // struct Person p1 = {.name = "Anne", .birthdate = "04/03/1961"};
    
    // print attribute values
    display_person(&p1);

    // update and print new name
    set_name(&p1, "Taylor");
    char* new_name = get_name(&p1);

    printf("New name is: %s\n", new_name);


    // instantiate student object
    struct Student s1;
    create_student(&s1, "UT Austin", "Computer Science");

    // set student attributes
    char* s1_college = get_school(&s1);
    char* s1_major = get_major(&s1);

    // set student's name and birthdate via parent class attributes
    strcpy(s1.p.name, "John");
    strcpy(s1.p.birthdate, "04/03/1961");

    // print attribute values
    display_student(&s1, &s1.p);

    // print student's updated name
    set_name(&s1.p, "Thomas");
    printf("\nNew name is: %s\n", s1.p.name);

    // calculate and print student's age
    int age = calculate_age(&s1.p, s1.p.birthdate);
    printf("Age is: %d\n", age);
    
}

/*Sources
https://www.youtube.com/watch?v=gt9YPl6O9ZM
https://www.youtube.com/watch?v=J5CGGyNL9MU
https://www.codementor.io/@arpitbhayani/powering-inheritance-in-c-using-structure-composition-176sygr724
https://www.educative.io/answers/how-to-read-data-using-sscanf-in-c
https://www.geeksforgeeks.org/all-forms-of-formatted-scanf-in-c/ */