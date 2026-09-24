#include <stdio.h>
#include <stdlib.h>

const char *find_char(char const *source, char const *chars) {

    const char *p = NULL;
    for (const char *sp = source; *sp != '\0'; sp++) {
        for (const char *cp = chars; *cp != '\0'; cp++) {
            if (*sp == *cp) {
                p = sp;
                return p;
            }
        }
    }

    return p;
}

int main(void) {

    char *string = "ABCDEFG";
    char *chars = "XRCQEF";

    printf("String starts at %p\n", string);

    const char *sp = find_char(string, chars);

    printf("Pointer found is: %p\n", sp);

    exit(0);
}
