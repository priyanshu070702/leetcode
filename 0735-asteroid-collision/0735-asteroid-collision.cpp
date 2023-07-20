// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         vector<int>ans;
//         int n=asteroids.size();
//         stack<int>st;
//         for(int i=n-1;i>=0;i--){
//             if(st.empty()){
//                 st.push(asteroids[i]);
//             }
//             else{
//                 if((st.top()>0 && asteroids[i]<0) || (st.top()<0 && asteroids[i]>0)){
//                     if((st.top()>0 && asteroids[i]<0)){
//                         int store=st.top();
//                         int comp=asteroids[i];
//                         st.pop();
//                         if(abs(comp)>abs(store)){
//                             st.push(comp);
//                         }
//                         else if(abs(comp)==abs(store)) continue;
//                         else st.push(store);
//                     }
//                     else if((st.top()<0 && asteroids[i]>0)){
//                         int store=st.top();
//                         int comp=asteroids[i];
//                         st.pop();
//                         if(abs(comp)<abs(store)){
//                             st.push(store);
//                         }
//                         else if(abs(comp)==abs(store)) continue;
//                         else st.push(comp);
//                     }
//                 }
//                 else if((st.top()>0 && asteroids[i]>0) || (st.top()<0 && asteroids[i]<0)){
//                     st.push(asteroids[i]);
//                 }
//             }
//         }
//         while(!st.empty()){
//             ans.push_back(st.top());
//             st.pop();
//         }
//         return ans;
//     }
// };

class Solution {
public:
    
	// if 2 consecutive asteroids are of same parity, they will keep moving in same direction without collision
    bool sameParity(int a, int b){
        if((a<0 && b<0) || (a>0 && b>0)) return true;
        return false;
    }
    
    vector<int> asteroidCollision(vector<int>& v) {
        int n=v.size();
        
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(st.size()==0 || sameParity(st.top(),v[i]) || (st.top()<0 && v[i]>0)){
                st.push(v[i]); // no collision
            }else{
                while(st.size()>0 && st.top()>0 && st.top() < abs(v[i])) st.pop(); // currect asteroid destroying existing
                
                if(st.size()==0 || st.top()<0){
                    st.push(v[i]);
                }else if(st.top() == abs(v[i])){
                    st.pop();  // both asteroids get destroyed
                }
            }
        }
        
        vector<int> ans;
        while(st.size()>0){
            int x=st.top();
            ans.push_back(x);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};