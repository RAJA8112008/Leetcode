class MinStack {
public:
  stack<int>st;
  stack<int>mini;
    MinStack() {
        
    }
    void push(int value) {
       st.push(value);
       //updatee mini 
       if(mini.empty()){
         mini.push(value);
       }else{
           mini.push(min(mini.top(),value));
       }
    }
    void pop() {
        if(!st.empty()){
             int val=st.top();
             st.pop();
             mini.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            int val=st.top();
            return val;
        }
      return 0;
    }
    int getMin() {
        if(!mini.empty()){
            return mini.top();
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */