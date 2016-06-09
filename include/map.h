#ifndef __MAP_H__
#define __MAP_H__

#include <sncstructures.h>
#include <cstdlib.h>
#include <cstring.h>
#include <stdio.h>

template<typename _key, typename _value>
class map {
	keyvalue_s *data;
	int count;
	int capacity;
public:
	map() {
		data = (keyvalue_s*)malloc(sizeof(_key) + sizeof(_value) * 5);
		count = 0;
		capacity = 5;
	}
	~map() {
		free(data);
		free(&count);
		free(&capacity);
	}

	keyvalue_s *getkv(_key key) {
		int sz = count;
		while (sz--)
			if (!memcmp((void*)data[sz].key, (void*)key, sizeof(key)))
				return &data[sz];
		return &data[count];
	}
	int haskey(_key key) {
		return ((*(_key*)getkv(key)) != *(_key*)0);//((*(_key*)getkv(key)->key) == (*(_key*)(*(keyvalue_s*)0).key));
	}

	_value &operator[](_key key) {
		if (haskey(key))
			return *(_value*)0;
		if (count == capacity) 
			data = (keyvalue_s*)realloc(data, sizeof(data) + (sizeof(_key) + sizeof(_value) * 5));		
		return *(_value*)&getkv(key)->value;
	}
};

#endif /* __MAP_H__ */