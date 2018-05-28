#ifndef SAYI_HPP
#define SAYI_HPP
#include<string>
#include "Liste.hpp"
class Sayi{//number class
	private:
		string deger;
		Liste *rakam = new Liste();
	public:
		Yazdir();
		Sayi();
		Rakam();
		Sayi(string dgr);
		friend ostream& operator<<(ostream& ekran, Sayi &sag){
			ekran<<sag.deger;
			ekran<<endl;
			return ekran;
		}
		friend Sayi* operator*(Sayi &s1, Sayi &s2) {
			Sayi *sonuc = new Sayi();
			
			
			//s2.rakam->SifirlariAt();//alttaki sayıdaki herhangi bir sıfırın üstteki sayının tamamı ile çarpımı sıfır olacağından atıyoruz.
			//eğer bu normal bi çarpma işlemi olsaydı asla böyle bir şey yapmayacaktık.
			sonuc->rakam=s1.rakam->Carp(s1.rakam, s2.rakam);
			for(ListeGezici gezici(sonuc->rakam->Ilk());!gezici.SonaGeldimi();gezici.ilerle()){
				sonuc->deger+=gezici.simdiki->veri+'0';
			}
			return sonuc;
		}
		~Sayi(){
			delete rakam;
			delete this;
		}
};
#endif