class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //brute force
        // vector<pair<int,int>>v;
        // for(int i=0;i<cost.size();i++){
        //     v.push_back({nums[i],cost[i]});
        // }
        // sort(v.begin(),v.end());
        // int n=nums.size();
        // int mn=INT_MAX;
        // for(int i=0;i<n;i++){
        //     int sum;
        //     int price=0;
        //     for(int j=0;j<n;j++){
        //         sum=abs(v[i].first-v[j].first);
        //         price+=sum*(v[j].second);
        //     }
        //     mn=min(mn,price);
        // }
        // return mn;
        
        //optimized
        int n = nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        long long total_ele=0;
        for(int i=0;i<n;i++){
            total_ele+=1L * v[i].second;
        }
        long long median, total=0;
        for(int i=0;i<n && total<(total_ele+1)/2;i++){
            total+=1L * v[i].second;
            median=v[i].first;
        }
        long long sum;
        long long res=0;
        for(int i=0;i<n;i++){
            int sum=1L*abs(median-v[i].first);
            res+=sum*1L*(v[i].second);
        }
        return res;
    }
};