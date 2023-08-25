class Solution {
public:
    int maxArea(vector<int>& height) {
       //brute force approach
        // int ans=INT_MIN;
        // for(int i=0;i<height.size();i++){
        //     for(int j=i+1;j<height.size();j++){
        //         int mx=(j-i)*(min(height[i],height[j]));
        //         ans=max(ans,mx);
        //     }
        // }
        // return ans;
        
        //optimized approroach
        int i=0;
        int j=height.size()-1;
        
        int mx=INT_MIN;
        
        while(i<=j){
            int min_height=min(height[i],height[j])*(j-i);
            mx=max(mx,min_height);
            if(height[i]<=height[j]){
                i++;
            }
            else j--;
        }
        return mx;
    }
};