class Solution {
public:
//     void func(string digits, string c[], vector<string>&v,string st, int i){
//         //base case
//         if(i>=digits.length()){
//             v.push_back(st);
//             return;
//         }
//         int val=digits[i]-'0';
//         string value=c[val];
        
//         for(int idx=0;idx<value.length();idx++){
//             st.push_back(value[idx]);
//             func(digits,c,v,st,i+1);
//             st.pop_back();
//         }
        
//     }
//     vector<string> letterCombinations(string digits) {
//         string c[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//         vector<string>v;
//         if(digits.length()==0)return v;
//         string st="";
//         func(digits,c,v,st,0);
//         return v;
//     }
       void solveRec(string digits, string n_char[], vector<string>&ans, string st, int idx){
           if(idx>=digits.length()){
               ans.push_back(st);
               return;
           }
           string get_digit = n_char[digits[idx]-'0'];
           
           for(int i=0;i<get_digit.length();i++){
               st.push_back(get_digit[i]);
               solveRec(digits, n_char, ans, st, idx+1);
               st.pop_back();
           }
       }
       vector<string> letterCombinations(string digits){
           string n_char[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
           vector<string>ans;
           string st="";
           if(digits.length()==0)return ans;
           solveRec(digits, n_char, ans, st, 0);
           return ans;
       }
    
};