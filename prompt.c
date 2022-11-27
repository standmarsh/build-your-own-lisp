#include <stdio.h>
#include <stdlib.h>


#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline functions */
char* readline(char* prompt) {
    fputs(prompt,  stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

// Otherwise include the editline headers
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {

    while(1) {
        char* input = readline("lispy> ");
        add_history(input);
        printf("No you're a %s\n", input);
        free(input);
    }

    return 0;
}
