#include <vector.h>
#include <stdio.h>
#include <sys/integertypes.h>

//[5/9/2016, Winter] Need to find a work around for this problem here.
template class vector<int8_t>;
template class vector<uint8_t>;
template class vector<int16_t>;
template class vector<uint16_t>;
template class vector<int32_t>;
template class vector<uint32_t>;
template class vector<int64_t>;
template class vector<uint64_t>;


template<class T>
void vector<T>::print(const char *str) {
	printf(str);
}