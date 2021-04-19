#include "awesome_header.h"

#include <stdio.h>

static int innerState;

#ifndef UNIT
static void privateFunction();
#endif


int openFunction(int param) {
    printf("openFunction\n");
    innerState = param;
    return 0;
}


void closedFunction() {
    printf("closedFunction\n");
    innerState = 42;
    privateFunction();
}

void closedFunctionWithPublic() {
    printf("closedFunctionWithPublic\n");
    innerState = 24;
    publicFunction();
}

#ifndef UNIT
void privateFunction() {
    printf("Private function was called\n");
}


void publicFunction() {
    printf("Public function was called\n");
}
#endif