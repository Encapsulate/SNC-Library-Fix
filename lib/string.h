#ifndef __STRING_H__
#define __STRING_H__

#pragma once
#include "includes.h"

	namespace std {
	class string {
		char *_buffer;
		size_t _size;

	public:
		string() : _buffer((char*)malloc(1)), _size(0) {}	//default constructor 
		~string() { free(_buffer); _size = 0; }

		void initialize(size_t s = 1) {
			if (_buffer == NULL)
				_buffer = (char*)malloc(s);
			if (_size == NULL)
				_size = s;
		}

		void set_buffer(char *v) {
			if (_buffer == NULL)
				initialize();
			_size = strlen(v);
			free(_buffer);
			_buffer = (char*)malloc(_size);
			_buffer = v;
		}
		char *cstr() {
			return _buffer;
		}
		size_t size() {
			return _size;
		}

		string operator =(char *v) {
			set_buffer(v);
			return *this;
		}
		string operator =(char v) {
			set_buffer((char*)v);
			return *this;
		}
		bool operator ==(_string v) {
			if (_buffer == NULL)
				initialize(v.size());
			if (_size <= 0)
				return false;
			return !strcmp(v.cstr(), _buffer);
		}
		string operator += (char *v) {
			if (_buffer == NULL)
				initialize(strlen(v));

			char* buffer = _buffer;
			strcat(buffer, v);
			set_buffer(buffer);
			free(buffer);
			return *this;
		}
		/*_string operator += (char v) {
			if (_buffer == NULL)
				initialize();

			char* buffer = _buffer;
			strcat(buffer, (char*)v);
			set_buffer(buffer);
			return *this;
		}*/
		string operator += (_string v) {
			if (_buffer == NULL)
				initialize(v.size());

			char* buffer = _buffer;
			strcat(buffer, v.cstr());
			set_buffer(buffer);
			free(buffer);
			return *this;
		}

		/*_string operator +(char *s) {
			this->operator+=(s);
			return *this;
		}*/
		/*_string operator +(_string s) {
			this->operator+=(s);
			return *this;
		}*/
		_tring operator[](int _where) {
			return *this;// _buffer[_where];
		}


		//conversions
		//_string(char c) {
		//	this->operator+=(c);
		//}
		string(char c[]) {
			//printf("%s\n", c);
			this->set_buffer(c);
		}
	};
}
#endif /* __STRING_H__ */