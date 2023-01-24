class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> answer(numRows,"");
        if(numRows==1) return s;
        int index = 0;
        int ptr = 0;
        int size = s.size();
        while(index < size){
            int i;
            for(i=index;i<index+numRows;i++){
                if(i<=size-1){
                    answer[ptr] += s[i];
                    ptr++;
                }else break;
            }
            index = i; ptr-=2;
            while(index<size && ptr>0){
                answer[ptr] += s[index];
                index++;
                ptr--;
            }
        }
        string final_string = "";
        for(auto item:answer){
            cout<<item<<" ";
            final_string += item;
        }
        
        return final_string;
    }
};
