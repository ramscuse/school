#include "Debug.h"
#include "iFloat.h"

/** @file iFloat.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in iFloat.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

/* declaration for useful function contained in testFloat.c */
const char* getBinary (iFloat_t value);

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetSign (iFloat_t x) {
  return (x&0x8000)>>15; /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetExp (iFloat_t x) {
  return (x&0x7F80)>>7; /* implement this */
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetVal (iFloat_t x) {
  int mant = ((x|0x0080)&0x00FF);
  if (floatGetSign(x))  {
    return ((~mant) + 1);
  }
  return mant;
}

/** @todo Implement based on documentation contained in iFloat.h */
void floatGetAll(iFloat_t x, iFloat_t* sign, iFloat_t* exp, iFloat_t* val) {
  *sign = floatGetSign(x);
  *exp = floatGetExp(x);
  *val = floatGetVal(x);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatLeftMost1 (iFloat_t bits) {
  for(int i = 15; i > 0; i--){
    int Val = (bits & (1 << i)) != 0;
    if(Val == 1){
      return i;
    }
  }
  return -1;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAbs (iFloat_t x) {
  return (x&0x7FFF);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatNegate (iFloat_t x) {
    if (x==0) {
        return 0;
    }
    if (floatGetSign(x)) {
        return x&0x7FFF;
    }
  return x|0x8000;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAdd (iFloat_t x, iFloat_t y) {
  if(x == 0 || y == 0){
    if(x == 0)
      return y;
    else if(y == 0)
      return x;
    else
      return 0;
  }
  debug("x = %s", getBinary(x));
  debug("y = %s", getBinary(y));
  //step 1
  debug("STEP 1");
  iFloat_t signX = -1, expX = -1, valX = -1;
  iFloat_t signY = -1, expY = -1, valY = -1;
  floatGetAll(x, &signX, &expX, &valX);
  floatGetAll(y, &signY, &expY, &valY);
  debug("X sign: %d exp: %d val: %s", signX,expX,getBinary(valX));
  debug("Y sign: %d exp: %d val: %s", signY,expY,getBinary(valY));

  //step 2
  debug("STEP 2");
  iFloat_t expR;
  if (expX > expY){
      debug("x = %s", getBinary(valX));
    iFloat_t Dif = expX - expY;
    expY = expY + Dif;
    valY = valY >> Dif;
      debug("x = %s", getBinary(valX));
  }else if (expY > expX){
    iFloat_t Dif = expY - expX;
    expX = expX + Dif;
    valX = valX >> Dif;
  }
  expR = expX;
  debug("%s: Value of X after equalizing exponents",getBinary(valX));
  debug("%s: Value of Y after equalizing exponents",getBinary(valY));
  //step 3
  debug("STEP 3");
  iFloat_t valR = valY + valX;
  debug("%s: Value of result after addition",getBinary(valR));
  //step 4
  debug("STEP 4");
  iFloat_t signR = floatGetSign(valR);
  iFloat_t magR = valR;
  if (signR) {
    magR = ~magR;
    magR = magR + 1;
  }
  debug("%s: Magnitude of result after converting from 2's complement to sign-magnitude", getBinary(magR));
  //step 5
  debug("STEP 5");
  int bit7 = floatLeftMost1(magR);
  while (bit7 != 7) {
    if (bit7 < 7) {
      magR = magR << 1;
      expR = expR - 1;
    }
    if (bit7 > 7) {
      magR = magR >> 1;
      expR = expR + 1;
    }
    bit7 = floatLeftMost1(magR);
  }
  debug("%s: Exponent of result after normalizing",getBinary(expR));
  debug("%s Magnitude of result after normalizing",getBinary(magR));
  //step 6
  debug("STEP 6");
  iFloat_t res = magR;
  res = res & 0x007F;
  res = res | (expR<<7);
  if (signR)
    res = res | 0x8000;
  debug("%s: Answer",getBinary(res));
  return res;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatSub (iFloat_t x, iFloat_t y) {
    return floatAdd(x,floatNegate(y));
}

