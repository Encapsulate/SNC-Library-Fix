#ifndef ___CSTRING_H__
#define ___CSTRING_H__

#include <sys/sys_types.h>
#include <stdarg.h>

void *memcpy(void *destination, const void *source, size_t num);
void *memset(void *ptr, int value, size_t num);
size_t strlen(const char *str);
int strcmp(const char* str1, const char* str2);
char *strcat(char *destination, const char *source);
char *chcat(char *destination, char source);

#endif /* ___CSTRING_H__ */