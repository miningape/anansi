#ifndef LIST
#define LIST

#include <stdlib.h>
#include "structs.c"

typedef struct {
    token* array;
    int length;
    int size;
} tokenList;

void initTokenList( tokenList* t ) {
    t->array = malloc(11 * sizeof(token));
    t->length = 0;
    t->size = 11;
}

void addToken( tokenList* tlist, token t ) {
    if ( tlist->size == tlist->length ) {
        tlist->size *= 2;
        tlist->array = realloc(tlist->array, tlist->size * sizeof(token));
    }
    tlist->array[tlist->length++] = t;
}

void deleteTokenList( tokenList* t ) {
    free( t->array );
    t->array = NULL;
    t->size = t->length = 0;
}

#endif