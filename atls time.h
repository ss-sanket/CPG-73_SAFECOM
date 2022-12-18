#ifndef _DTLS_DTLS_TIME_H_
#define _DTLS_DTLS_TIME_H_

#include <stdint.h>
#include <sys/time.h>

#include "tinydtls.h"

/**
 * @defgroup clock Clock Handling
 * Default implementation of internal clock. You should redefine this if
 * you do not have time() and gettimeofday().
 * @{
 */

#ifdef WITH_CONTIKI
#include "clock.h"
#else /* WITH_CONTIKI */
#include <time.h>

#ifndef CLOCK_SECOND
# define CLOCK_SECOND 1000
#endif

typedef uint32_t clock_time_t;
#endif /* WITH_CONTIKI */

typedef clock_time_t dtls_tick_t;

#ifndef DTLS_TICKS_PER_SECOND
#define DTLS_TICKS_PER_SECOND CLOCK_SECOND
#endif /* DTLS_TICKS_PER_SECOND */

void dtls_clock_init(void);
void dtls_ticks(dtls_tick_t *t);

/** @} */

#endif /* _DTLS_DTLS_TIME_H_ */