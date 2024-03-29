

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
       stack<char>s;
       
        
        for(int i = 0;i<x.length();i++){
            
            //inital element to push
            if(s.empty())
                s.push(x[i]);
            //when pairs match
            else if(x[i]=='('||x[i]=='{'||x[i]=='[')
                s.push(x[i]);
            else if((x[i]==')' and s.top()=='(')or(x[i]=='}' and s.top()=='{' )or(x[i]==']' and s.top()=='[' ))
                s.pop();
           //when the pairs don't match
           else
                return false;
        
        }
        
        
        return s.empty();
    }

};
