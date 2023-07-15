class Solution {
public:
    
    vector<vector<int>> memo;
    
    // searching for 1st next non-conflicting event 
    int search(vector<vector<int>>& events, int end, int idx){
        int n=events.size();
        int l=idx, r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            int start=events[m][0];
            if(start>end){
                r=m;
            }else{
                l=m+1;
            }
        }
        
        return ((l<n && events[l][0]>end) ? l:-1);
    }
    
    int profit(vector<vector<int>>& events, int n, int k, int idx){
        if(idx==n || k==0) return 0;
        
        if(memo[idx][k]!=-1) return memo[idx][k];
        
        int maxval=0;
        
        // not attend
        maxval = profit(events, n, k, idx+1);
        
        // attend event
        int next_possible_idx = search(events, events[idx][1], idx+1);
        maxval = max(maxval, events[idx][2] + (next_possible_idx==-1 ? 0:profit(events,n,k-1,next_possible_idx)));
        
        return memo[idx][k]=maxval;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        
        memo.resize(n,vector<int>(k+1,-1));
        
        return profit(events,n,k,0);
    }
};