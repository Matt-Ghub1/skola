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



int uloha5() {
    class Riadok {
        
        public:
        char *znaky;
        int pocet;
        char znak = ' ';

        Riadok (int pocet) {
            this->pocet = pocet;
            znaky = new char[pocet];
        }
        ~Riadok () {
            cout << "riadok zruseny" << endl;
            delete[] znaky;
    }
        virtual void prepis() {
            for (int i = 0; i<pocet; i++)
                znaky[i] = znak;
        }

        void vypisRiadok() {
            for (int i =0; i<pocet;i++){
               cout << znaky[i];
        }
        cout << endl;
    }

    };  

    class HviezdickovyRiadok : public Riadok {
        public:
        HviezdickovyRiadok(int pocet) : Riadok(pocet) {
            for (int i = 0; i<pocet; i++)
                znaky[i] = '*';
        }
        };

    class MriezkovyRiadok : public Riadok {
        public:
        MriezkovyRiadok(int pocet) : Riadok(pocet){
            for (int i = 0; i<pocet; i++)
                znaky[i] = '#';
        }
        };

        int pocetz = 0;

    cout<<"Zadaj pocet znakov: "<<endl;
    cin >> pocetz;
    HviezdickovyRiadok H(pocetz);
    MriezkovyRiadok M(pocetz);
    H.vypisRiadok();
    M.vypisRiadok();
    return 0;
}


int uloha6() {
    class Vozidlo {
        public:
         
        virtual double rychlost() const = 0;

        virtual ~Vozidlo() {}
    };
    
    class Auto : public Vozidlo {
        double rychlost() const override {return 120.0;}
    };
    

    class Bycikel : public Vozidlo {
        double rychlost() const override {return 25.0;}
    };

    int n;
    int volba;
    cout << "pocet (aut/byciklov):" << endl;
    cin >> n;
    Vozidlo **v = new Vozidlo*[n];
    for (int i = 0; i < n; i++) {
        cout << "Zvol auto(1) alebo bycikel(2):" << endl;
        cin >> volba;
        if (volba ==1) {v[i]=new Auto;}
        else if (volba == 2) {v[i]= new Bycikel;}
        cout << "rychlost je:" << v[i]->rychlost() << endl;
        delete v[i];
    }

    delete[] v;

    
    return 0;
}


int main() {
    uloha6();
}



//1) NAZVY ZAPISUJ PRESNE - test vola tvoje metody podla mena. Aj velkost
//     pismen, aj typ parametrov, aj public/protected/private. (Test moze
//     napr. dedit z tvojej triedy, aby sa dostal na protected clenov.)
//
//  2) ABSTRAKTNA TRIEDA:   virtual void f(int) = 0;   + virtual ~Trieda() {}
//     Potomok:             void f(int) override { ... }
//
//  3) KONSTRUKTOR POTOMKA nastavuje protected clenov predka v tele (alebo
//     zavola konstruktor predka v inicializacnom zozname: Potomok(): Predok(1,2) {}).
//
//  4) PARAMETER TIENUJE CLENA (rovnake meno)  ->  this->x = x;
//
//  5) DYNAMICKE POLE:      T* p = new T[n];     uvolnenie:  delete[] p;
//     Jedna premenna:      T* p = new T(...);               delete p;
//     Vzdy nullptr, ked nic neallokujes. Vzdy destruktor. Vzdy delete[] k new[].
//
//  6) 2D POLE:  T** m = new T*[r];  for i: m[i] = new T[c];
//     Uvolnenie: for i: delete[] m[i];  delete[] m;
//
//  7) PRAVIDLO TROCH: ak mas destruktor s delete -> napis aj kopirovaci
//     konstruktor a operator= (hlboka kopia, viz Tileset vyssie).
//
//  8) CONST: metoda, ktora nemeni stav objektu:  int getX() const;
//     Parametre, ktore len citas:  const std::string& s
//     Navrat referencie na string: const std::string& getType() const;
//
//  9) "NEPLATNA HODNOTA" pri zlom indexe: zvycajne nullptr (pri pointeri),
//     -1 / 0 (pri cisle), prazdny string, alebo vynimka:
//        throw std::out_of_range("index");   // #include <stdexcept>
//     Pozri zadanie, co presne chcu. Ak nie je jasne, nullptr pri pointeroch.
//
// 10) NAVRAT "AKO REFERENCIA/POINTER", ABY SA ZMENA PREJAVILA V OBJEKTE:
//     vracaj T* alebo T&, nie T (T = kopia, zmeny sa stratia).
//
// 11) STATIC clen (spolocny pre vsetky objekty):
//        class A { static int count; };      // v triede
//        int A::count = 0;                   // MIMO triedy, raz, v .cpp
//
// 12) OPERATORY:  bool operator==(const A& o) const { return x == o.x; }
//                 A operator+(const A& o) const { return A(x + o.x); }
//                 friend std::ostream& operator<<(std::ostream& os, const A& a);
//
// 13) CELOCISELNE DELENIE: 7/2 == 3 (zahadza desatinnu cast), -7/2 == -3.
//     Modulo: 7 % 2 == 1 (neparne).
//
// 14) POLE VS VECTOR: ak zadanie vyslovene hovori "dynamicke pole" / "new",
//     pouzi new[]. Ak nie, std::vector<T> je bezpecnejsi (netreba delete).
//
// 15) GTEST (ako to vyzera na druhej strane, len pre pochopenie):
//        #include <gtest/gtest.h>
//        #include "c_aisid_priezvisko.cpp"   // tvoj subor sa vlozi
//        TEST(GrassTest, Default) {
//            Grass g;
//            EXPECT_EQ(g.getY(), 1);
//            EXPECT_EQ(g.getType(), "grass");
//        }
//        // main() dodava gtest_main - ten nie je tvoj.
// ============================================================================