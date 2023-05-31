class UndergroundSystem {
public:
    map<int,pair<string,double>>m;
    map<string,pair<double,double>>ans;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        stationName+='-'+m[id].first;
        if(ans.find(stationName)==ans.end()){
            ans[stationName]={1,t-m[id].second};
        }
        else{
            ans[stationName].first+=1;
            ans[stationName].second+=t-m[id].second;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        endStation+='-'+startStation;
        if(ans.find(endStation)!=ans.end()){
            return ((double)ans[endStation].second/(double)ans[endStation].first);
        }
        return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */