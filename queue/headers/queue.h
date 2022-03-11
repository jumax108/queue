#pragma once

#include <Windows.h>

template<typename T>
class CQueue {

public:

	CQueue(unsigned int capacity, unsigned int maxCapacity = 0xFFFFFFFF);
	~CQueue();
	
	inline unsigned int size() {
		return _size;
	}
	inline unsigned int capacity() {
		return _capacity;
	}

	bool push(T in);
	bool pop();
	bool front(T* out);

private:

	T* _data;
	unsigned int _size;
	unsigned int _capacity;
	unsigned int _rear;
	unsigned int _front;
	unsigned int _maxCapacity;

	void resize(unsigned int capapcity);

	HANDLE _heap;
};

template<typename T>
CQueue<T>::CQueue(unsigned int capacity, unsigned int maxCapacity) {

	_heap = HeapCreate(0,0,0);
	_data = (T*)HeapAlloc(_heap, HEAP_ZERO_MEMORY, sizeof(T) * capacity);

	_capacity = capacity;
	_maxCapacity = maxCapacity;
	_size = 0;
	_rear = 0;
	_front = 0;

}

template<typename T>
CQueue<T>::~CQueue() {

	HeapFree(_heap, 0, _data);
	HeapDestroy(_heap);

}

template <typename T>
void CQueue<T>::resize(unsigned int capacity){

	T* oldData = _data;
	_data = (T*)HeapAlloc(_heap, 0, sizeof(T) * capacity);

	memcpy(_data, oldData, sizeof(T) * _capacity);
	
	_capacity = capacity;
	HeapFree(_heap, 0, oldData);

}

template<typename T>
bool CQueue<T>::push(T in) {

	if (_size == _capacity) {
		if(_capacity == _maxCapacity){
			return false;
		}
		
		unsigned __int64 nextCapacity = (unsigned __int64)_capacity * 2 + 1;
		if(nextCapacity >= (unsigned __int64)_maxCapacity){
			nextCapacity = (unsigned __int64)_maxCapacity;
		}
		resize(nextCapacity);
	}

	_data[_rear] = in;
	_rear = (_rear + 1) % _capacity;
	_size += 1;

	return true;

}

template<typename T>
bool CQueue<T>::pop() {

	if (_size == 0) {
		return false;
	}

	_front = (_front + 1) % _capacity;
	_size -= 1;

	return true;

}

template<typename T>
bool CQueue<T>::front(T* out) {

	if (_size == 0) {
		return false;
	}

	*out = _data[_front];

	return true;

}