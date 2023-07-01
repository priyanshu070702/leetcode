class Solution {
public:
    int solveRec(vector<int>&cookies, int index,int k,vector<int>&A){
       if(index>=cookies.size()){
           int ans=0;
           for(auto it:A){
               ans=max(ans,it);
           }
           return ans;
       }
       int mn=INT_MAX;   

           for(int i=0;i<A.size();i++){
               A[i]+=cookies[index];
               mn=min(mn,solveRec(cookies,index+1,k,A));
               A[i]-=cookies[index];
           }
           return mn;
       }
       
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>A(k);
        return solveRec(cookies,0,k,A);    
    }
};