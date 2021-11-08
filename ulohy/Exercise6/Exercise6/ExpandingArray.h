#pragma once
#ifndef EXPANDINGARRAY_H
#define EXPANDINGARRAY_H

#include <stdexcept>

// T = data type; S = size; C =  coefficient
template <class T, int S = 5, int C = 10>

class ExpandingArray {
private:
	T* _array;
	unsigned _arraySize;
	unsigned _numberOfEntities;

	bool isThereSpaceInArray();
	void resizeArray();

public:
	ExpandingArray();
	ExpandingArray(const T& fill);
	~ExpandingArray();
	void Add(const T& e);
	void Reallocate(int size, const T& fill);
	T& GetEAdress(int i);
	T GetE(int i) const;
	unsigned int GetElementCount() const;
	unsigned int GetArraySize() const;
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
inline ExpandingArray<T, S, C>::ExpandingArray(const T& fill)
{
	_array = new T[S];
	_arraySize = S;
	_numberOfEntities = _arraySize;

	std::fill_n(_array, _arraySize, fill);
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
inline void ExpandingArray<T, S, C>::Reallocate(int size, const T& fill)
{
	if (size <= 0) {
		throw std::invalid_argument("size can not be 0 or smaller");
	}
	else {
		int newArrSize = size;
		T* newArr = new T[newArrSize];

		// pokud nove pole ma vetsi velikost nez pocet prvku v poli,
		// tak vypln pole hodnotou fill. Jinak realokuj pole. 

		if (size > _numberOfEntities) {
			// nejdrive naplni stare prvky
			for (int i = 0; i < _numberOfEntities; i++)  
			{
				newArr[i] = _array[i];
			}
			
			// doplneni pole hodnotou fill od poctu starych prvku az do nove velikost pole
			for (int i = _numberOfEntities; i < size; i++) 
			{
				newArr[i] = fill;
			}
		}
		else {
			for (int i = 0; i < size; i++)
			{
				newArr[i] = _array[i];
			}
		}

		

		delete[] _array;
		_array = newArr;
		_arraySize = newArrSize;
		_numberOfEntities = size;  // pocet se nastavi na velikost pole, jelikoz pole 
								   // bude vzdy naplnene hodnotou fill nebo prvky z predesleho pole
	}

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
	return _numberOfEntities;
}

template<class T, int S, int C>
inline unsigned int ExpandingArray<T, S, C>::GetArraySize() const
{
	return _arraySize;
}
