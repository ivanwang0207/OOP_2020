#include <iostream>

using namespace std;

/*the Command interface*/
class Command {
public:
	virtual void execute()=0;
};

/*Receiver class*/
class Light {
public:
	Light() {}
	void turnOn() { cout << "The light is on" << endl;}
	void turnOff() { cout << "The light is off" << endl;}
	void blink() { cout << "The light is blinking" << endl; }
};

class FlipUpCommand : public Command{
private:
	Light* L;
public:
	FlipUpCommand(Light* light){ L = light;}
	virtual void execute(){L->turnOn();}
};

class FlipDownCommand : public Command{
private:
	Light* L;
public:
	FlipDownCommand(Light* light){ L = light;}
	virtual void execute(){L->turnOff();}
};

class BlinkCommand : public Command{
private:
	Light* L;
public:
	BlinkCommand(Light* light){ L = light;}
	virtual void execute(){L->blink();}
};

class ComboCommand : public Command{
	Light* L;
public:
	ComboCommand(Light* light){ L = light;}
	virtual void execute(){L->turnOn();L->turnOff();L->blink();L->turnOn();L->turnOff();L->blink();}
};


class Switch{
private:
	FlipUpCommand* up;
	FlipDownCommand* down;
	Command* spe;
public:
	void setFlipUpCommand(FlipUpCommand* up) {this->up = up;}
	void setFlipDownCommand(FlipDownCommand* down) {this->down = down;}
	void setSpecialCommand(Command* spe){this->spe = spe;}
	void flipUp(){up->execute();}
	void flipDown(){down->execute();}
	void special(){spe->execute();}
};

/*The test class or client*/
int main(){
    Light lamp;
    FlipUpCommand switchUp(&lamp);
    FlipDownCommand switchDown(&lamp);
    BlinkCommand blink(&lamp);
    ComboCommand combo(&lamp);

    cout << "Switch 1:" << endl;
    Switch s1;
    s1.setFlipUpCommand(&switchUp);
    s1.setFlipDownCommand(&switchDown);
    s1.setSpecialCommand(&blink);
    s1.flipUp();
    s1.flipDown();
    s1.special();
	
    cout << "Switch 2:" << endl;
    Switch s2;
    s2.setSpecialCommand(&combo);
    s2.special();

    return 0;
}
