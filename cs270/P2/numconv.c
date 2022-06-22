/**
 *  @author  Jameson Walter
 */
#include <stdio.h>

const char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char baselower[] = "0123456789abcdefghijklmnopqrstuvwxyz";
/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
char int_to_char (int value, int radix) {
    if (radix < 2||radix>36) { return '?'; };
    if (value > radix-1) { return '?'; }
    return base[value];
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int char_to_int (char digit, int radix) {
    if (radix < 2||radix>36) { return -1; }
    int res = -1;
    for (int i = 35; i >= 0; i--) {
        if (base[i] == digit || baselower[i] == digit) {
            res = i;
        }
    }
    if (res >= radix)
        return -1;
    return res;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void div_rem (int numerator, int divisor, int* remainder, int* quotient) {
    *remainder = numerator%divisor;
    *quotient = (int)(numerator/divisor);
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int ascii_to_int (int valueOfPrefix, int radix) {
    char cur = getchar();
    if (cur == '\n'){
        return valueOfPrefix;
    }
    return ascii_to_int(radix*valueOfPrefix+char_to_int(radix,cur), radix);
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void int_to_ascii (int value, int radix) {
    if (value == 0||radix<2||radix>36i) {
    } else {
        printf("%c", int_to_char(value%radix,radix));
        int_to_ascii(value/radix, radix);
    }
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
double frac_to_double (int radix) {
  return -1.0;
}


