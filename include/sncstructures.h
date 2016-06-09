#ifndef __SNCSTRUCTURES_H__
#define __SNCSTRUCTURES_H__

struct keyvalue_s {
	int *key;
	int *value;
};

template<typename _key, typename _value>
struct _keyvalue_s {
	_key key;
	_value value;
};

#endif /* __SNCSTRUCTURES_H__ */