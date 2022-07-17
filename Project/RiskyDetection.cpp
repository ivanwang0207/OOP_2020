#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

//從database取得工作人員和危險區域的資料 
class GetDataBase{
public:
    GetDataBase() = default;
    virtual void ReadDataBase() = 0;
    virtual ~GetDataBase() = default;
private:
    
};

class GetWorkerRiskyTable : GetDataBase{
private:
    map<string,tuple<int,double>> RiskTable; //工作項目, (危險指數, 危險範圍)
public:
    virtual void ReadDataBase(){   
        
        vector<vector<string>> matrix;
        fstream file;
        file.open("WorkerRiskyTable.csv");
        string line;
        while (getline(file, line,'\n'))  //讀檔讀到跳行字元
        {
            istringstream templine(line); // string 轉換成 stream
            string data;
            vector<string> temp;
            while (getline(templine, data,',')) //讀檔讀到逗號
            {
                temp.push_back(data.c_str()); 
            }
            matrix.push_back(temp);
        }
        file.close();
    };

    virtual ~GetWorkerRiskyTable(){
        //cout << "WorkerRiskyTable is deleted" << endl;
    };
    GetWorkerRiskyTable(){ //之後要用database寫入
        RiskTable.insert(pair<string,tuple<int,double>>("SteelbarMan",make_tuple(1,1.5))); //鋼筋搬運工人
        RiskTable.insert(pair<string,tuple<int,double>>("MakeupMan",make_tuple(2,2.5))); //補料工人
        RiskTable.insert(pair<string,tuple<int,double>>("VanDriver ",make_tuple(3,3.5))); //開貨車工人
    }
    int GetRiskyIndex(string t){
        int temp;
        auto iter = RiskTable.find(t);
        if(iter != RiskTable.end())
            temp =  get<0>(iter->second);
        return temp;        
    }
    double GetRiskyRange(string t){
        int temp;
        auto iter = RiskTable.find(t);
        if(iter != RiskTable.end())
            return get<1>(iter->second);
        return temp;
    }
};

class GetRegionRiskyTable : GetDataBase{
private:
    map<string,int> RiskTable; //危險區域, 危險指數
public:
    virtual void ReadDataBase(){};
    virtual ~GetRegionRiskyTable(){
        //cout << "RegionRiskyTable is deleted" << endl;
    };
    GetRegionRiskyTable(){ //之後要用database寫入
        RiskTable.insert(pair<string,int>("HighRiseBuilding",3)); //人為環境:高樓
        RiskTable.insert(pair<string,int>("UndergroundStructure",3)); //人為環境:地下結構
        RiskTable.insert(pair<string,int>("TemporaryStructure",5)); //施工環境:臨時建物
        RiskTable.insert(pair<string,int>("ElecEquip",5)); //施工環境:機電設備
        RiskTable.insert(pair<string,int>("MakeupArea",4)); //施工環境:堆積區
    }
    int GetRiskyIndex(string t){
        int temp;
        auto iter = RiskTable.find(t);
        if(iter != RiskTable.end())
            temp =  iter->second;
        return temp;        
    }
};

class GetWorkersData : GetDataBase{
public:
    GetWorkersData() = default;
    virtual ~GetWorkersData(){
        cout << "WorkersData is deleted!" << endl;
    }
    virtual void ReadDataBase(){ //之後要用database寫入
        workers.push_back(make_tuple("Sam","SteelbarMan",12.1,23.7,18,3));
        workers.push_back(make_tuple("Samantha","MakeupMan",-2.8,0.6,22,5));
        cout << "reading workersData successfully!" << endl;
    }
    vector<tuple<string, string, double, double, int, int>> getWorkers() const{
        return workers;
    }
private:
    vector<tuple<string, string, double, double, int, int>> workers; //人員名稱, 從事項目, x, y, age, 資歷
};

