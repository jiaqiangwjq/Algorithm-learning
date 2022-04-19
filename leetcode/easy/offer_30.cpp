class MinStack {
    
public:
    /** initialize your data structure here. */
        stack<int> origin_stack;
        stack<int> min_stack;
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        origin_stack.push(x);
        int tmp = ::min(min_stack.top(), x);
        min_stack.push(tmp);
    }
    
    void pop() {
        origin_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return origin_stack.top();
    }
    
    int min() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */