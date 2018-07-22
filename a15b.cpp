#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


// const string Creatures[4] = { "Human", "Cyberdemon", "Balrog", "Elf" };


class Creature {
    public:
        // ENUM TYPE
        const string Creatures[4] = { "Human", "Cyberdemon", "Balrog", "Elf" };
        Creature();
        Creature(int newStrength, int newHitpoints);
        int getHitpoints() const { return hitpoints; }
        int getStrength() const { return strength; }
        void setHitpoints(int hp) {  hitpoints = hp; }
        void setStrength(int strength) { strength = strength; }
        virtual string getSpecies() const = 0;
        virtual int getDamage() const;
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
};

Human::Human() { }
Human::Human(int strength, int hp) : Creature(strength, hp) { }


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
};

Cyberdemon::Cyberdemon() { }
Cyberdemon::Cyberdemon(int strength, int hp) : Demon(strength, hp) { }


//////////
// MAIN //
//////////

void battleArena(Creature &Creature1, Creature& Creature2);

int main() {
    srand(static_cast<unsigned>(time(0)));

    Elf e(50,50);
    Balrog b(50,50);;

    battleArena(e, b);


    Human h(50,400);
    Cyberdemon b1(10,500);;

    battleArena(h, b1);

}


void battleArena(Creature& Creature1, Creature& Creature2) {
    string result = " ", winner;

    while (result == " ") {
        // calculate the damage done by Creature1
        // subtract that amount from Creature2's hitpoints
        Creature2.setHitpoints(Creature2.getHitpoints() - Creature1.getDamage());
        // calculate the damage done by Creature2
        // subtract that amount from Creature1's hitpoints
        Creature1.setHitpoints(Creature1.getHitpoints() - Creature2.getDamage());
        
        // remaining hps
        int creature1HP = Creature1.getHitpoints();
        int creature2HP = Creature2.getHitpoints();

        if (creature1HP == 0 && creature2HP == 0) {
            result = "tie";
            cout << result << endl;
        } else if (creature1HP <= 0 || creature2HP <= 0) {
            result = "game over";
            cout << result << endl;
            winner = creature1HP < creature2HP ? Creature2.getSpecies() : Creature1.getSpecies();
            cout <<  winner << " won";
        } else {
            cout << "Another round" << endl;
            cout << "HP 1: " << creature1HP << " | HP 2: " << creature2HP << endl;
        }
        cout << endl;
        cout << endl;
    }
}