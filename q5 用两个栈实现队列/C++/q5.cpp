class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            cout << "ERR: queue is empty." << endl;
            return -1;
        }
        int peak = stack2.top();
        stack2.pop();
        return peak;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
