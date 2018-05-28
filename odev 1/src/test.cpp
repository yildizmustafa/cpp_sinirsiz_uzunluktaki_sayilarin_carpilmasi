#include "Liste.hpp"
#include "Sayi.hpp"
#include<fstream>

string sayi1,sayi2;


void SayilariEkrandanAl(){
	cout<<"1.sayi: "<<endl;
	cin>>sayi1;
	Sayi *s1 = new Sayi(sayi1);
	cout<<"2.sayi: "<<endl;
	cin>>sayi2;
	Sayi *s2 = new Sayi(sayi2);
	///sonucu * operatörü ile oluşturuyoruz
	Sayi *sonuc = *s1**s2;
	cout<<"sonuc: "<<*sonuc;
	///
}
void SayilariTxtDosyalarindanAl(){
	ifstream sa1 ("sayi1.txt");
	if(sa1.is_open()){
		getline(sa1,sayi1);
		sa1.close();
	}
	Sayi *s1 = new Sayi(sayi1);
	ifstream sa2 ("sayi2.txt");
	if(sa2.is_open()){
		getline(sa2,sayi2);
		sa2.close();
	}
	Sayi *s2 = new Sayi(sayi2);
	///sonucu * operatörü ile oluşturuyoruz
	Sayi *sonuc = *s1**s2;
	cout<<"sonuc: "<<*sonuc;
	///
	ofstream SONUC ("sonuc.txt");	
	if(SONUC.is_open()){
		SONUC<<*sonuc;
		SONUC.close();
	}
}

int main(){

	SayilariEkrandanAl();
	//SayilariTxtDosyalarindanAl();

	return 0;
}
