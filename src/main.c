#include "awesome_header.h"

#include <stdio.h>

int main() {
    printf("Ret = %d", openFunction(22));
    closedFunction();
    closedFunctionWithPublic();
}