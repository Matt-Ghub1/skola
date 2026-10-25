// C++ program for function overriding and dynamic memory allocation for array of objects

#include <iostream>
using namespace std;

class PrazdnyRiadok
{
public:
    char znak = ' ';
    char *znaky;
    int pocet_znakov;
	PrazdnyRiadok (int pocet_znakov)	{ 
        znaky = new char[pocet_znakov];
        this->pocet_znakov = pocet_znakov;
        cout<< "Prazdny riadok bol vytvoreny" <<endl; 
        }
    ~PrazdnyRiadok ()	{ 
        cout<< "Prazdny riadok bol zruseny" <<endl;
        delete[] znaky; 
        }
	virtual void prepis ()  { 
        for (int i = 0; i < pocet_znakov; i++)
        {
            znaky[i] = znak;
        }
    }
    void vypisRiadok ()  { 
        for (int i = 0; i < pocet_znakov; i++)
        {
            cout << znaky[i];
        }
        cout << endl;
    }
};

class NeparnyRiadok : public PrazdnyRiadok
{
public:
	NeparnyRiadok (int pocet_znakov, char znak) : PrazdnyRiadok(pocet_znakov){ 
        this->znak = znak;
        cout<< "Neparny riadok bol vytvoreny" <<endl; 
        }

	virtual void prepis ()  {
        for (int i = 0; i < pocet_znakov; i++)
            {
                znaky[i] = znak;
            }
    }
};

class ParnyRiadok : public PrazdnyRiadok
{
public:
    ParnyRiadok (int pocet_znakov, char znak) : PrazdnyRiadok(pocet_znakov){ 
        this->znak = znak;
        cout<< "Parny riadok bol vytvoreny" <<endl; 
        }

	virtual void prepis ()  {
        for (int i = 0; i < pocet_znakov; i++)
            {
                znaky[i] = znak;
            }
    }
};

class StvorcovaMatica
{
public:
    int pocet_znakov;
    char znak1;
    char znak2;
    PrazdnyRiadok *prptr1;
    NeparnyRiadok *nr;
    ParnyRiadok *pr;
	StvorcovaMatica (int pocet_znakov, char znak1, char znak2)  { 
        this->pocet_znakov = pocet_znakov;
        this->znak1 = znak1;
        this->znak2 = znak2;
        nr = new NeparnyRiadok(pocet_znakov,znak1); //IDE TO AJ TAKTO, ALE ZBYTOCNE KOMPLIKOVANE, MA SA TO ROBIT CEZ INICIALIZACNY LIST
        pr = new ParnyRiadok(pocet_znakov,znak2);
	}

    
	void vypis() {
        prptr1 = pr;
        prptr1->prepis();
        prptr1 = nr;
        prptr1->prepis();
        for (int i = 0; i < pocet_znakov; i++)
        {
            if (i%2)
            {
                pr->vypisRiadok();
            } else
            {
                nr->vypisRiadok();
            }
        }
          
	}
	    
    ~StvorcovaMatica() {
        delete nr;
        delete pr;
        cout<< "Stvorcova matica bola znicena" <<endl;
    }
};

//main function
int main()
{
	int pocet_znakov;
    cout<< "Zadaj pocet znakov:" <<endl; 
    cin >> pocet_znakov;
    char znak1;
    cout<< "Zadaj znak pre neparny riadok:" <<endl; 
    cin >> znak1;
    char znak2;
    cout<< "Zadaj znak pre parny riadok:" <<endl; 
    cin >> znak2;
    StvorcovaMatica matica(pocet_znakov,znak1,znak2);
    matica.vypis();
    //matica.nr.
    matica.nr->vypisRiadok();
    matica.pr->vypisRiadok();
	return 0;
}
