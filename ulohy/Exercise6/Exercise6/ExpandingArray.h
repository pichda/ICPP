#pragma once
#ifndef ROUSTOUCIKONTEJNER_H
#define ROUSTOUCIKONTEJNER_H

#include <stdexcept>

template <class TypDat, int PocetecniVelikost = 5, int C = 10>

class RoustouciKontejner {
private:
	TypDat* _pole;
	unsigned _velikostPole;
	unsigned _pocetPlatnychPrvku;

	bool jeMistoVPoli() const;
	void zvetsiPole();

public:
	RoustouciKontejner();
	RoustouciKontejner(const TypDat& vypln);
	~RoustouciKontejner();
	void Pridej(const TypDat& o);
	void Realokuj(int velikost, const TypDat& vypln);
	TypDat& Dej(int index);
	TypDat Dej(int index) const;
	unsigned int DejPocetPrvku() const;
	unsigned int DejVelikostPole() const;
};

#endif ROUSTOUCIKONTEJNER_H

template<class TypDat, int S, int C>
inline bool RoustouciKontejner<TypDat, S, C>::jeMistoVPoli() const
{
	return _velikostPole > _pocetPlatnychPrvku;
}


template<class TypDat, int S, int C>
inline void RoustouciKontejner<TypDat, S, C>::zvetsiPole()
{
	int newArrSize = _velikostPole * C;
	TypDat* newArr = new TypDat[newArrSize];

	// memcpy(newArr, _array, newArrSize);

	for (int i = 0; i < _velikostPole; i++)
	{
		newArr[i] = _pole[i];
	}

	delete[] _pole;
	_pole = newArr;
	_velikostPole = newArrSize;
}

template<class TypDat, int S, int C>
inline RoustouciKontejner<TypDat, S, C>::RoustouciKontejner()
{
	_pole = new TypDat[S];
	_velikostPole = PocetecniVelikost;
	_pocetPlatnychPrvku = 0;
}

template<class TypDat, int S, int C>
inline RoustouciKontejner<TypDat, S, C>::RoustouciKontejner(const TypDat& fill)
{
	_pole = new TypDat[S];
	_velikostPole = PocetecniVelikost;
	_pocetPlatnychPrvku = _velikostPole;

	std::fill_n(_pole, _velikostPole, fill);
}

template<class TypDat, int S, int C>
inline RoustouciKontejner<TypDat, S, C>::~RoustouciKontejner()
{
	delete[] _pole;
}

template<class TypDat, int S, int C>
inline void RoustouciKontejner<TypDat, S, C>::Pridej(const TypDat& e)
{
	if (!jeMistoVPoli()) {
		zvetsiPole();
	}
	_pole[_pocetPlatnychPrvku] = e;
	_pocetPlatnychPrvku += 1;
}

template<class TypDat, int S, int C>
inline void RoustouciKontejner<TypDat, S, C>::Realokuj(int size, const TypDat& fill)
{
	if (size <= 0) {
		throw std::invalid_argument("size can not be 0 or smaller");
	}
	else {
		int newArrSize = size;
		TypDat* newArr = new TypDat[newArrSize];

		// pokud nove pole ma vetsi velikost nez pocet prvku v poli,
		// tak vypln pole hodnotou fill. Jinak realokuj pole. 
		if (size > _pocetPlatnychPrvku) {

		}
		else {

		}

		for (int i = 0; i < _velikostPole; i++)
		{
			newArr[i] = _pole[i];
		}

		delete[] _pole;
		_pole = newArr;
		_velikostPole = newArrSize;
	}

}

template<class TypDat, int S, int C>
inline TypDat& RoustouciKontejner<TypDat, S, C>::Dej(int i)
{
	if (_pocetPlatnychPrvku < i || i <= 0) {
		throw std::invalid_argument("There is no element in collection");
	}

	return _pole[i - 1];
}

template<class TypDat, int S, int C>
inline TypDat RoustouciKontejner<TypDat, S, C>::Dej(int i) const
{
	if (_pocetPlatnychPrvku < i || i <= 0) {
		throw std::invalid_argument("There is no element in collection");
	}
	return _pole[i - 1];
}

template<class TypDat, int S, int C>
inline unsigned int RoustouciKontejner<TypDat, S, C>::DejPocetPrvku() const
{
	return _pocetPlatnychPrvku;
}

template<class TypDat, int S, int C>
inline unsigned int RoustouciKontejner<TypDat, S, C>::DejVelikostPole() const
{
	return _velikostPole;
}
