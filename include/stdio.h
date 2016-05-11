#ifndef ___STDIO_H__
#define ___STDIO_H__

#include <limits.h>
#include <stdarg.h>

int vsnprintf(char *str, size_t size, const char *format, va_list args);
void fmtstr(char *str, size_t *len, size_t size, const char *value, int width, int precision, int flags);
void fmtint(char *str, size_t *len, size_t size, long long int value, int base, int width, int precision, int flags);
void fmtflt(char *str, size_t *len, size_t size, double fvalue, int width, int precision, int flags, int *overflow);
void printsep(char *str, size_t *len, size_t size);
int getnumsep(int digits);
int getexponent(double value);
int convert(unsigned long long int value, char *buf, size_t size, int base, int caps);
unsigned long long int cast(double value);
unsigned long long myround(double value);
double mypow10(int exponent);
int vsprintf(char *buf, const char *fmt, va_list args);
int sprintf(char *buffer, const char *fmt, ...);
int snprintf(char *buffer, size_t len, const char *fmt, ...);
int printf(const char *fmt, ...);

#endif /* ___STDIO_H__ */