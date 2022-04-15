class MyQueue {
public:
    MyQueue() {

    }

    stack<int> en_q;
    stack<int> de_q;
    
    void push(int x) {
        en_q.push(x);
    }
    
    int pop() {
        if (!de_q.empty()) {
            int tmp = de_q.top();
            de_q.pop();
            return tmp;
        }
        else {
            while (!en_q.empty()) {
                int tmp = en_q.top();
                en_q.pop();
                de_q.push(tmp);
            }
            int tmp = de_q.top();
            de_q.pop();
            return tmp;
        }
    }
    
    int peek() {
        if (!de_q.empty()) {
            int tmp = de_q.top();
            return tmp;
        }
        else {
            while (!en_q.empty()) {
                int tmp = en_q.top();
                en_q.pop();
                de_q.push(tmp);
            }
            int tmp = de_q.top();
            return tmp;
        }
    }
    
    bool empty() {
        if (en_q.empty() && de_q.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */