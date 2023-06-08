class Solution {
public:
    bool func(vector<vector<char>>&b, string w, int i,int j, int ind){
        if(ind==w.size())return true;
        if(i<0||j<0||i>=b.size()||j>=b[0].size()||b[i][j]!=w[ind])return false;
        char temp=b[i][j];
        b[i][j]='0';
        bool x = func(b,w,i+1,j,ind+1);
        bool y = func(b,w,i-1,j,ind+1);
        bool z = func(b,w,i,j+1,ind+1);
        bool n = func(b,w,i,j-1,ind+1);
        b[i][j]=temp;
        return(x||y||z||n);
        //recursion
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]&&func(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
