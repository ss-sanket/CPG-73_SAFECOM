#include <inttypes.h>

extern const uint32_t ecc_prime_m[8];
extern const uint32_t ecc_prime_r[8];

//debug function to print long numbers
void ecc_printNumber(const uint32_t *x, int numberLength);
void ecc_setRandom(uint32_t *secret);

#ifdef CONTIKI
#undef assert
#define assert(e) ((e) ? (void)0 : test_assert(__FILE__, __LINE__))
void test_assert(const char *, int);
#endif