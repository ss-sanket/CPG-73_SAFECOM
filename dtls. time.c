#include "tinydtls.h"
#include "dtls_time.h"

#ifdef WITH_CONTIKI
clock_time_t dtls_clock_offset;

void
dtls_clock_init(void) {
  clock_init();
  dtls_clock_offset = clock_time();
}

void
dtls_ticks(dtls_tick_t *t) {
  *t = clock_time();
}

#else /* WITH_CONTIKI */

time_t dtls_clock_offset;

void
dtls_clock_init(void) {
#ifdef HAVE_TIME_H
  dtls_clock_offset = time(NULL);
#else
#  ifdef __GNUC__
  /* Issue a warning when using gcc. Other prepropressors do 
   *  not seem to have a similar feature. */ 
#   warning "cannot initialize clock"
#  endif
  dtls_clock_offset = 0;
#endif
}

void dtls_ticks(dtls_tick_t *t) {
#ifdef HAVE_SYS_TIME_H
  struct timeval tv;
  gettimeofday(&tv, NULL);
  *t = (tv.tv_sec - dtls_clock_offset) * DTLS_TICKS_PER_SECOND 
    + (tv.tv_usec * DTLS_TICKS_PER_SECOND / 1000000);
#else
#error "clock not implemented"
#endif
}

#endif /* WITH_CONTIKI */