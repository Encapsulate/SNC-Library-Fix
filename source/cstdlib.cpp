#include <sys/memory.h>
#include <sys/integertypes.h>
#include "cstring.h"

void *malloc(uint32_t size) {
	if (size == 0)
		size = 1;
	sys_addr_t addr = (65536 + size);
	sys_memory_allocate(addr, SYS_MEMORY_PAGE_SIZE_64K, &addr);
	return (void*)addr;
}
void free(void *ptr) {
	sys_memory_free((sys_addr_t)ptr);
}
void *realloc(void *ptr, uint32_t size) {
	void *dest = malloc(size);
	memcpy(dest, ptr, size);
	free(ptr);
	return dest;
}