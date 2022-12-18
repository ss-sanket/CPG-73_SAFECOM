#include "session.h"

#ifdef HAVE_ASSERT_H
#include <assert.h>
#else
#ifndef assert
#warning "assertions are disabled"
#  define assert(x)
#endif
#endif

#ifdef WITH_CONTIKI
#define _dtls_address_equals_impl(A,B)				\
  ((A)->size == (B)->size					\
   && (A)->port == (B)->port					\
   && uip_ipaddr_cmp(&((A)->addr),&((B)->addr))			\
   && (A)->ifindex == (B)->ifindex)

#else /* WITH_CONTIKI */

static inline int 
_dtls_address_equals_impl(const session_t *a,
			  const session_t *b) {
  if (a->ifindex != b->ifindex ||
      a->size != b->size || a->addr.sa.sa_family != b->addr.sa.sa_family)
    return 0;
  
  /* need to compare only relevant parts of sockaddr_in6 */
 switch (a->addr.sa.sa_family) {
 case AF_INET:
   return 
     a->addr.sin.sin_port == b->addr.sin.sin_port && 
     memcmp(&a->addr.sin.sin_addr, &b->addr.sin.sin_addr, 
	    sizeof(struct in_addr)) == 0;
 case AF_INET6:
   return a->addr.sin6.sin6_port == b->addr.sin6.sin6_port && 
     memcmp(&a->addr.sin6.sin6_addr, &b->addr.sin6.sin6_addr, 
	    sizeof(struct in6_addr)) == 0;
 default: /* fall through and signal error */
   ;
 }
 return 0;
}
#endif /* WITH_CONTIKI */

void
dtls_session_init(session_t *sess) {
  assert(sess);
  memset(sess, 0, sizeof(session_t));
  sess->size = sizeof(sess->addr);
}

int
dtls_session_equals(const session_t *a, const session_t *b) {
  assert(a); assert(b);
  return _dtls_address_equals_impl(a, b);
}