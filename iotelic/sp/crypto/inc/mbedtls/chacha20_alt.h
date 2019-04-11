
#ifndef CHACHA20_ALT_H
#define CHACHA20_ALT_H

int
iot_stream_ref(unsigned char *c, unsigned long long clen, const unsigned char *n, const unsigned char *k);

int
iot_stream_ietf_ref(unsigned char *c, unsigned long long clen, const unsigned char *n, const unsigned char *k);


int
iot_stream_ietf_ref_xor_ic(unsigned char *c,
                           const unsigned char *m,
                           unsigned long long mlen,
                           const unsigned char *n,
                           uint32_t ic,
                           const unsigned char *k);

int
iot_stream_ref_xor_ic(unsigned char *c,
                      const unsigned char *m,
                      unsigned long long mlen,
                      const unsigned char *n,
                      uint64_t ic,
                      const unsigned char *k);

#endif // CHACHA20_ALT_H
