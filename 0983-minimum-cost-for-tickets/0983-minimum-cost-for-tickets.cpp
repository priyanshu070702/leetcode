class Solution {
public:
    
    int ticketRec(int n,vector<int>&days,vector<int>&costs,int index){
        if(index>=n){
            return 0;
        }
        //pass 1
        int pass1=costs[0]+ticketRec(n,days,costs,index+1);
        
        //pass2
        int i;
        for( i=index;i<n && days[i]<days[index]+7;i++);
        int pass2=costs[1]+ticketRec(n,days,costs,i);
        
        //pass2
        for(i=index;i<n && days[i]<days[index]+30;i++);
        int pass3=costs[2]+ticketRec(n,days,costs,i);
        
        return min(pass1,min(pass2,pass3));
    }
    
    
    int ticketMemo(int n,vector<int>&days,vector<int>&costs,int index, vector<int>&dp){
         if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        //pass 1
        int pass1=costs[0]+ticketMemo(n,days,costs,index+1,dp);
        
        //pass2
        int i;
        for( i=index;i<n && days[i]<days[index]+7;i++);
        int pass2=costs[1]+ticketMemo(n,days,costs,i,dp);
        
        //pass2
        for(i=index;i<n && days[i]<days[index]+30;i++);
        int pass3=costs[2]+ticketMemo(n,days,costs,i,dp);
        
        dp[index] = min(pass1,min(pass2,pass3));
        return dp[index];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        //return ticketRec(n,days,costs,0);
        vector<int>dp(n,-1);
        return ticketMemo(n,days,costs,0,dp);
    }
};