class Solution {
public:
    bool isFascinating(int n) {
        int a2=2*n;
        int a3=3*n;
        
        int cna=0,cnb=0;
        int a22=a2;
        int a33=a3;
        while(a22!=0){
            cna++;
            a22=a22/10;
            //cna++;
        }
        while(a33!=0){
            cnb++;
            a33=a33/10;
            //cnb++;
        }
        long long res=(long long)n*(pow(10,(cna)))+a2;
        res=res*(pow(10,(cnb)))+a3;
        vector<int>v(10,0);
        long long st=res;
        while(res!=0){
            int temp=res%10;
            v[temp]++;
            res=res/10;
        }
        for(int i=1;i<10;i++){
            if(v[i]!=1)return false;
        }
        return true;
    }
};