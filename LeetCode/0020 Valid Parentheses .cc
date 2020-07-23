class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (char ctr : s) {
            if (ctr == '{' || ctr == '(' || ctr == '[') {
                myStack.push(ctr);
            } else {
                switch(ctr) {
                    case '}':
                        if (myStack.empty() || myStack.top() != '{') {
                            return false;
                        }
                        myStack.pop();
                        break;
                    case ')':
                        if (myStack.empty() || myStack.top() != '(') {
                            return false;
                        }
                        myStack.pop();
                        break;
                    case ']':
                        if (myStack.empty() || myStack.top() != '[') {
                            return false;
                        }
                        myStack.pop();
                        break;
                    default:
                        break;
                }
            }
        }
        return myStack.empty();
    }
};