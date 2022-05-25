#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "fmt.h"

int fmt() {
    char* text =(char*) malloc(sizeof(char));
    char c =(char) fgetc(stdin);
    int i = 0;
    int linesCounter = 0;
    int wordCounter = 0;
    /*
     * Read characters from text until its end.
     */
    while(c > 0) {
        /*
         * Check the rules of Fmt.
         */
        while(c != ' ' && c != '\n' && c > 0 && (isalnum(c) || ispunct(c))) {
            text[i] = c;
            wordCounter++;
            i++;
            text = realloc(text, (i+1)*sizeof(char));
            c =(char) fgetc(stdin);
        }
        /*
         * if a word was read and the line has more than 72 characters, add a line break.
         */
        if(((i-1) - (linesCounter * 71) > 71) && (wordCounter < 71)) {
            int j;
            for(j = i-1; text[j] != ' '; j--);
            text[j] = '\n';
            linesCounter++;
            text[i] = c;
            i++;
            text = realloc(text, (i+1)*sizeof(char));
            wordCounter = 0;
            c =(char) fgetc(stdin);
        }
        /*
         * if a line break was read after the last word, check the rules to change it for a space.
         */
        else if(c == '\n') {
            c =(char) fgetc(stdin);
            if(c != ' ' && c != '\n') {
                text[i] = ' ';
            }
            else{
                text[i] = '\n';
            }
            i++;
            text = realloc(text, (i+1)*sizeof(char));
            wordCounter = 0;
        }
        /*
         * Otherwise, just continue reading.
         */
        else if(c == ' '){
            text[i] = c;
            i++;
            text = realloc(text, (i+1)*sizeof(char));
            wordCounter = 0;
            c =(char) fgetc(stdin);
        }
    }
    text[i] = '\0';
    fprintf(stdout,"%s\n", text);
    return 0;
}
