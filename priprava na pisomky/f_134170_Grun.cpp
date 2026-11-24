#include <iostream>
#include <string>
using namespace std;

class Weapon {
    protected:
        string type = "";
        int range = 0;
        int usage = 100;

    public:
        virtual string getType() const {return type;}
        virtual int getRange() const {return range;}
        virtual int getUsage() const {return usage;}

        virtual bool attack(const Weapon &weapon) = 0;

        virtual ~Weapon() {}
};

class Spear : public Weapon {
    public:
        Spear() {
            type="spear";
            range=100;
            usage=usage*2;
        }
        bool attack(const Weapon &weapon) override {
            usage = usage - weapon.getRange() / 20;
            
            if (usage <= 0) {
                usage = 0;
                return false;
            }
            else if (usage > weapon.getRange()){
                return true;
            }
            else {return false;}
        }
};

class Bow : public Weapon {
    public:
    Bow() {
            type="bow";
            range=500;
            usage=usage/2;
        }
    bool attack(const Weapon &weapon) override {
        usage = usage - weapon.getRange() / 10;
            
            if (usage <= 0) {
                usage = 0;
                return false;
            }
            else if (usage > weapon.getRange()*1.5){
                return true;
            }
            else {return false;}

    }
};

class Battlefield {
    private:
        Weapon **army;
        int armyAmount;
    public:
        Battlefield(int armyAmount) {
            if (armyAmount <= 0) {
                army = nullptr;
                this->armyAmount = 0;
            }
            army = new Weapon*[armyAmount];
            for(int i = 0; i<armyAmount; i++) {
                if (i <= (armyAmount/2)) 
                {army[i]= new Bow;}
            else if (i > (armyAmount/2)) 
                {army[i]= new Spear;}
            }
        }
        ~Battlefield() {
            for(int i = 0; i<armyAmount; i++) {delete army[i];}
            delete[] army;
        }
        Weapon *getWeapon(int index) {
            if ((index > armyAmount) || (index < 0)) {return nullptr;}
            else {return army[index];} 
        }
        Weapon *getWeaponByType(int index, const string &type) {
            if (army[index]->getType() == type) {return army[index];}
            else return nullptr;
        }

};



int main() {
    
}