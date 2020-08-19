class MyStack {
private:
    queue<int> data;
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (data.empty()) return 0;
        queue<int> tmp;
        while (data.size() > 1) {
            tmp.push(data.front());
            data.pop();
        }
        int res = data.front();
        data = tmp;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (data.empty()) return 0;
        queue<int> tmp;
        while (data.size() > 1) {
            tmp.push(data.front());
            data.pop();
        }
        int res = data.front();
        data = tmp;
        data.push(res);
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */