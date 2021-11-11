#pragma once
#ifndef ROUSTOUCIKONTEJNER_H
#define ROUSTOUCIKONTEJNER_H

#include <stdexcept>

template <class TypDat, int PocetecniVelikost = 5, int RostouciKoeficient = 10>

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

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline bool RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::jeMistoVPoli() const
{
	return _velikostPole > _pocetPlatnychPrvku;
}


template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline void RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::zvetsiPole()
{
	int newArrSize = _velikostPole * RostouciKoeficient;
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

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::RoustouciKontejner()
{
	_pole = new TypDat[PocatecniVelikost];
	_velikostPole = PocatecniVelikost;
	_pocetPlatnychPrvku = 0;
}

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::RoustouciKontejner(const TypDat& vypln)
{
	_pole = new TypDat[PocatecniVelikost];
	_velikostPole = PocatecniVelikost;
	_pocetPlatnychPrvku = _velikostPole;

	std::fill_n(_pole, _velikostPole, vypln);
}

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::~RoustouciKontejner()
{
	delete[] _pole;
}

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline void RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::Pridej(const TypDat& e)
{
	if (!jeMistoVPoli()) {
		zvetsiPole();
	}
	_pole[_pocetPlatnychPrvku] = e;
	_pocetPlatnychPrvku += 1;
}
template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline void RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::Realokuj(int velikost, const TypDat& vypln)
{
	if (velikost <= 0) {
		throw std::invalid_argument("size can not be 0 or smaller");
	}
	else {
		int newArrSize = velikost;
		TypDat* newArr = new TypDat[newArrSize];

		// pokud nove pole ma vetsi velikost nez pocet prvku v poli,
		// tak vypln pole hodnotou fill. Jinak realokuj pole. 

		if (velikost > _pocetPlatnychPrvku) {
			// nejdrive naplni stare prvky
			for (int i = 0; i < _pocetPlatnychPrvku; i++)
			{
				newArr[i] = _pole[i];
			}
			
			// doplneni pole hodnotou fill od poctu starych prvku az do nove velikost pole
			for (int i = _pocetPlatnychPrvku; i < velikost; i++)
			{
				newArr[i] = vypln;
			}
		}
		else {
			for (int i = 0; i < velikost; i++)
			{
				newArr[i] = _pole[i];
			}
		}

		delete[] _pole;
		_pole = newArr;
		_velikostPole = newArrSize;
		_pocetPlatnychPrvku = velikost;  // pocet se nastavi na velikost pole, jelikoz pole 
										// bude vzdy naplnene hodnotou fill nebo prvky z predesleho pole
	}

}

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline TypDat& RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::Dej(int i)
{
	if (_pocetPlatnychPrvku < i || i <= 0) {
		throw std::invalid_argument("There is no element in collection");
	}

	return _pole[i - 1];
}

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline TypDat RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::Dej(int i) const
{
	if (_pocetPlatnychPrvku < i || i <= 0) {
		throw std::invalid_argument("There is no element in collection");
	}
	return _pole[i - 1];
}

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline unsigned int RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::DejPocetPrvku() const
{
	return _pocetPlatnychPrvku;
}

template<class TypDat, int PocatecniVelikost, int RostouciKoeficient>
inline unsigned int RoustouciKontejner<TypDat, PocatecniVelikost, RostouciKoeficient>::DejVelikostPole() const
{
	return _velikostPole;
}