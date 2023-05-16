map<int,int>mp;
    for(int i=0;i<size;i++){
        mp[a[i]]++;
    }
    int m=0,ans=0;
    for(auto t:mp){
       if(m<t.second){
           m=t.second;
           ans=t.first;
       }
    }
    if(m>(size/2))return ans;
    return -1;
