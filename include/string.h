#ifndef ___STRING_H__
#define ___STRING_H__

#include <cstring.h>

class string {
	char *_data;
	//int _size;
public:
	string(char *str) {
		this->_data = str;
		//this->_size = strlen(str);
	}
	string() {
	
	}
	size_t size() {
		return strlen(this->_data);//this->_size;
	}
	char *c_str() {
		return _data;
	}
	void clear() {
		_data = "";
		//_size = 0;
	}

	int operator==(char *s) {
		return !strcmp(s, _data);
	}
	int operator==(string s) {
		return !strcmp(s.c_str(), _data);
	}
	char &operator[](int index) {
		return _data[index];
	}
	string &operator =(char *str) {
		this->_data = str;
		//this->_size = strlen(str);
		return *this;
	}

	char &operator*() {
		return *_data;
	}
	char &operator++() {
		return *_data++;
	}
	char operator+=(char c) {
		chcat(this->_data, c);
		//this->_size++;
		return c;
	}
};

#endif /* ___STRING_H__ */