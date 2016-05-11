#ifndef ___CSTDLIB_H__
#define ___CSTDLIB_H__

#include <sys/integertypes.h>

void *malloc(uint32_t size);
void free(void *ptr);
void *realloc(void *ptr, uint32_t size);

#endif /* ___CSTDLIB_H__ */