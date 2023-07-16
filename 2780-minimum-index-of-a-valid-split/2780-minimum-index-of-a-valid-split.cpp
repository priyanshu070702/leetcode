class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int>ump;
        for(int i=0; i<n; i++){
            ump[nums[i]]++;
            
        }
        int ele;
        int count=0;
        for(auto x:ump){
            if(x.second>n/2){
                ele= x.first;
                count= x.second;
                break;
            }
        }
        int left=0;
        for(int i=0; i<n-1; i++){
            if(nums[i]==ele){
                left++;
            }
            int right= count-left;
            if(left*2> i+1 && right*2> n-1-i){
                return i;
            }
            
        }
        return -1;
    }
};