class MyHashSet {
public:
vector<int>v;
    MyHashSet() {
        v.resize(1000001,0);
    }
    
    void add(int key) {
        v[key]=1;
        // int cnt=0;
        // if(v.size()==0)v.push_back(key);
        // else{
        //     for(int i=0;i<v.size();i++){
        //         if(v[i]!=key){
        //             cnt++;
        //         }
        //     }
        //     if(cnt==v.size()){
        //         v.push_back(key);
        //     }
        // }
        // sort(v.begin(),v.end());
    }
    
    void remove(int key) {
        v[key]=0;
       // v.pop_back();
    }
    
    bool contains(int key) {
        if(v[key]==1)return 1;
        return 0;
        // for(int i=0;i<v.size();i++){
        //     if(v[i]==key)return true;
        // }
        // return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */