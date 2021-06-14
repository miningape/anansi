#ifndef HELPER
#define HELPER

int isNumber( char test ) {
    switch ( test ) {
        case '0': case '1': case '2': case '3': 
        case '4': case '5': case '6': case '7':
        case '8': case '9':
            return 1;
            break;

        default:
            return 0;
            break;
    }
}

int isOperator( char test ) {
    switch ( test ) {
        case '+': case '-': case '*': case '/': case '=':
            return 1;
            break;

        default:
            return 0;
            break; 
    }
}

#endif