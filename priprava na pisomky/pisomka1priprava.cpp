#include <iostream>
#include <string>
using namespace std;

// 1. uloha

int uloha1() {
    int x[][3][4]={{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    },
    {
        {13,14,15,16},
        {17,18,19,20},
        {21,22,23,24}
        
    }
};
    int velkosti = sizeof(x)/sizeof(x[0]);
    int velkostj= sizeof(x[0])/sizeof(x[0][0]);
    int velkostk= sizeof(x[0][0])/sizeof(x[0][0][0]);

    for (int i = 0; i<velkosti; i++) {
        int sucet = 0;
        for (int j = 0; j<velkostj; j++) {
            for (int k = 0; k<velkostk; k++) {
                cout << x[i][j][k] << " ";
                sucet += x[i][j][k];
            }
            cout << endl;
        }
        cout << "sucet vrstvy je :" << sucet <<endl;
        sucet =0;
    }

    return 0;
}

int uloha12() {
    char mesta[5][15]={"Mesto","Blava","Senec","Gbely","Kupac"};
    int velkostmesta = sizeof(mesta)/sizeof(mesta[0]);
    for(int i=0; i<velkostmesta; i++){
        cout << mesta[i] << endl;
    }

    mesta[2][1]='b';

    for(int i=0; i<velkostmesta; i++){
        cout << mesta[i] << endl;
    }

    const char *mesta2[5]={"Mesto","Blava","Senec","Gbely","Kupac"};

    for(int i=0; i<velkostmesta; i++){
        cout << "//////////////////////////////" << endl;
        cout << mesta2[i] << endl;
    }



    return 0;
}

int uloha3() {
    class Obdlznik {
        private:
        int a;
        int b;
        public:
        Obdlznik() {
            a=1;b=1;
        }
        Obdlznik(int a, int b) {
            this->a = a; this->b =b;
        }
        int obsah () {
            return a*b;
        }
        int obvod () {
            return (2*a)+(2*b);
        }
        void vypis() {
            cout << "rozmery obdlznika su: a="<< a <<" a b=" << b << endl;
            cout << "obsah obdlznika je: "<< obsah() << endl;
            cout << "obvod obdlznika je: "<< obvod() << endl;
        }
    };

    Obdlznik o(4, 6);
    o.vypis();
    Obdlznik u;
    u.vypis();

return 0;
}

int uloha4() {
    class Osoba {
        public:
        Osoba() {
            cout << "osoba vytvorena" << endl;
        }
        ~Osoba() {
            cout << "osoba zrusena" << endl;
        }

        virtual void kto_som() {
            cout <<  "som osoba" << endl;
        }
    };
    class Ziak : public Osoba {
        public:
        Ziak() {
            cout << "Ziak vytvoreny" << endl;
        }
        
        ~Ziak() {
            cout << "Ziak zruseny" << endl;
        }
        void kto_som() override 
        { cout << "Som ziak" << endl;}
    };

    class Ucitel : public Osoba {
        public:
        Ucitel() {
            cout << "Ucitel vytvoreny" << endl;
        }
        
        ~Ucitel() {
            cout << "Ucitel zruseny" << endl;
        }
        void kto_som() override 
        { cout << "Som Ucitel" << endl;}
    };


    class Skola {
        private:
        Ziak *ziaci;
        Ucitel *ucitelia;
        int pocetziakov;
        int pocetucitelov;
        
        public:
        Skola(int n, int m) {
            ziaci = new Ziak[n];
            ucitelia = new Ucitel[m];
            this->pocetziakov = n;
            this->pocetucitelov = m;
        }
  

        void vypis() {
            for (int i =0; i < pocetziakov ;i++) {
                cout << "ziak, index: "<< i << endl;
                Osoba &ref = ziaci[i];
                ref.kto_som();
            }
            
            for (int i =0; i < pocetucitelov ;i++) {
                cout << "ucitel, index: "<< i << endl;
                Osoba &ref = ucitelia[i];
                ref.kto_som();
            }
        }
              ~Skola() {
            cout << "Ziaci aj Ucitelia opustili Skolu" << endl;
            delete[] ziaci;
            delete[] ucitelia;
        }
    };
    int pz,pu;
    cout << "Zadaj pocet ziakov: ";
    cin >> pz;
    cout << "Zadaj pocet ucitelov: ";
    cin >> pu;

    Skola skola(pz, pu);
    skola.vypis();
    
    
    
    return 0;
}

int main() {
    uloha4();
}

