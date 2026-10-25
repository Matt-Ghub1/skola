// C++ program for function overriding and dynamic memory allocation for array of objects

#include <iostream>
using namespace std;

class Miestnost
{
public:
	Miestnost ()	{ 
        cout<< "Miestnost: Bola som postavena" <<endl; 
        }
    ~Miestnost ()	{ 
        cout<< "Miestnost: Bola som zburana" <<endl; 
        }


	virtual void mojaFunkcia ()
	{ cout<< "Miestnost: Mam 4 steny" <<endl; }
};

class Izba : public Miestnost
{
public:
	Izba () { 
        cout<< "Izba: Bola som zariadena" <<endl; 
        }

	void mojaFunkcia () override
	{ cout<< "Izba: Mam okna" <<endl; }
};

class Byt
{
public:
    Izba *izby;
    int size;
	Byt (int pocet_izieb)	{ 
        cout<< "Byt: Vytvaram byt s izbami" <<endl; 
        izby = new Izba[pocet_izieb];
        this->size = pocet_izieb;    
	}
	void vypis() {
        //Miestnost *mptr;
        for (int i = 0; i < size; i++)
        {
            cout<< "Index izby i: " << i <<endl; 
            //mptr = &izby[i];
            //mptr->mojaFunkcia();
            Miestnost &refm = izby[i];
            refm.mojaFunkcia();
        }
        
            
	}
	    
    ~Byt() {
        cout<< "Byt: Buram byt" <<endl;
        delete[] izby; 
    }

};

//main function
int main()
{
	int pocet_iz;
    cout<< "Zadaj pocet izieb:" <<endl; 
    cin >> pocet_iz;
    Byt byt(pocet_iz);
    byt.vypis();
    
    system("pause");
	return 0;
}
