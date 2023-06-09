class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int>v;
        vector<vector<int>>pas;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || i==j){
                    v.push_back(1);
                }
                else{
                    v.push_back(pas[i-1][j]+pas[i-1][j-1]);
                }
            }
            pas.push_back(v);
            v.clear();
        }
        return  pas;
    }
};