#include <stdio.h>
# include <string.h>

// Create person struct
struct Person {
    // ● Give the object class attributes (aka instance variables)
    char name[50];
    char birthdate[50];

};

// constructor
struct Person* new_person(struct Person* p, char name[], char birthdate[]) {
    strcpy(p->name, name);
    strcpy(p->birthdate, birthdate);
    return p;
}

// ● Give the object functions
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

    return current_year - birth_year;
}

void display_person(struct Person* p) {
    int age = calculate_age(p, p->birthdate);
    printf("Name is: %s\n", p->name);
    printf("Date of birth is: %s\n", p->birthdate);
    printf("Age is: %d\n", age);
}

// ● Create an object that inherits from the first object (e.g., Student) with some attributes
// and functions of its own

struct Student {
    // set up inheritance capability
    struct Person p;
    char school[50];
    char major[50];

};

// constructor
struct Student* new_student(struct Student* s, char school[], char major[]) {
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
    new_person(&p1, "Bob", "12/24/1994");
    
    // print attribute values
    display_person(&p1);

    // update and print new name
    set_name(&p1, "Taylor");
    char* new_name = get_name(&p1);
    printf("New name is: %s\n", new_name);

    // instantiate student object
    struct Student s1;
    new_student(&s1, "UT Austin", "Computer Science");

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

// Sources

// https://www.youtube.com/watch?v=J5CGGyNL9MU
// https://www.codementor.io/@arpitbhayani/powering-inheritance-in-c-using-structure-composition-176sygr724