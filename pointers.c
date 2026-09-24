#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Machine char range is %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Machine unsigned char range is %d to %d\n", 0, UCHAR_MAX);
    printf("Machine float range is %.2f to %.2f\n", FLT_MIN, FLT_MAX);
    printf("Machine ldouble range is %.2Lf to %.2Lf\n", LDBL_MIN, LDBL_MAX);

    char *string = "string";
    string = "string2";
    printf("String: %s", string);
}
