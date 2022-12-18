#include "test_helper.h"
#include "ecc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ecc_printNumber(const uint32_t *x, int numberLength){ //here the values are turned to MSB!
	int n;

	for(n = numberLength - 1; n >= 0; n--){
		printf("%08x", x[n]);
	}
	printf("\n");
}

void ecc_setRandom(uint32_t *secret){
	int i;

	for (i = 0; i < arrayLength; ++i)
	{
		secret[i] = rand();
	}
}
const uint32_t ecc_prime_m[8] = {0xffffffff, 0xffffffff, 0xffffffff, 0x00000000,
				 0x00000000, 0x00000000, 0x00000001, 0xffffffff};

							
/* This is added after an static byte addition if the answer has a carry in MSB*/
const uint32_t ecc_prime_r[8] = {0x00000001, 0x00000000, 0x00000000, 0xffffffff,
				 0xffffffff, 0xffffffff, 0xfffffffe, 0x00000000};

#ifdef CONTIKI
void
test_assert(const char *file, int lineno)
{
  printf("Assertion failed: file %s, line %d.\n", file, lineno);
  /*
   * loop for a while;
   * call _reset_vector__();
   */
}
#endif