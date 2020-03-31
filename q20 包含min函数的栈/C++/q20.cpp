class Solution {
private:
    stack<int> minStack;
    stack<int> myStack;
public:
    void push(int value) {
        myStack.push(value);
        if (minStack.empty()) {
            minStack.push(value);
        } else {
            minStack.push(minStack.top() < value ? minStack.top() : value);
        }
    }
    void pop() {
        if (!myStack.empty() && !minStack.empty()) {
            myStack.pop();
            minStack.pop();
        }
    }
    int top() {
        return myStack.top();
    }
    int min() {
        return minStack.top();
    }
};
