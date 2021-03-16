#include <iostream>
#include <fstream>
using namespace std;

class dane{	
	public:
		
		fstream plik1;
		string obraz[21];
		int tak = 0;
		int ktory = 0;
		int kolumna = 0;
		int wiersz = 0;
		int licz1 = 0;
		int licz2 = 0;
    	
    	void op();
    	void file();
    	void licz();
};
void dane::op(){
	plik1.open("obrazki.txt");
}

void dane::file(){
		
		    while(!plik1.eof()) {

        for(int i=0;i<21;i++) {
            plik1 >> obraz[i];
        }

        bool rekurencyjny = true;
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {

                if(obraz[i][j] != obraz[i][j+10] || obraz[i][j] != obraz[i+10][j] || obraz[i][j]!=obraz[i+10][j+10]) {
                    rekurencyjny = false;
                }
            }
        }

        if(rekurencyjny) {
            tak = 1;
        }
        ktory++;
        
        licz();
    }
}

void dane::licz(){
	
	if(tak==1){
		cout<<"Numer obrazka: "<<ktory<<", ";
		
		for (int i = 0; i < 20; i++) {
          for (int k = 0; k < 21; k++) {
			if (obraz[i][k] == '1' && k<20){
				licz1++;
				if(licz1%2==0 && obraz[i][k] == '1'){
					wiersz++;
				}
			}
		}
	}
		cout<<"Numer wiersza: "<<wiersz<<", ";
	
		for (int i = 0; i < 20; i++) {
          for (int k = 0; k < 21; k++) {
			if (obraz[k][i] == '1' && k<20){
				licz2++;
				if(licz2%2==0 && obraz[k][i] == '1'){
					kolumna++;
				}
			}
		}
	}
		cout<<"Numer kolumny: "<<kolumna<<endl;
}
	tak=0;
	kolumna = 0;
	wiersz = 0;
	licz1 = 0;
	licz2=0;
}

int main()
{
	dane d;
	d.op();
	d.file();

    return 0;
}

