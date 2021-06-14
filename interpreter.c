#include <stdio.h>
#include <string.h>

#include "structs.c"
#include "list.c"
#include "helper.c"

char test[] = "69/=420+11";
tokenList tokens;
FILE *f;

void tokenizer () {
    //int length = strlen(test);
    int position = 0;
    char str[2];
    char curToken[64];
    curToken[0] = '\0';

    tokenList token_list;
    initTokenList( &token_list );

    datatype current_state = none;
    datatype last_state = none;


    while ( current_state != end ) {
        printf("%i\t%c:%s\t%i\n", position, test[position], curToken, current_state);
        if ( test[position] == '\0' ) {
            current_state = none;
            token t = createToken(last_state, curToken);
            addToken( &token_list, t );
            last_state = none;

            printf("End:%s\n", curToken);

            current_state = end;
        }
        
        // Check transitions
        switch ( current_state ) {
            case none:
                if ( isNumber(test[position]) ) {
                    current_state = number;  
                    break;
                }
                if ( isOperator(test[position]) ) {
                    current_state = operand;
                    break;
                }
                // we ignore it
                position++;
                break;
            
            case number:
                if ( last_state == number || last_state == none ) {
                    last_state = number;
                    current_state = none;
                    str[0] = test[position];
                    str[1] = '\0';
                    strcat(curToken, str);
                    position++;
                    //free(str);
                    break;
                }
                if ( last_state == operand ) {
                    current_state = transition;
                    break;
                }
                current_state = error;
                break;
            
            case operand:
                if ( last_state == operand || last_state == none ) {
                    last_state = operand;
                    str[0] = test[position];
                    str[1] = '\0';
                    current_state = none;
                    
                    strcat(strcpy(curToken, curToken), str);
                    position++;
                    //free( str );
                    break;
                }
                if ( last_state == number ) {
                    current_state = transition;
                    break;
                }
                current_state = error;
                break;
            
            case transition:
                printf("Transition:%s\n", curToken);
                current_state = none;
                
                token t = createToken(last_state, curToken);
                addToken( &token_list, t );
                last_state = none;
                curToken[0] = '\0';
                break;
            
            default:
                break;
            
        }

    }

    for ( int i = 0; i < token_list.length; i++) {
        printToken( token_list.array[i] );
    }

    deleteTokenList( &token_list );
}

int main() {
    token a;
    strcat(a.value, "10");
    a.type = number;
    
    initTokenList( &tokens );
    addToken( &tokens, a );
    a.type = operand;
    addToken( &tokens, a );

    printToken( tokens.array[1] );
    //f = fopen( "logger.txt", "a+")

    tokenizer();
    return 0;
}