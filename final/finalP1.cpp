#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

//character class as the prototype in the prototype pattern
//supporting the clone operation; having copy constructor for cloning and separate peration for reinitializing internal state

class Character{
public:
	virtual ~Character() {}
	virtual string name() = 0;
	virtual string getLeader() = 0;
	virtual Character* clone() = 0;
	Character(const Character&);
	virtual void initialize(string, string);

protected:
	string leader;
	string char_name;
};

Character::Character (const Character& other){
	leader = other.leader;
	char_name = other.char_name;
}

void Character::initialize(string lb, string nam){
	leader = lb;
	char_name = nam;
}


class Jedi: public Character{
public:
	Jedi(){leader = "Yoda";}
	Jedi(string ledby):leader(ledby){}
	virtual Character* clone() const;
	virtual string getLeader(){return leader;}
	virtual string name(){return char_name;}
};

void Character* Jedi::clone() const{
	return new Jedi(*this);
}

class SnowTrooper: public Character{
public:
	SnowTrooper(){leader = "SnowTrooper Leader";}
	SnowTrooper(string ledby):leader(ledby){}
	virtual Character* clone() const;
	virtual string getLeader(){return leader;}
	virtual string name(){return char_name;}
};

void Character* SnowTrooper::clone() const{
	return new SnowTrooper(*this);
}

class Avenger: public Character{
public:
	Avenger(){leader = "Captain America";}
	Avenger(string ledby):leader(ledby){}
	virtual Character* clone() const;
	virtual string getLeader(){return leader;}
	virtual string name(){return char_name;}
};

void Character* Avenger::clone() const{
	return new Avenger(*this);
}

class Hydra: public Character{
public:
	Hydra(){leader = "Viper";}
	Hydra(string ledby):leader(ledby){}
	virtual Character* clone() const;
	virtual string getLeader(){return leader;}
	virtual string name(){return char_name;}
};

void Character* Hydra::clone() const{
	return new Hydra(*this);
}

class Scene{
private:
    string action;
    Character* char1;
    Character* char2;
    int char1_num;
    int char2_num;
public:
    Scene(string act, Character* h, Character* v, int i, int j): action(act), char1(h), char2(v), char1_num(i), char2_num(j){}
    void playScene(){
        cout << "Playing " << action <<  " Scene:" << endl;
        cout <<  char1_num << " " << char1->name() << "s led by " << char1->getLeader() << " ";
        cout << action << "-ing "<< char2_num << " " << char2->name() << "s led by " << char2->getLeader() << endl;
    }
};

ckass SceneStartup{
	public:
		void createScene();
		void playScene();
	private:
		Scene* scene;
}

//the SceneBuilder class defines the following interface for building scenes:
class SceneBuilder{
	public:
		virtual void buildScene() = 0;
		virtual void buildChar1() = 0;
		virtual void buildChar2() = 0;		
		virtual Character* getChar1() = 0;
		virtual Character* getChar2() = 0;
	protected:
		SceneBuilder();
}; 

int main(){
    // First test run
		/*
    Movie starWars;

	  CharactersBuilder starWarsCharsBuilder(new Jedi, new SnowTrooper);
    starWars.createFightScene(starWarsCharsBuilder, 2, 10);
    starWars.createBattleScene(starWarsCharsBuilder, 15, 100);

    CharactersBuilder starWarsCharsBuilder2(new Jedi("Obi-Wan Kenobi"), new SnowTrooper("Darth Vader"));
    starWars.createFightScene(starWarsCharsBuilder2, 10, 1000);

    cout << "Movie Star Wars Playing: " << endl;
    starWars.playMovie();
    */

    // second test run
		/*
    Movie theAvengers;

	  CharactersBuilder theAvengersBuilder(new Avenger, new Hydra("Loki"));
    theAvengers.createFightScene(theAvengersBuilder, 2, 10);

    CharactersBuilder theAvengersBuilder2(new Avenger("Thor"), new Hydra);
    theAvengers.createFightScene(theAvengersBuilder2, 4, 120);

    CharactersBuilder theAvengersBuilder3(new Avenger("Thor"), new SnowTrooper("Kylo Ren"));
    theAvengers.createBattleScene(theAvengersBuilder3, 2, 1200);

    cout << "Movie the Avengers Playing: " << endl;
    theAvengers.playMovie();
    */

}
