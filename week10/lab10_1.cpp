#include <iostream>

// Implementor
class Wand {
public:
    virtual void cast() = 0;
protected:
    Wand(){std::cout << "Wand()" << std::endl;}
    virtual ~Wand() { std::cout << "~Wand()" << std::endl; }
};

// ConcreteImplementor A
class OrdinaryWand: public Wand {
public:
    OrdinaryWand() {
      std::cout << "OrdinaryWand()" << std::endl;
    }
    virtual ~OrdinaryWand() {
      std::cout << "~OrdinaryWand()" << std::endl;
    }
    void cast() {
        std::cout << "OrdinaryWand" << std::endl;
    }
};

// ConcreteImplementor B
class ElderWand: public Wand {
public:
    ElderWand() {
      std::cout << "ElderWand()" << std::endl;
    }
    virtual ~ElderWand() {
      std::cout << "~ElderWand()" << std::endl;
    }
    void cast() {
        std::cout << "ElderWand" << std::endl;
    }
};

// Abstraction
class Wizard {
public:
    virtual void castSpell(){
      std::cout << "Casting spell using ";
      wand.cast();
    } // low-level
    Wizard(Wand& di):wand(di){
      std::cout << "Wizard(Wand&)" << std::endl;
    }
    virtual ~Wizard() {
      std::cout << "~Wizard()" << std::endl;
    }
protected:
    Wand& wand;
};

// Refined Abstraction
class DeathEater: public Wizard {
public:
    DeathEater(Wand& Implementor):Wizard(Implementor) {
      std::cout << "DeathEater(Wand&)" << std::endl;
    }
    virtual ~DeathEater() {
      std::cout << "~DeathEater()" << std::endl;
    }
    // low-level i.e. Implementation specific
    void castSpell() {
        std::cout << "Casting dark magic spell using ";
        wand.cast();
    }
};

using namespace std;

int main() {
    ElderWand ewand;
    OrdinaryWand owand;

    Wizard wz1(ewand);
    DeathEater de(owand);
    Wizard wz2(owand);

    Wizard* wizards[3];
    wizards[0] = &wz1;
    wizards[1] = &de;
    wizards[2] = &wz2;

    for(auto w : wizards)
      w->castSpell();

    return 0;
}
