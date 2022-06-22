#include "field.h"

/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. 
 * <p>
 * @author <b>Jameson Walter</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {
    int mask = 1<<position;
    int cur = value&mask;
    if (cur==mask) {
	return 1;
    }
    return 0;
}

/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
    return value|(1<<position);
}

/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    return value&(~(1<<position));
}

/** @todo Implement in field.c based on documentation contained in field.h */
int getField (int value, int hi, int lo, bool isSigned) {
    if (isSigned) {
	res
    }
    return res;
}
