class Solution {
public:
    int mySqrt(int x) {
        //linear search
        // int ans=1;
        // for(int i=0;i<=x;i++){
        //     if(i*i <= x){
        //         ans=i;
        //     }
        //     else break;
        // }
        // return ans;
        
        //binary search
        int ans=1;
        int low=0,high=x;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid <= (long long)x){
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