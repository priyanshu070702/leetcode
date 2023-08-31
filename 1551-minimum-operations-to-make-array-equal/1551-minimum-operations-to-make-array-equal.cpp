class Solution {
public:
    int minOperations(int n) {
        // vector<int>v(n);
        // for(int i=0;i<n;i++){
        //     v[i]=(2*i)+1;
        // }
        // int i=0,j=n-1;
        int sum=0;
        // while(i<=j){
        //     sum+=(v[j]-v[i])/2;
        //     i++;j--;
        // }
        // return sum;
        if(n%2!=0){
            for(int i=1;i<=n;i++){
                if(i%2==0)sum+=i;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(i%2!=0)sum+=i;
            }
        }
        return sum;
    }
};