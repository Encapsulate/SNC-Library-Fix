#ifndef __VECTOR_H__
#define __VECTOR_H__

#pragma once
#include "includes.h"

namespace std {
	template<class T>
	class vector {
		//private:
	//private:
		T **_data;
		int _count;
		int _capacity;
	public:
		vector() : _data((T**)malloc(1)), _count(0), _capacity(1) {}
		~vector() { free(_data); _count = 0;; _capacity = 0; }

		void initialize() {
			this->_data = (T**)malloc(/*sizeof(T) **/ 1);
			this->_count = 0;
			this->_capacity = 1;
		}
		void reallocate(size_t size) {
			if (this->_data == NULL || this->_count == NULL || this->_capacity == NULL)
				initialize();
			this->_data = (T**)realloc((void*)_data, sizeof(T) * size);
			this->_capacity = size;
		}

		T at(int index) {
			if (this->_data == NULL || this->_count == NULL || this->_capacity == NULL)
				initialize();
			return *(T*)&this->_data[index];
		}
		T push(T value) {
			if (this->_count >= this->_capacity || this->_capacity <= 0)
				reallocate(this->_capacity + 5);
			*(T*)&this->_data[this->_count++] = value;
			return at(this->_count - 1);
		}
		void pop() {
			if (this->_data == NULL || this->_count == NULL || this->_capacity == NULL)
				initialize();
			if (this->_count <= 0)
				return;
			free(this->_data[this->_count--]);
		}

		int count() {
			if (this->_data == NULL || this->_count == NULL || this->_capacity == NULL)
				initialize();
			return _count;
		}

		T operator[](int index) {
			return this->at(index);
		}
	};
}

#endif /* __VECTOR_H__ */