class GetRegionsData : GetDataBase{
public:
    GetRegionsData() = default;
    virtual ~GetRegionsData(){
        cout << "RegionsData is deleted!" << endl;
    }
    virtual void ReadDataBase(){ //之後要用database寫入
        Regions.push_back(make_tuple("TemporaryStructure",12.3,23.1,8,5));
        Regions.push_back(make_tuple("UndergroundStructure",1.2,2.1,8,3));
        cout << "reading regionsData successfully!" << endl;
    }
    vector<tuple<string, double, double, double, double>>getRegions() const{
        return Regions;
    }
private:
    vector<tuple<string, double, double, double, double>> Regions; //風險區名稱, x, y, W寬度, L長度
};

//工地現場的物件: 工人&危險區域
class ConstructionSite { 
public:
    ConstructionSite() = default;
    virtual int getIndex() = 0;
    virtual string getName() = 0;
    virtual tuple<double, double> getLocation(){return make_tuple(x,y);}
    virtual tuple<double, double> getLW(){return make_tuple(width,length);}
        virtual tuple<tuple<double, double>,tuple<double, double>> getRange(){
        double x_min = x - width/2;
        double x_max = x + width/2;
        double y_min = y - length/2;
        double y_max = y + length/2;   
        return make_tuple(make_tuple(x_min,y_min),make_tuple(x_max,y_max));  
    }
protected:
    double x;
    double y;
    double width;
    double length;
    int index;
};

class Worker : public ConstructionSite  { 
public:
    Worker(tuple<string, string, double, double, int, int> info):ConstructionSite() {
        workerName = get<0>(info);
        item = get<1>(info);
        x = get<2>(info);
        y = get<3>(info);
        age = get<4>(info);
        seniority = get<5>(info);
        RiskTable = new GetWorkerRiskyTable;
        //RiskTable->ReadDataBase();
        index = RiskTable->GetRiskyIndex(item);
        width = length = RiskTable->GetRiskyRange(item);
    }
    virtual string getName(){return workerName;}
    virtual string getItem(){return item;}
    virtual int getIndex(){return index;}
    virtual ~Worker(){
        delete RiskTable;
        cout << "Worker: " << this->getName() <<" is deleted" << endl;
    }
protected:
    GetWorkerRiskyTable* RiskTable;
    string workerName;
    string item;
    int age;
    int seniority;
};

class Region : public ConstructionSite  { 
public:
    Region(tuple<string, double, double, double, double> info):ConstructionSite() {
        regionName = get<0>(info);
        x = get<1>(info);
        y = get<2>(info);
        width = get<3>(info);
        length = get<4>(info);
        RiskTable = new GetRegionRiskyTable;
        index = RiskTable->GetRiskyIndex(regionName);
    }
    virtual string getName(){return regionName;}
    virtual int getIndex(){return index;}
    virtual ~Region(){
        delete RiskTable;
        cout << "Region: " << this->getName() <<" is deleted" << endl;
    }

protected:
    GetRegionRiskyTable* RiskTable;
    string regionName;
};

//工地: 用來存取創建後的工人和區域
class Site{
public:
    Site() = default;
    virtual ~Site(){
        for(auto& w:v_worker)
            delete w;
        for(auto& r:v_region)
            delete r;
        cout << "Site is deleted!" << endl;
    };

    void addWorker(Worker* w){
        v_worker.push_back(w);
    }
    vector<Worker*> get_workers() const{
        return v_worker;
    }    
    void addRegion(Region* r){
        v_region.push_back(r);
    }
    vector<Region*> get_regions() const{
        return v_region;
    }
private:
    vector<Worker*> v_worker;
    vector<Region*> v_region;
};

//abstract factory
class NormalSiteFactory {
public:
    NormalSiteFactory(){}
    virtual Site* makeSite() const{
        return new Site;
    }
    virtual Worker* makeWorker(tuple<string, string, double, double, int, int> w_info) const{
        return new Worker(w_info);
    }
    virtual Region* makeRegion(tuple<string, double, double, double, double> r_info) const{
        return new Region(r_info);
    }

};

class SpecialSiteFactory : public NormalSiteFactory{
    //ex 工人的年紀和資歷亦會影響到施工的維安狀況
};

