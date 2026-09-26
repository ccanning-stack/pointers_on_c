#include <stdio.h>
#include <stdlib.h>

int del_substring(char *str, char const *substr) {

    const char *cp = substr;
    int len = 0;
    const char *ssp = substr;
    char *firstmatch = NULL;
    char *lastmatch = NULL;
    int found = 0;

    while (*ssp++ != '\0') {
        len++;
    }

    char lastsubchar = *(substr + (len - 1));

    for (char *sp = str; *sp != '\0'; sp++) {
        if (*sp == *substr) {
            firstmatch = sp;
            cp = substr;
            while (*++sp == *++cp) {
                if (*sp == lastsubchar) {
                    lastmatch = sp;
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }

    if (found) {
        char *c;

        for (c = lastmatch + 1; *c != '\0'; c++) {
            *firstmatch++ = *c;
        }
        *firstmatch = '\0';
    }

    return found;
}

int main(void) {

    char *substr = "CDE";
    char *literal = "ABCDEFG";
    char *string = malloc(8);
    char *src = literal;
    char *dst = string;

    while (*src != '\0') {
        *dst = *src;
        src++;
        dst++;
    }

    int i = del_substring(string, substr);

    printf("Function returned %d. Word is %s\n", i, string);

    free(string);
    return 0;
}
