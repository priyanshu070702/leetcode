class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // for(int i=0;i<arr.size();i++){
        //     if(i==0 && arr[i+1]<arr[i])return i;
        //     else if(i==arr.size()-1 && arr[i-1]<arr[i])return i;
        //     else if(arr[i]>arr[i+1] && arr[i]>arr[i-1])return i;
        // }
        // return -1;
        
        //optimized approach
        int s=1,e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])return mid;
            else if(arr[mid]<arr[mid+1])s=mid+1;
            else e=mid-1;
        }
        return -1;
    }
};