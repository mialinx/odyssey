#ifndef OD_LOG_H_
#define OD_LOG_H_

/*
 * odissey.
 *
 * PostgreSQL connection pooler and request router.
*/

typedef struct odlog_t odlog_t;

struct odlog_t {
	int pid;
	int fd;
};

int od_loginit(odlog_t*);
int od_logopen(odlog_t*, char*);
int od_logclose(odlog_t*);
int od_logv(odlog_t*, char*, char*, va_list);

static inline int
od_log(odlog_t *l, char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int rc = od_logv(l, NULL, fmt, args);
	va_end(args);
	return rc;
}

static inline int
od_debug(odlog_t *l, char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int rc = od_logv(l, "debug: ", fmt, args);
	va_end(args);
	return rc;
}

static inline int
od_error(odlog_t *l, char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int rc = od_logv(l, "error: ", fmt, args);
	va_end(args);
	return rc;
}

#endif