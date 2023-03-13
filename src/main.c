////////////////////////////////////////
// { prgmSEIVEC } { v1.5 }
// Author: izder456
// License: n/a
// Description: generate primes up to n
////////////////////////////////////////

/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Other available headers: stdarg.h, setjmp.h, assert.h, ctype.h, float.h, iso646.h, limits.h, errno.h */

/* uint8_t is an unsigned integer that can range from 0-255. */
/* It performs faster than just an int, so try to use it (or int8_t) when possible */

/* Put function prototypes here */
#define INPUT_SIZE 10

/* Put all your code here */
int main() {
  int i, j, n, c;
  char prompt[7] = "Till? ";
  char * ptr;
  char inputBuffer[INPUT_SIZE];
  char istr[12];

  os_ClrHomeFull();
  os_GetStringInput(prompt, inputBuffer, INPUT_SIZE);
  n = strtol(inputBuffer, & ptr, INPUT_SIZE);

  os_ClrHomeFull();
  os_PutStrFull("Prime numbers: ");
  os_NewLine();
  for (i = 2; i <= n; i++) {
    c = 0;
    for (j = 1; j <= i; j++) {
      if (i % j == 0) {
        c = c + 1;
      }
    }

    if (c == 2) {
      //printf("%d\n",i);
      sprintf(istr, "%d", i);
      os_PutStrFull(istr);
      os_NewLine();
    }
    if (os_GetCSC()) {
      os_PutStrFull("Interrupt detected");
      os_NewLine();
      break;
    }
  }

  os_PutStrFull("DONE!");
  while (!os_GetCSC());
  return 0;
}