#ifndef _DTLS_STATE_H_
#define _DTLS_STATE_H_

#include <sys/types.h>
#include <stdint.h>

#include "global.h"
#include "hmac.h"

typedef enum { 
  DTLS_STATE_INIT = 0, DTLS_STATE_WAIT_CLIENTHELLO, DTLS_STATE_WAIT_CLIENTCERTIFICATE,
  DTLS_STATE_WAIT_CLIENTKEYEXCHANGE, DTLS_STATE_WAIT_CERTIFICATEVERIFY,
  DTLS_STATE_WAIT_CHANGECIPHERSPEC,
  DTLS_STATE_WAIT_FINISHED, DTLS_STATE_FINISHED, 
  /* client states */
  DTLS_STATE_CLIENTHELLO, DTLS_STATE_WAIT_SERVERCERTIFICATE, DTLS_STATE_WAIT_SERVERKEYEXCHANGE,
  DTLS_STATE_WAIT_SERVERHELLODONE,

  DTLS_STATE_CONNECTED,
  DTLS_STATE_CLOSING,
  DTLS_STATE_CLOSED
} dtls_state_t;

typedef struct {
  uint16_t mseq_s;	     /**< send handshake message sequence number counter */
  uint16_t mseq_r;	     /**< received handshake message sequence number counter */

  /** pending config that is updated during handshake */
  /* FIXME: dtls_security_parameters_t pending_config; */

  /* temporary storage for the final handshake hash */
  dtls_hash_ctx hs_hash;
} dtls_hs_state_t;
#endif /* _DTLS_STATE_H_ */