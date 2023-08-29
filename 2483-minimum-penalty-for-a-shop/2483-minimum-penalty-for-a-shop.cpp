class Solution {
public:
    int func(int i, string customers){
        int penalty=0;
        int cnt=0;
        if(i==0){
            for(int j=0;j<customers.length();j++){
                if(customers[j]=='Y')penalty++;
            }
        }
        else{
            for(int j=0;j<customers.length();j++){
                if(cnt<i){
                   if(customers[j]=='Y'){
                       cnt++;
                       continue;
                   }
                   else if(customers[j]=='N'){
                       cnt++;
                       penalty++;
                   }
                }
                else{
                   if(customers[j]=='Y')penalty++;
                }
            }
        }
        return penalty;
    }
    int bestClosingTime(string customers) {
        // int min_penalty=INT_MAX;
        // int index=0;
        // int n=customers.length();
        // for(int i=0;i<=n;i++){
        //     int find=func(i,customers);
        //     if(find<min_penalty){
        //         min_penalty=min(min_penalty,find);
        //         index=i;
        //     }
        // }
        // return index;
        
        int n = customers.size();
        vector<int> prefix(n + 1), suffix(n + 1);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (customers[i] == 'N' ? 1 : 0);
        }

        for (int i = n - 1; 0 <= i; i--) {
            suffix[i] = suffix[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int current = INT_MAX, answer = n;
        for (int i = 0; i <= n; i++) {
            int penalty = suffix[i] + prefix[i];
            if (penalty < current) {
                current = penalty;
                answer = i;
            }
        }
        return answer;
    }
};