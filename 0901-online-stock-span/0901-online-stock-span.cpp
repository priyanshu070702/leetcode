class StockSpanner {
public:
    StockSpanner() {
          
    }
    stack<pair<int,int>>st;  
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top().first<=price){
            auto it=st.top();
            st.pop();
            span+=it.second;
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */