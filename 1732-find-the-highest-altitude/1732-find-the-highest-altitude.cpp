class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int mx=INT_MIN;
        int sum=0;
        for(int i=0;i<gain.size();i++){
            sum+=(gain[i]);
            mx=max(mx,sum);
        }
        if(mx<0)return 0;
        return mx;
    }
};