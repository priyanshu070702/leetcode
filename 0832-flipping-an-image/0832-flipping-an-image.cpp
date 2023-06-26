class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<n;i++){
            int j=0,k=m-1;
            while(j<k){
                swap(image[i][j],image[i][k]);
                j++;
                k--;
            }
            for(int l=0;l<m;l++){
                if(image[i][l]==1)image[i][l]=0;
                else if(image[i][l]==0)image[i][l]=1;
            }
        }
        return image;
    }
};