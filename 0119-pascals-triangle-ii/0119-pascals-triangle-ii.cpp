class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>pas;
        vector<int>v;
        for(int i=0;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || i==j){
                    v.push_back(1);
                }
                else{
                    v.push_back(pas[i-1][j]+pas[i-1][j-1]);
                }
            }
            pas.push_back(v);
            if(i==rowIndex)break;
            v.clear();
        }
        return v;
    }
};