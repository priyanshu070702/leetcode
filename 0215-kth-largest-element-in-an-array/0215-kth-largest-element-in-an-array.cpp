class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>p;
        int n=nums.size();
        for(int i=0;i<n;i++){
            p.push(nums[i]);
        }
        int ans=0;
        for(int i=0;i<k;i++){
            ans=p.top();
            p.pop();
        }
        return ans;
        // int max=INT_MIN;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]>max)max=nums[i];
        // }
        // int A[max+1];
        // for(int i=0;i<max+1;i++){
        //     A[i]=0;
        // }
        // for(int i=0;i<n;i++){
        //     A[nums[i]]++;
        // }
        // int i=0;
        // vector<int>a;
        // while(i<max+1){
        //     if(A[i]>0){
        //        a.push_back(A[i]);
        //        A[i]--;
        //     }
        //     else i++;
        // }
        // return a[n];
    }
};