#define ll longlong;
class Solution {
public:
    bool isValid(long long mid, vector<int>batteries, int n){
        long long total=0;
        for(int i=0;i<batteries.size();i++){
            total+=min(mid, 1LL*batteries[i]);
        }
        if(total>=mid*n)return true;
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low=1;
        long long high=0;
        for(int i=0;i<batteries.size();i++){
            high+=batteries[i];
        }
        high=high/n;
        long long ans=INT_MAX;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isValid(mid, batteries, n)==true){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};