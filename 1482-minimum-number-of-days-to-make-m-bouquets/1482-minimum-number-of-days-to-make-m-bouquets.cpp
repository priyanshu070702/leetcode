class Solution {
public:
    bool isBloomed(int day, vector<int>bloomDay, int m, int k){
        int cnt=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)bloomDay[i]=0;
        }
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]==0){
                cnt++;
            }
            else{
                ans+=(cnt/k);
                cnt=0;
            }
        }
        ans+=(cnt/k);
        if(ans>=m)return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        long long n=bloomDay.size();
        if((long long)m*k>n)return -1; //impossible case
        for(int i=0;i<n;i++){
            mn=min(mn,bloomDay[i]);
            mx=max(mx,bloomDay[i]);
        }
        int ans=-1;
        while(mn<=mx){
            int mid=(mn+mx)/2;
            if(isBloomed(mid,bloomDay,m,k)==1){
                ans=mid;
                mx=mid-1;
            }
            else mn=mid+1;
        }
        return ans;
    }
};