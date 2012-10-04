#include <stdio.h>

// would be declared in the header file
typedef struct {
    void* publicFunction;
    void* publicVariable;
} testClassPublic;

// would be declared in the .c file
typedef struct {
    testClassPublic public;
    void* privateFunction;
    void* privateVariable;
} testClassPrivate;

// would be declared in the .c file
typedef union {
    testClassPublic public;
    testClassPrivate private;
}  testClass;

// f1 to be public
int f1() {
    return 0;
}

// f2 to be private
// also better to declare this in the .c file
// basically, declare all public stuff in the header
// and all private stuff in the .c file
int f2() {
    return 1;
}

int main() {
    // initalize the class
    testClass class;
    class.public.publicFunction = &f1;
    class.private.privateFunction = &f2;
    // now we can cast the union to a testClassPublic
    // and give it to somebody, who can now only see the
    // public parts while we can see all the parts
    return 0;
}
