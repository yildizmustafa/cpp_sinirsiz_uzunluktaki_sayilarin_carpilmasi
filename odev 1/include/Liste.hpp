
#ifndef LISTE_HPP
#define LISTE_HPP
#include<iostream>
#include<string>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include "ListeGezici.hpp"
using namespace std;
class Liste{
	private:
		Dugum *basDugum; // içinde eleman olmayan sadece listenin baþýný tutan düðüm.
		double elemanSayisi;
		
		/// Eleman içermeyen liste baþýný döndürüyor
		ListeGezici ListeBasi() const{
			return ListeGezici(basDugum);
		}
		ListeGezici OncekiniBul(const int& aranan){
			Dugum *gezici = basDugum;
			while(gezici->ileri != NULL){
				if(gezici->ileri->veri == aranan) return ListeGezici(gezici);
				gezici = gezici->ileri;
			}
			//throw ElemanYok();
		}
		ListeGezici OncekiniKonumuIleBul(int konum) {
			if(konum<0 || konum > Uzunluk());
			int indeks=0;
			Dugum *gezici = basDugum;
			while(gezici->ileri != NULL && konum != indeks++) gezici = gezici->ileri;
			return ListeGezici(gezici);
		}
		
		ListeGezici BulKonum(int konum){
			//if(konum<0 || konum > Uzunluk()) throw Tasma();
			int indeks=0;
			Dugum *gezici = basDugum;
			while(gezici->ileri != NULL && konum != indeks++) gezici = gezici->ileri;
			return ListeGezici(gezici);
		}
		
