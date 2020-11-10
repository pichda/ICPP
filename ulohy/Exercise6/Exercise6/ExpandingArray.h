#pragma once
#ifndef EXPANDINGARRAY_H
#define EXPANDINGARRAY_H

#include <stdexcept>

// T = data type; S = size; C =  coefficient
template <class T, int S = 5, int C = 2>

class ExpandingArray {
private:
	T* _array;
	unsigned _arraySize;
	unsigned _numberOfEntities;

	bool isThereSpaceInArray();
	void resizeArray();

public:
	ExpandingArray();
	~ExpandingArray();
	void Add(const T& e);
	T& GetEAdress(int i);
	T GetE(int i) const;
	unsigned int GetElementCount() const;
};

#endif EXPANDINGARRAY_H

template<class T, int S, int C>
inline bool ExpandingArray<T, S, C>::isThereSpaceInArray()
{
	return _arraySize > _numberOfEntities;
}

template<class T, int S, int C>
inline void ExpandingArray<T, S, C>::resizeArray()
{
	int newArrSize = _arraySize * C;
	T* newArr = new T[newArrSize];

	// memcpy(newArr, _array, newArrSize);

	for (int i = 0; i < _arraySize; i++)
	{
		newArr[i] = _array[i];
	}

	delete[] _array;
	_array = newArr;
	_arraySize = newArrSize;
}

template<class T, int S, int C>
inline ExpandingArray<T, S, C>::ExpandingArray()
{
	_array = new T[S];
	_arraySize = S;
	_numberOfEntities = 0;
}

template<class T, int S, int C>
inline ExpandingArray<T, S, C>::~ExpandingArray()
{
	delete[] _array;
}

template<class T, int S, int C>
inline void ExpandingArray<T, S, C>::Add(const T& e)
{
	if (!isThereSpaceInArray()) {
		resizeArray();
	}
	_array[_numberOfEntities] = e;
	_numberOfEntities += 1;
}

template<class T, int S, int C>
inline T& ExpandingArray<T, S, C>::GetEAdress(int i)
{
	if (_numberOfEntities < i || i <= 0) {
		throw std::invalid_argument("There is no element in collection");
	}

	return _array[i - 1];
}

template<class T, int S, int C>
inline T ExpandingArray<T, S, C>::GetE(int i) const
{
	if (_numberOfEntities < i || i <= 0) {
		throw std::invalid_argument("There is no element in collection");
	}
	return _array[i - 1];
}

template<class T, int S, int C>
inline unsigned int ExpandingArray<T, S, C>::GetElementCount() const
{
	return _arraySize;
}
