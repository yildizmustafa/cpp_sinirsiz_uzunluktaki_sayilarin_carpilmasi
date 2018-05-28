// Þablon düðüm sýnýfý
#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
using namespace std;

struct Dugum{
	int veri;
	Dugum *ileri;
	Dugum *geri;
	Dugum(const int& yeni=int(), Dugum *ilr=NULL, Dugum *gr=NULL){
		veri=yeni;
		ileri=ilr;
		geri=gr;
		
	}
};
#endif