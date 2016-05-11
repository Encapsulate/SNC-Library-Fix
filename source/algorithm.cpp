#include <algorithm.h>
#include <cstring.h>

void reverse(char *destination, char *source) {
	while (*(++source));
	while (*(--source))
		if (*source)
			chcat(destination, *source);
}