#include <iostream>
#include <string>
using namespace std;


class Stromy {
    public:
        Stromy() {
            cout << "Bol som zasadeny" << endl;
        }
        virtual ~Stromy() {
            cout << "Bol som vytaty" << endl;
        }

        virtual void mojaFunkcia() {
            cout << "Som uzitocny" << endl;
        }

    };

class OvocneStromy : public Stromy {
    void mojaFunkcia() override {
        cout << "Davam ovocie" << endl;
    }
};

class OkrasneStromy : public Stromy {
    void mojaFunkcia() override {
        cout << "Som pekny" << endl;
    }

};

class Zahrada {
    private:
    int pocetOkrasnych;
    int pocetOvocnych;
    OkrasneStromy* okrasne;
    OvocneStromy* ovocne;

    public:
    Zahrada(int pocetOkr, int pocetOvo) {
        pocetOkrasnych = pocetOkr;
        pocetOvocnych = pocetOvo;

        ovocne = new OvocneStromy[pocetOvocnych];
        okrasne = new OkrasneStromy[pocetOkrasnych];
    }

    void vypis() {
        cout << ">>>>>>>>>>>>>>OVOCNE STROMY<<<<<<<<<<<<<<" << endl;
        for (int i = 0; i < pocetOvocnych; i++) {
            Stromy* s = &ovocne[i]; 
            cout << "Ovocny strom c." << i+1 << ": ";
            s->mojaFunkcia(); 
        }
        cout << ">>>>>>>>>>>>>>OKRSNE STROMY<<<<<<<<<<<<<<" << endl;
        for (int i = 0; i < pocetOkrasnych; i++) {
            Stromy* s = &okrasne[i]; 
            cout << "Okrasny strom c." << i+1 << ": ";
            s->mojaFunkcia(); 
        }

    }


    ~Zahrada () {
        delete[] ovocne;
        delete[] okrasne;
        cout << "zahrada je znicena" << endl;
    }
};



int main() {
    int pocOv, pocOkr;
    cout << "Zdaj pocet Ovocnych stromov: "<< endl;
    cin >> pocOv;
    cout << "Zdaj pocet Okrasnych stromov: "<< endl;
    cin >> pocOkr;

    Zahrada z(pocOkr,pocOv);
    z.vypis();

    return 0;
}