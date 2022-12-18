#include "global.h"
#include "peer.h"
#include "dtls_debug.h"

#ifndef WITH_CONTIKI
void peer_init(void)
{
}

static inline dtls_peer_t *
dtls_malloc_peer(void) {
  return (dtls_peer_t *)malloc(sizeof(dtls_peer_t));
}

void
dtls_free_peer(dtls_peer_t *peer) {
  dtls_handshake_free(peer->handshake_params);
  dtls_security_free(peer->security_params[0]);
  dtls_security_free(peer->security_params[1]);
  free(peer);
}
#else /* WITH_CONTIKI */

#include "memb.h"
MEMB(peer_storage, dtls_peer_t, DTLS_PEER_MAX);

void
peer_init(void) {
  memb_init(&peer_storage);
}

static inline dtls_peer_t *
dtls_malloc_peer(void) {
  return memb_alloc(&peer_storage);
}

void
dtls_free_peer(dtls_peer_t *peer) {
  dtls_handshake_free(peer->handshake_params);
  dtls_security_free(peer->security_params[0]);
  dtls_security_free(peer->security_params[1]);
  memb_free(&peer_storage, peer);
}
#endif /* WITH_CONTIKI */

dtls_peer_t *
dtls_new_peer(const session_t *session) {
  dtls_peer_t *peer;

  peer = dtls_malloc_peer();
  if (peer) {
    memset(peer, 0, sizeof(dtls_peer_t));
    memcpy(&peer->session, session, sizeof(session_t));
    peer->security_params[0] = dtls_security_new();

    if (!peer->security_params[0]) {
      dtls_free_peer(peer);
      return NULL;
    }

    dtls_dsrv_log_addr(DTLS_LOG_DEBUG, "dtls_new_peer", session);
  }

  return peer;
}