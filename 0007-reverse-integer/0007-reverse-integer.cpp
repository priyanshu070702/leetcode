class Solution {
public:
    int reverse(int x) {
        int a=x;
        long long sum=0;
        while(a!=0){
            sum=(sum*10)+(a%10);
            a=a/10;
        }
        if(sum>=pow(2,31) || sum< -(pow(2,31)))return 0;
        return sum;
    }
};