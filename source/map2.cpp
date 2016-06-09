#include <sncstructures.h>
#include <cstring.h>

void map2_push(void *key, void *value, int key_size, int value_size, keyvalue_s *_data, int *_count) {
	memcpy(_data[*_count++].key, key, key_size);
	memcpy(_data[*_count++].value, value, value_size);
}