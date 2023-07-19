class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& points) {
        // stack<pair<int,int>>st;
        // vector<pair<int,int>>v(intervals.size());
        // for(int i=0;i<intervals.size();i++){
        //     v[i].first=intervals[i][0];
        //     v[i].second=intervals[i][1];
        // }
        // sort(v.begin(),v.end());
        // st.push({v[0].first,v[0].second});
        // for(int i=1;i<v.size();i++){
        //     int front=st.top().second;
        //     int tail=st.top().first;
        //     if(v[i].first>=front && v[i].second>front){
        //         st.push({v[i].first,v[i].second});
        //     }
        //     else{
        //         continue;
        //     }
        // }
        // return intervals.size()-st.size();
        sort(points.begin(),points.end());

        int  r = points[0][1], cnt = 0;

        for(int i = 1; i < points.size(); ++i)
        {
            if(r > points[i][0])
            {
                r = min(r, points[i][1]);
                cnt++; 
            }

            else r = points[i][1];
                    
        }
         return cnt; 
    }
};