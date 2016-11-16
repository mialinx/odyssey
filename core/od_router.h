#ifndef OD_ROUTER_H_
#define OD_ROUTER_H_

/*
 * odissey.
 *
 * PostgreSQL connection pooler and request router.
*/

typedef enum {
	OD_RS_UNDEF,
	OD_RS_OK,
	OD_RS_EROUTE,
	OD_RS_EPOOL,
	OD_RS_ESERVER_READ,
	OD_RS_ESERVER_WRITE,
	OD_RS_ECLIENT_READ,
	OD_RS_ECLIENT_WRITE
} odrouter_status_t;

void od_router(void*);

#endif