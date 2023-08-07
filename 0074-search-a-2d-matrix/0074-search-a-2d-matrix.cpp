class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(n*m)
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j]==target)return true;
        //     }
        // }
        // return false;
        
        //O(log(n*m)) optimized;
        for(int i=0;i<matrix.size();i++){
            int start=0,end=matrix[i].size()-1;
            while(start<=end){
                int mid=(start+end)/2;
                if(matrix[i][mid]==target)return true;
                else if(matrix[i][mid]>target)end=mid-1;
                else start=mid+1;
            }
        }
        return false;
    }
};