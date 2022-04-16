class CQueue {
public:
    CQueue() {

    }

    stack<int> in_stk;
    stack<int> out_stk;
    
    void appendTail(int value) {
        in_stk.push(value);
    }
    
    int deleteHead() {
        if (out_stk.empty()) {
            if (in_stk.empty()) {
                return -1;
            }
            while (!in_stk.empty()) {
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
        } 
        
        int res = out_stk.top();
        out_stk.pop();

        // while (!out_stk.empty()) {
        //     in_stk.push(out_stk.top());
        //     out_stk.pop();
        // }

        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */