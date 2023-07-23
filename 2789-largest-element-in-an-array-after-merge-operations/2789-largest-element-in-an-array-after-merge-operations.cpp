class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        stack<long long>st;
        int i=nums.size()-1;
        while(i>=0){
            if(st.empty()){
                st.push(nums[i]);
            }
            else if(st.top()<nums[i]){
                st.push(nums[i]);
            }
            else if(nums[i]<=st.top()){
                long long store=st.top();
                st.top();
                st.push(store+nums[i]);
            }
            i--;
        }
        long long mx=INT_MIN;
        while(!st.empty()){
            mx=max(mx,st.top());
            st.pop();
        }
        return mx;
    }
};