		/*ListeGezici Bul(const int& aranan)
		{
			Dugum *gezici = basDugum;
			while(gezici != NULL && gezici->veri != aranan) gezici=gezici->ileri;
			//if(gezici == NULL) throw ElemanYok();
			return ListeGezici(gezici);
		}*/
	public:
		Liste(){
			basDugum = new Dugum; // Boþ bir düðüm oluþturuluyor	
			elemanSayisi=0;			
		}
		bool Sifir(){
			if(Uzunluk()==1 && basDugum->ileri->veri==0) return true;
			return false;
		}
		bool Bosmu() const{
			if(Uzunluk()==0) return true;
			return false;		
		}
		double Uzunluk() const{
			return elemanSayisi;
		}		
		/// Listenin ilk düðümünü döndürür
		ListeGezici Ilk() const{
			//if(Bosmu()) throw ListeBos();
			return ListeGezici(basDugum->ileri);
		}
		/// Listenin son düðümünü döndürür
		ListeGezici Son() const{
			//if(Bosmu()) throw ListeBos();
			ListeGezici gezici;
			for(gezici=Ilk();!gezici.SonDugumMu();gezici.ilerle());
			return ListeGezici(gezici.simdiki);
		}
		/// Listenin ilk elemanýný döndürür
		const int& IlkEleman() const{
			//if(Bosmu()) throw ListeBos();
			return basDugum->ileri->veri;
		}
		/// Listenin son elemanýný döndürür
		const int& SonEleman() const{
			//if(Bosmu()) throw ListeBos();
			ListeGezici gezici(Son());
			return gezici.simdiki->veri;
		}
		/// Listenin sonuna verilen elemaný ekler
		void Ekle(const int& yeni){
			Ekle(yeni,Uzunluk());
		}
		/// Listenin istenen konumuna verilen elemaný ekler
		void Ekle(const int& yeni,int konum){
			ListeGezici gezici;
			gezici = OncekiniKonumuIleBul(konum);
			Dugum *geciciGeri = gezici.simdiki->ileri;
			gezici.simdiki->ileri = new Dugum(yeni,gezici.simdiki->ileri,gezici.simdiki);
			if(geciciGeri != NULL) geciciGeri->geri = gezici.simdiki->ileri;
			elemanSayisi++;
		}
		/// Verilen elemaný listede bulur ve siler.
		void Sil(const int& aranan){			
			int konum = KonumuBul(aranan);
			KonumdakiniSil(konum);
		}
		void KonumdakiniSil(int konum){
			ListeGezici gezici = OncekiniKonumuIleBul(konum);
			Dugum *sil = gezici.simdiki->ileri;
			gezici.simdiki->ileri = gezici.simdiki->ileri->ileri;
			if(gezici.simdiki->ileri != NULL) gezici.simdiki->ileri->geri = gezici.simdiki;
			delete sil;
			elemanSayisi--;
		}
		void Sil(){//sondan siler
			ListeGezici gezici(Son());
			gezici.gerigit();
			Dugum *sil = gezici.simdiki->ileri;
			gezici.simdiki->ileri = gezici.simdiki->ileri->ileri;
			delete sil;
			elemanSayisi--;
		}
		/*
		bool ElemanBul(const int& aranan) const{
			if(Bosmu()) return false;
			for(ListeGezici gezici(basDugum->ileri);!gezici.SonaGeldimi();gezici.ilerle()){
				if(gezici.Getir() == aranan) return true;
			}
			return false;
		}*/
		int KonumuBul(const int& aranan){
			//if(Bosmu()) throw ElemanYok();
			int indeks=0;
			for(ListeGezici gezici(basDugum->ileri);!gezici.SonaGeldimi();gezici.ilerle()){
				if(gezici.Getir() == aranan) return indeks;
				indeks++;
			}
			//throw ElemanYok();
		}
		/// Listedeki elemanlarý temizler
		void Temizle(){
			while(!Bosmu())
				Sil(Ilk().Getir());
		}
		~Liste(){
			Temizle();
			delete basDugum;
		}
		friend ostream& operator<<(ostream& ekran, Liste &sag){
			if(sag.Bosmu()) ekran<<"Liste bos";
			ListeGezici gezici = sag.Ilk();
			for(;!gezici.SonaGeldimi();gezici.ilerle())
				ekran<<gezici.Getir();
			ekran<<endl;
			return ekran;
		}
		void BastakiSifirlariAt(){
			while(IlkEleman()==0 && Uzunluk()!=1){
				KonumdakiniSil(0);
			}
		}
		void SondakiSifirlariAt(){
			while(SonEleman()==0  && Uzunluk()!=1){
				Sil();
			}
		}
		void SifirlariAt(){
			ListeGezici gezici(Ilk());
			for(;!gezici.SonaGeldimi();gezici.ilerle()){
				if (gezici.simdiki->veri==0 && Uzunluk()!=1){
					Dugum *sil = gezici.simdiki;
					gezici.simdiki=gezici.simdiki->geri;
					gezici.simdiki->ileri=sil->ileri;
					if(sil->ileri!=NULL) sil->ileri->geri=gezici.simdiki;
					delete sil;
				}
			}
			cout<<"2. sayida sifir gereksiz onlari atalim : "<<*this;
		}
		void HepsiSifirsaTekSifirYap(){
			BastakiSifirlariAt();
			SondakiSifirlariAt();
			if(Bosmu()) Ekle(0);
		};
		Liste* Carp(Liste *&s1, Liste *&s2){
			Liste *Temp = new Liste();
			Liste *Aratoplam = new Liste();
			Liste *Sonuc = new Liste();
			ListeGezici gezici1(s1->Son());
			ListeGezici gezici2(s2->Son());
			if(s2->Sifir() || s1->Sifir())
			{
				Sonuc->Ekle(0);
				return Sonuc;
			}
			int kalan=0;
			int aracarpan=0;
			for(;!gezici2.BasaGeldimi();gezici2.gerigit()){
				if(!Temp->Bosmu() && Aratoplam->Bosmu()){
					for(ListeGezici geziciTemp(Temp->Son());!geziciTemp.BasaGeldimi();geziciTemp.gerigit()){
						Aratoplam->Ekle(geziciTemp.simdiki->veri,0);
					}
					Temp->Temizle();
					cout<<"aratoplam: "<<*Aratoplam;
				}
				///ÇARPMA ÝÞLEMÝ								
				for(;!gezici1.BasaGeldimi();gezici1.gerigit()){
					aracarpan=gezici1.simdiki->veri*gezici2.simdiki->veri+kalan;
					Temp->Ekle(aracarpan%10,0);
					kalan=(aracarpan-aracarpan%10)/10;
				}
				if(kalan!=0){
					Temp->Ekle(kalan,0);
					Temp->BastakiSifirlariAt();
					cout<<"temp: "<<*Temp;
				}
				else {
					Temp->BastakiSifirlariAt();
					cout<<"temp: "<<*Temp;
				}
				for(;!gezici1.SonDugumMu();gezici1.ilerle());
				kalan=0;
				///TOPLAMA
				if(!Aratoplam->Bosmu() && !Temp->Bosmu()){
					for(ListeGezici gezici3(gezici2.simdiki->ileri);!gezici3.SonaGeldimi();gezici3.ilerle())
					{
						Temp->Ekle(0);
					}
					if(Temp->Uzunluk()<Aratoplam->Uzunluk())
					{
						for(ListeGezici gezici(Aratoplam->Son());!gezici.BasaGeldimi();gezici.gerigit()){
							Temp->Ekle(0,0);
						}
					}
					if(Temp->Uzunluk()>Aratoplam->Uzunluk()) 
					{
						for(ListeGezici gezici(Temp->Son());!gezici.BasaGeldimi();gezici.gerigit()){
							Aratoplam->Ekle(0,0);
						}
					}
					Sonuc->Temizle();
					int kln=0;			
					int toplam=0;
					ListeGezici geziciTemp(Temp->Son());
					ListeGezici geziciAra(Aratoplam->Son());
					for(;!geziciTemp.BasaGeldimi();geziciTemp.gerigit()){
						toplam = geziciTemp.simdiki->veri + geziciAra.simdiki->veri + kln;
						if(toplam<10){
							Sonuc->Ekle(toplam,0);
							geziciAra.gerigit();
							kln = (toplam-toplam%10)/10;
						}
						else{
							Sonuc->Ekle(toplam%10,0);
							kln = (toplam-toplam%10)/10;
							geziciAra.gerigit();
						}
					}
					if(kln!=0){
					Sonuc->Ekle(kln,0);
					}
					if(Temp->Uzunluk()<Aratoplam->Uzunluk()){
						ListeGezici geziciSonuc(Sonuc->Ilk());
						toplam = geziciSonuc.simdiki->veri + geziciAra.simdiki->veri;
						if(toplam<10) geziciSonuc.simdiki->veri = toplam;
						else{
							Sonuc->Ekle(geziciAra.simdiki->veri,0);
						}
						
					}
					else{
						ListeGezici geziciSonuc(Sonuc->Ilk());
						toplam = geziciSonuc.simdiki->veri + geziciTemp.simdiki->veri;
						if(toplam<10) geziciSonuc.simdiki->veri = toplam;
						else{
							Sonuc->Ekle(geziciTemp.simdiki->veri,0);
						}
					}
					while(Sonuc->IlkEleman()==0){
						Sonuc->KonumdakiniSil(0);
					}
					if(Sonuc->Bosmu()) {
						Sonuc->Ekle(0);
					}
					cout<<"aratoplam: "<<*Sonuc;
					Aratoplam->Temizle();
					for(ListeGezici geziciSonuc(Sonuc->Son());!geziciSonuc.BasaGeldimi();geziciSonuc.gerigit()){
						Aratoplam->Ekle(geziciSonuc.simdiki->veri,0);
					}
					Temp->Temizle();
				}
				if(Sonuc->Bosmu()){
					for(ListeGezici geziciTemp(Temp->Son());!geziciTemp.BasaGeldimi();geziciTemp.gerigit()){
						Sonuc->Ekle(geziciTemp.simdiki->veri,0);
						}
				}
			}
			delete Temp;
			delete Aratoplam;
			return Sonuc;
		}
};
#endif