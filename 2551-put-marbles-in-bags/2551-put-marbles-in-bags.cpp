class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
       vector<long long>partitions; 
       for(int i=1;i<weights.size();i++){
          long long sum = weights[i] + weights[i-1];
           partitions.push_back(sum);
       }
       sort(partitions.begin(),partitions.end()); 
       int n = partitions.size();
       long long mx=0,mn=0;
       for(int i=0;i<k-1;i++)mn += partitions[i];
       for(int i=n-1;i>=n-k+1;i--)mx += partitions[i];
       return mx - mn;
    }
};