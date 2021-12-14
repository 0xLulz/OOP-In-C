#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Using this struct as a CCLASS
typedef struct Skrillec_CLASS {
    char *name;
    void* (*set_name)(skrillec, skrillec);
    void* (*run)(skrillec); // This will run PRINT_NAME()
} skrillec;

// THIS IS A FUNCTION CONSTUCTS TO THE 'set_name' field in the struct (class) ABOVE ONCE THE CONSTUCTOR IS CALLED
// this becomes s.set_name
void *makename(skrillec *s, skrillec *name) {
    s->name = name;
}

// THIS IS A FUNCTION CONSTUCTS TO THE 'run' field in the struct (class) ABOVE ONCE THE CONSTUCTOR IS CALLED
void *print_name(skrillec *s) {
    printf("Testing this: %s", s->name);
}

// Constructor to construct functions to fields in strcut (class)
skrillec construct(skrillec *s) {
    s->run = print_name;
    s->set_name = makename;
}

/*
    Act as 'main.c' below
*/
int main() {
    skrillec s;
    construct(&s);
    s.set_name(&s, "This shit works dude");
    s.run(&s);
    return 0;
}
