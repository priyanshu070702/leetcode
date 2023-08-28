class MyStack {
public:
    MyStack() {

    }
    queue<int> q1;
    queue<int> q2;
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        // Move elements from q1 to q2, except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Get the last element from q1
        int get = q1.front();
        q1.pop();
        
        // Swap q1 and q2
        swap(q1, q2);
        
        return get;
    }
    
    int top() {
        // Move elements from q1 to q2, except the last one
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Get the last element from q1
        int get = q1.front();
        q1.pop();
        
        // Move the element to q2
        q2.push(get);
        
        // Swap q1 and q2
        swap(q1, q2);
        
        return get;
    }
    
    bool empty() {
       return q1.empty() && q2.empty();
    }
};
