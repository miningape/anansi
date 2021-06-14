#ifndef STRUCTS
#define STRUCTS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    none,
    number,
    operand,
    end,
    error,
    transition
} datatype;

typedef struct {
    datatype type;
    char* value;
} token;

token createToken ( datatype type, char* value ) {
    token rtn;

    rtn.value = strdup( value );
    rtn.type = type;

    return rtn;
}

void printToken( token obj ) {
    char* type;

    switch ( obj.type ) {
        case number:
            type= strdup("number");
            break;
        case operand:
            type= strdup("operand");
            break;
        default:
            printf("Thats weird token of type: %i", obj.type);
            break;
    }

    printf("Token { type: %s, value: %s }\n", type, obj.value);
}

#endif
