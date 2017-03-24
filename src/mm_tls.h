#ifndef MM_TLS_H_
#define MM_TLS_H_

/*
 * machinarium.
 *
 * cooperative multitasking engine.
*/

typedef struct mm_tls_t mm_tls_t;

typedef enum {
	MM_TLS_DISABLE,
	MM_TLS_ALLOW,
	MM_TLS_PREFER,
	MM_TLS_REQUIRE,
	MM_TLS_VERIFY_CA,
	MM_TLS_VERIFY_FULL
} mm_tlsmode_t;

struct mm_tls_t {
	mm_tlsmode_t mode;
	char        *protocols;
	char        *ca_path;
	char        *ca_file;
	char        *ca;
	int          ca_size;
	char        *cert_file;
	char        *cert;
	int          cert_size;
	char        *key_file;
	char        *key;
	int          key_size;
};

#endif
