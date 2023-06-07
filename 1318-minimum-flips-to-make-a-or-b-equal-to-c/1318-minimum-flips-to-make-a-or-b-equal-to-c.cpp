class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res=0;
        while(a>0 || b>0 ||c>0){
            int bit_a= a&1;
            int bit_b= b&1;
            int bit_c= c&1;
            
            if((bit_a | bit_b)!=bit_c){
                if(bit_c==1)res++;
                else res+=bit_a+bit_b;
            }
            
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return res;
    }
};