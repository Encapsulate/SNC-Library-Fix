#include <sys/syscall.h>
#include <sys/process.h>
#include <sys/integertypes.h>

void *memcpy(void *destination, const void *source, size_t num) {
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, num, (uint64_t)source);
	return_to_user_prog(void*);
}
void *memset(void *ptr, int value, size_t num) {
	char *p = (char*)ptr;
	while (num--)
		*p = value;
	return ptr;
}

size_t strlen(const char *s) {
	const char *p = s;
	while (*s) ++s;
	return s - p;
}
int strcmp(const char* s1, const char* s2) {
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
char *strcat(char *destination, const char *source) {
	char *ret = destination;
	while (*destination)
		destination++;
	while (*destination++ = *source++);
	return ret;
}

char *chcat(char *destination, char source) {
	if (*destination)
		while (+(++destination));
	return &(*(destination++) = source);
}