class Solution {
public:
    double average(vector<int>& salary) {
        int mx=INT_MIN,mn=INT_MAX;
        int sum=0.00000;
        for(int i=0;i<salary.size();i++){
            sum+=salary[i];
            mx=max(salary[i],mx);
            mn=min(salary[i],mn);
        }
        double ans=(double)sum-((double)mx+(double)mn);
        return ans/(salary.size()-2);

    }
};
