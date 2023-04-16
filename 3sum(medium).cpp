class Solution {
public:

    int _(int a, int b, int c){
        if((a+b+c)==0)return 0;
        else if((a+b+c>0))return 1;
        else return -1;
    }
        
    vector<vector<int>> threeSum(vector<int> &nums){
            vector<vector<int>> ans;
            int n = nums.size();
            sort(nums.begin(), nums.end());

            for (int i = 0; i < n - 2; ++i)
            {
                int low = i + 1, high = n - 1;
                while (low < high)
                {
                    int a = nums[i], b = nums[low], c = nums[high];
                    if (_(a, b, c) == 0)
                    {
                        vector<int> v(3);
                        v[0] = a, v[1] = b, v[2] = c;
                       // sort(v.begin(), v.end());
                        ans.push_back(v);
                        while (high > low && nums[high] == nums[high - 1]) --high;
                        while (low < high && nums[low] == nums[low + 1]) ++low;
                        --high, ++low;
                    }
                    else if (_(a, b, c) == 1)
                        --high;
                    else
                        ++low;
                }
                while (i < n - 1 && nums[i] == nums[i + 1]) ++i;
            }

            return ans;

    }
};
