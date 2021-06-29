class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (data_.empty()) {
            minData_.push(x);
        } else {
            minData_.push(x < minData_.top() ? x : minData_.top());
        }
        data_.push(x);
    }
    
    void pop() {
        if (!data_.empty()) {
            data_.pop();
            minData_.pop();
        }
    }
    
    int top() {
        return data_.top();
    }
    
    int getMin() {
        return minData_.top();
    }
private:
    stack<int> data_;
    stack<int> minData_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */