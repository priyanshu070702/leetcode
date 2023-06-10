class Solution {
// public:
//     int maxValue(int n, int index, int maxsum) {
//         long r=n-index-1;
//         long l=index;
//         long hi=maxsum;
//         long lo=1;
//         long mx=0;
//         //binary ongoing
//         while(lo<=hi){
//             long mid = (lo+hi)/2;
//             long sum=mid;
//             long ls=0,rs=0;
//             long m=mid-1;
//             if(r<=m){
//                 rs+=m*(m+1)/2 + (m-r)*(m-r+1)/2;
//             }
//             else{
//                 rs=m*(m+1)/2 + (r-m);
//             }
            
//             if(l<=m){
//                 rs+=m*(m+1)/2 + (m-l)*(m-l+1)/2;
//             }
//             else{
//                 ls=m*(m+1)/2 + (l-m);
//             }
//             sum+=ls+rs;
//             if(sum<=maxsum){
//                 mx=mid;
//                 lo=mid+1;
//             }
//             else{
//                 hi=mid-1;
//             }
//         }
//         return mx;
//     }
    public:
    long long c(long long n){
        return (n*(n+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        long long l=1,r=maxSum;
        long long ans=1;
        while(l<=r){
            long long mid=(l+r)/2;
            long long left = c(mid-1);
            if(index>mid-1){
                left += (index-mid+1);
            }
            else left -= c(mid-1-index);
            long long right = c(mid-1) ;
            if((n-1-index)>(mid-1)){
                right += (n-1-index-(mid-1));
            }
            else right -= c(mid-1-(n-1-index));
            if(left+right<=(maxSum-mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }   
        return ans;
    }
};