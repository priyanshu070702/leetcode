class Solution {
public:
    bool isHappy(int n) {
        int temp=n;
        while(temp>=10){
            int st=temp;
            int sum=0;
            while(st!=0){
                int rem=st%10;
                sum+=(rem*rem);
                st/=10;
            }
            temp=sum;
        }
        if(temp==1 ||temp==7)return true;
        return false;
    }
};