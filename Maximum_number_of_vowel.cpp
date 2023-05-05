 bool check(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ans=0;
        int count=0;
        for(int i=0;i<k;i++){
            if(check(s[i]))count++;
        }
        ans=count;
        int i=0,j=k;
        while(j<s.size()){
            if(check(s[j]))count++;
            if(check(s[i]))count--;
            ans=max(ans,count);
            j++;
            i++;
        }
        return ans;
    }
