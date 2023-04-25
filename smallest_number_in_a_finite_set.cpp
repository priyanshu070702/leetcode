class SmallestInfiniteSet {
public:
    map<int,int> pri;
    SmallestInfiniteSet() {
        for(int i =1;i<=1000;i++) pri[i]++;
    }
    
    int popSmallest() {
        int a = pri.begin()->first;
        pri.erase(a);
        return a;
    }
    
    void addBack(int num) {
        pri[num]++;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
