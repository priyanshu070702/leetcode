class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans=0;
        for(int i=1;i<=mainTank;i++){
            if(i%5==0 && additionalTank>0){
                ans+=10;
                mainTank++;
                additionalTank--;
            }
            else{
                ans+=10;
            }
        }
        return ans;
    }
};