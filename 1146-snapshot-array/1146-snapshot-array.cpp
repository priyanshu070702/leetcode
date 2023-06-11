class SnapshotArray {
public:
  unordered_map<int, map<int, int>> mp;
    int s = 0;
    SnapshotArray(int length) {
        for(int i = 0; i < length; i++){
            map<int, int> tmp;
            tmp[0] = 0;
            mp[i] = tmp;
        }
    }

    void set(int index, int val) {
        mp[index][s] = val;
    }
    
    int snap() {
        return s++;
    }
    
    int get(int index, int snap_id) {
        auto i = mp[index].upper_bound(snap_id); 
        i--;
        return i -> second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */