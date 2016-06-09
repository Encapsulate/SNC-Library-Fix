#ifndef ___VECTOR_H__
#define ___VECTOR_H__

#include <cstdlib.h>
#include <cstring.h>

template<class T>
class vector {
	T **_data;
	int _capacity;
	int _count;
public:
	vector() {
		_data = (T**)malloc(sizeof(T)*5);
		_capacity = 5;
		_count = 0;
	}
	~vector() {
		free(_data);
		free(&_capacity);
		free(&_count);
	}

	void push(T value) {
		memcpy(_data[_count++], (void*)value, sizeof(T));
	}
	void pop() {
		memset(_data[_count--], 0, sizeof(T));
	}
	int count() {
		return this->_count;
	}
	T &at(int index) {
		return *_data[index];
	}

	T &operator[](int index) {
		if (index > _capacity) {
			return *_data[0];
		}
		return this->at(index);
	}
};

#endif /* ___VECTOR_H__ */