#include "Sayi.hpp"
using namespace std;
		Sayi::Yazdir(){
			cout<<endl<<"string deger: "<<deger;
		}
		Sayi::Sayi(){
			
		}
		Sayi::Rakam(){
			cout<<*rakam;
		}
		Sayi::Sayi(string dgr){
			for(string::iterator it=dgr.begin(); it!=dgr.end();++it){
				if(isdigit(*it)){
					deger+=*it;
				}
			}
			for(string::iterator it=deger.begin(); it!=deger.end();++it){
				rakam->Ekle(*it-'0');
			}
			if(rakam->Bosmu()) rakam->Ekle(0);//hic bir rakam okunmaz ise 0 kabul eder
			rakam->BastakiSifirlariAt();//00000000651651 gibi bir string okunursa 0'ları atar.
			cout<<"girdigiz sayi : "<<*rakam<<endl;
		}
