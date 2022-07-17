#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ParaWeatherData;

//abstract observer
class ObserverInterface {
public:
    virtual void update() = 0;
    virtual void show() = 0;
};

// keep track of the current temperature
class ConcreteObserverCurrent : public ObserverInterface {
public:
    ConcreteObserverCurrent() {}
    ConcreteObserverCurrent(ParaWeatherData&);
    virtual void update() {
        auto pos = (*history_temp).end() - 1;
        current_temp = *pos;
    }
    virtual void show() {
        cout << "_____CurrentConditions_______" << endl;
        cout << "temperature: " << current_temp << endl;
        cout << "_____________________________" << endl << endl;
    }
private:
    vector<double>* history_temp;
    double current_temp;
};

ConcreteObserverCurrent::ConcreteObserverCurrent(ParaWeatherData& data) {
    data.registerOb(this);
    history_temp = data.getVec();
}

// keep track of the max temperature
class ConcreteObserverStatistics : public ObserverInterface {
public:
    ConcreteObserverStatistics(ParaWeatherData&);
    ConcreteObserverStatistics() = default;
    ~ConcreteObserverStatistics() = default;
    virtual void update() {
        max_temp = *max_element((*statistics).begin(), (*statistics).end());
    }
    virtual void show()  {
        cout << "_____TemperatureStatistics___" << endl;
        cout << "highest temperature: " << max_temp << endl;
        cout << "_____________________________" << endl << endl;
    }
private:
    vector<double>* statistics;
    double max_temp;
};

ConcreteObserverStatistics::ConcreteObserverStatistics(ParaWeatherData& data) {
    data.registerOb(this);
    statistics = data.getVec();
}

class WeatherDataInterface { //abstract subject
public:
    WeatherDataInterface() = default;
    virtual void registerOb(ObserverInterface* ob) = 0;
    virtual void removeOb(ObserverInterface* ob) = 0;
    virtual void notifyOb() = 0;
protected:
    vector<ObserverInterface*> observers;
};

class ParaWeatherData : public WeatherDataInterface {
public:
    virtual void registerOb(ObserverInterface* ob) { observers.push_back(ob); }
    virtual void removeOb(ObserverInterface* ob) {
        auto pos = find (observers.begin(), observers.end(), ob);
        if (pos != observers.end())
            observers.erase(pos);
    }
    virtual void notifyOb() {
        for (auto ob : observers) {
            ob->update();
            ob->show();
        }
        cout << endl;
    }
    void sensorDataChange(double temp) {
        tempVec.push_back(temp);
        notifyOb();
    }
    vector<double>* getVec() { return &tempVec; }
private:
    vector<double> tempVec;
};


int main(){
    ParaWeatherData* wdata = new ParaWeatherData;
    ConcreteObserverCurrent* current = new ConcreteObserverCurrent(*wdata);
    ConcreteObserverStatistics* statistcs = new ConcreteObserverStatistics(*wdata);

    wdata->sensorDataChange(28.2);
    wdata->sensorDataChange(30.12);

    wdata->sensorDataChange(26);

    wdata->removeOb(current);

    wdata->sensorDataChange(35.9);
    wdata->sensorDataChange(40);

    delete statistcs;
    delete current;
    delete wdata;

    return 0;
}