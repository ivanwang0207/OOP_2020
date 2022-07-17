#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

enum Direction {North, South, East, West};

class MapSite { 
public:
    virtual void enter() = 0;
};

class Room : public MapSite { 
public:
    Room(int roomNo){roomNum = roomNo;}
    MapSite* getSide(Direction d) const{
        return sides.find(d)->second;
    }
    void setSide(Direction d, MapSite* m){
        sides.insert({d,m});
    } 
    void enter(){
        cout << "You are in the room No."  << roomNum << "."<< endl;
    };
private:
    int roomNum;
    map<Direction, MapSite*> sides;
// add your own data members 
};

class Wall : public MapSite { 
public:
    Wall() = default;
    virtual void enter(){
        cout << "Hit the wall and hurt your nose!" << endl;
    }
};

class BombedWall : public Wall {
public:
    BombedWall() = default;
    void enter() {
        cout << "Hit the wall and bombed your nose!" << endl;
    }
};

class Door : public MapSite { 
public:
    Door(Room* r1= nullptr, Room* r2= nullptr){
        room1 = r1;
        room2 = r2;
    };
    void enter(){
        cout << "Entering another room" << endl;
    }
private:
    Room* room1;
    Room* room2;
// add your own data members
};

class Maze{
public:
    Maze() = default;
    void addRoom(Room* r){
        vec.push_back(r);
    }
    vector<Room*> getvec() const {
        return vec;
    }
private:
    vector<Room*> vec; 
};

class NormalMazeFactory {
public:
    NormalMazeFactory() {}
    virtual Maze* makeMaze() const{ 
        return new Maze; 
    }
    virtual Wall* makeWall() const{ 
        return new Wall; 
    }
    virtual Room* makeRoom(int n) const{ 
        return new Room(n); 
    }
    virtual Door* makeDoor(Room* r1, Room* r2) const{ 
        return new Door(r1, r2); 
    }
};

class BombedMazeFactory : public NormalMazeFactory{
	public:
		BombedMazeFactory() {}
		virtual Wall* makeWall() const override{ 
			return new BombedWall; 
		}
};

class MazeGame{
public:
    MazeGame() {}
    void createMaze(NormalMazeFactory* factory){
        aMaze = factory->makeMaze();
        Room* r1 = factory->makeRoom(1);
        Room* r2 = factory->makeRoom(2);
        Door* aDoor = factory->makeDoor(r1, r2);
        
        aMaze->addRoom(r1);
        aMaze->addRoom(r2);
        
        r1->setSide(North, factory->makeWall());
        r1->setSide(East, aDoor);
        r1->setSide(South, factory->makeWall());
        r1->setSide(West, factory->makeWall());
        
        r2->setSide(North, factory->makeWall());
        r2->setSide(East, factory->makeWall());
        r2->setSide(South, factory->makeWall());
        r2->setSide(West, aDoor);
    }
    void play(){
        (aMaze->getvec()[0])->getSide(North)->enter();
        (aMaze->getvec()[0])->getSide(East)->enter();
        (aMaze->getvec()[0])->enter();
    }
    
    virtual Maze* makeMaze() const{ 
        return new Maze; 
    }
    virtual Room* makeRoom(int n) const{ 
        return new Room(n); 
    }
    virtual Wall* makeWall() const{ 
        return new Wall; 
    }
    virtual Door* makeDoor(Room* r1, Room* r2) const{ 
        return new Door(r1, r2); 
    }
    
private:
    Maze* aMaze;
};

int main(){

    // NormalMazeFactory
	MazeGame game1;
	game1.createMaze(new NormalMazeFactory);
	game1.play();

    cout << endl;

	// BombedMazeFactory
	MazeGame game2;
	game2.createMaze(new BombedMazeFactory);
	game2.play();

    return 0;
}