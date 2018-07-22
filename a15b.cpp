#include <iostream>
#include <cassert>
#include <string>
using namespace std;


const string Creatures[4] = { "Human", "Cyberdemon", "Balrog", "Elf" };


class Creature {
    public:
        Creature();
        Creature(int newStrength, int newHitpoints);
        int getHitpoints() const { return hitpoints; }
        int getStrength() const { return strength; }
        void setHitpoints(int hp) {  hitpoints = hp; }
        void setStrength(int strength) { strength = strength; }
        virtual string getSpecies() const { return Creatures[0]; }
        int getDamage() const;
    private:
        int strength;           // how much damage this Creature inflicts
        int hitpoints;          // how much damage this Creature can sustain
};


Creature::Creature() {
   strength = 10;
   hitpoints = 10;
}






Creature::Creature(int str, int hp) {
   strength = str;
   hitpoints = hp;
}






int Creature::getDamage() const {
   int damage;
   damage = (rand( ) % strength) + 1;

   cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
   
   return damage;
}



///////////
// HUMAN //
///////////
class Human: public Creature {
    public:
        Human();
        Human(int strength, int hp);
        string getSpecies() const { return Creatures[0]; }
        int getDamage() const;
};

Human::Human() { }
Human::Human(int strength, int hp) : Creature(strength, hp) { }


int Human::getDamage() const {
    int damage = Creature::getDamage();
    return damage;
}


/////////
// Elf //
/////////
class Elf: public Creature {
    public:
        Elf();
        Elf(int strength, int hp);
        string getSpecies() const { return Creatures[3]; }
        int getDamage() const;
};

Elf::Elf() { }
Elf::Elf(int strength, int hp) : Creature(strength, hp) { }

int Elf::getDamage() const {
    int damage = Creature::getDamage();

    // Elves inflict double magical damage with a 50% chance
    if ((rand() % 2) == 0) {
        cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        damage *= 2;
    }

    return damage;
}


///////////
// Demon //
///////////
class Demon: public Creature {
    public:
        Demon();
        Demon(int strength, int hp);
        string getSpecies() const { return "Demon"; }
        int getDamage() const;
};

Demon::Demon() { }
Demon::Demon(int strength, int hp) : Creature(strength, hp) { }


int Demon::getDamage() const {
    int damage = Creature::getDamage();

    if (rand() % 4 == 0) {
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 additional damage points!" << endl;
    }

    return damage;
}

////////////
// Balrog //
////////////
class Balrog: public Demon {
    public:
        Balrog();
        Balrog(int strength, int hp);
        string getSpecies() const { return Creatures[2]; }
        int getDamage() const;
};
Balrog::Balrog() { }
Balrog::Balrog(int strength, int hp) : Demon(strength, hp) { }


int Balrog::getDamage() const {
    int damage, damage2;
    
    damage = Demon::getDamage();

    damage2 = (rand() % getStrength()) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    damage += damage2;
    return damage;
}
////////////////
// Cyberdemon //
////////////////
class Cyberdemon: public Demon {
    public:
        Cyberdemon();
        Cyberdemon(int strength, int hp);
        string getSpecies() const { return Creatures[1]; }
        int getDamage() const;
};

Cyberdemon::Cyberdemon() { }
Cyberdemon::Cyberdemon(int strength, int hp) : Demon(strength, hp) { }


int Cyberdemon::getDamage() const {
    int damage = Demon::getDamage();

    return damage;
}




int main() {
    cout << "Hello " << endl;

    srand(static_cast<unsigned>(time(0)));

    Elf e1;
    Elf e(40, 50);

    Human h1;
    Human h(20, 30);

    Cyberdemon c1;
    Cyberdemon c(60, 70);

    Balrog b1;
    Balrog b(80, 90);



    cout << "default Human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
    cout << "default Elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
    cout << "default Cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
    cout << "default Balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
    cout << "non-default Human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
    cout << "non-default Elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
    cout << "non-default Cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
    cout << "non-default Balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
    cout << endl << endl;

    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
       int damage = h.getDamage();
       cout << " Total damage = " << damage << endl;
       cout << endl;
    }
    cout << endl;



    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;



    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
       int damage = c.getDamage();
       cout << " Total damage = " << damage << endl;
       cout << endl;
    }
    cout << endl;



    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++){
       int damage = b.getDamage();
       cout << " Total damage = " << damage << endl;
       cout << endl;
    }
    cout << endl;
}