//detection process 
class TestDetection{
public:
    TestDetection(){}
    ~TestDetection(){
        cout << "-----------Destructor------------" << endl;
        delete aSite;
        delete workers;
        delete regions;
        cout << "Detection is deleted!" << endl;
    }
    void CreateDetection(NormalSiteFactory* factory){
        cout << "-----------Starting reading database and creating objects------------" << endl;
        workers = new GetWorkersData; //Get data from DB
        regions = new GetRegionsData;
        
        workers->ReadDataBase();
        regions->ReadDataBase();

        aSite = factory->makeSite();

        for(auto worker : workers->getWorkers()){
            Worker* w = factory->makeWorker(worker);
            aSite->addWorker(w);
        }

        for(auto region : regions->getRegions()){
            Region* r = factory->makeRegion(region);
            aSite->addRegion(r);
        }
        cout << "Creating sites, workers and regions successfully!\n" << endl;
    }

    void StartDetection(){
        cout << "-----------Starting detecting risky events------------" << endl;
        auto v_workers = aSite->get_workers();
        auto v_regions = aSite->get_regions();
        double dx, dy, dw, dh, sw, sh;
        
        for(auto w_iter = v_workers.begin(); w_iter != v_workers.end(); ++w_iter){            
            auto worker_LW = (*w_iter)->getLW();
            auto worker_C = (*w_iter)->getLocation();          
            
            for(auto r_iter = v_regions.begin(); r_iter != v_regions.end(); ++r_iter ){                                             
                auto region_LW = (*r_iter)->getLW(); 
                auto region_C = (*r_iter)->getLocation(); 
                dx = abs(get<0>(region_C) - get<0>(worker_C));
                dy = abs(get<1>(region_C) - get<1>(worker_C));
                dw = abs(get<0>(region_LW) - get<0>(worker_LW));
                dh = abs(get<1>(region_LW) - get<1>(worker_LW));
                sw = abs(get<0>(region_LW) + get<0>(worker_LW));
                sh = abs(get<1>(region_LW) + get<1>(worker_LW));

                if (dx < dw / 2 && dy < dh / 2) {
                    cout << (*w_iter)->getName() << " location=(" << get<0>((*w_iter)->getLocation()) << "," << get<1>((*w_iter)->getLocation()) << ")"<<" is inside " << (*r_iter)->getName() << " Range=(min("<<get<0>(get<0>((*r_iter)->getRange())) << "," << get<1>(get<0>((*r_iter)->getRange())) << "),max(" << get<0>(get<1>((*r_iter)->getRange())) << "," << get<1>(get<1>((*r_iter)->getRange())) << ")), and the risky index is: " << (*w_iter)->getIndex() * (*r_iter)->getIndex() << endl;
			        //cout << "r2 is inside r1" << endl;
		        } 
                else if (dx > sw / 2 || dy > sh / 2) {
                    //cout << (*w_iter)->getName() <<" is safe " << endl;
			        //cout << "r2 does not overlap r1" << endl;
		        } 
                else {
                    cout << (*w_iter)->getName() << " location=(" << get<0>((*w_iter)->getLocation()) << "," << get<1>((*w_iter)->getLocation()) << ")"<<" is approaching " << (*r_iter)->getName() << " Range=(min("<<get<0>(get<0>((*r_iter)->getRange())) << "," << get<1>(get<0>((*r_iter)->getRange())) << "),max(" << get<0>(get<1>((*r_iter)->getRange())) << "," << get<1>(get<1>((*r_iter)->getRange())) << ")), and the risky index is: " << (*w_iter)->getIndex() * (*r_iter)->getIndex() << endl;
			        //cout <<  "r2 overlaps r1" << endl;
		        }
            }
        }
        cout << "\n";
    }   
private:
    Site* aSite;
    GetWorkersData* workers;
    GetRegionsData* regions;
};

int main(){
        
    TestDetection detection;
    NormalSiteFactory* nfactory = new NormalSiteFactory;
    detection.CreateDetection(nfactory);
    detection.StartDetection();
    delete nfactory;

    return 0;
}
