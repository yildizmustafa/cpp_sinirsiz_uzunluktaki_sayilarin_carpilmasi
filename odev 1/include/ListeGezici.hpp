// Þablon liste gezici sýnýfý
#ifndef LISTEGEZICI_HPP
#define LISTEGEZICI_HPP

#include "Dugum.hpp"

class ListeGezici{//list iterator
	public:
		Dugum *simdiki;
		ListeGezici(){
			simdiki = NULL;
		}
		ListeGezici(Dugum *dugum){
				simdiki=dugum;
		}
		bool SonaGeldimi()const{
			if(simdiki == NULL) return true;
			return false;
		}
		bool BasaGeldimi()const{
			if(simdiki->geri == NULL) return true;
			return false;
		}
		bool SonDugumMu()const{
			if(simdiki->ileri == NULL) return true;
			return false;
		}
		void ilerle(){
			//if(SonaGeldimi()) throw SonaGeldi;
			simdiki=simdiki->ileri;
		}
		void gerigit(){
			simdiki=simdiki->geri;
		}
		const int& Getir(){
			//if(SonaGeldimi()) throw SonaGeldi;
			return simdiki->veri;
		}
		
};
#endif