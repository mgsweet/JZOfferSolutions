class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n < 1 || m < 1) return -1;
        list<int> children;
        for (int i = 0; i < n; ++i) {
            children.push_back(i);
        }
        auto iter = children.begin();
        auto next = children.end();
        while (children.size() > 1) {
            for (int i = 0; i < m - 1; ++i) {
                ++iter;
                if (iter == children.end())
                    iter = children.begin();
            }
            next = ++iter;
            if (next == children.end())
                next = children.begin();
            children.erase(--iter);
            iter = next;
        }
        return *(children.begin());
    }
};
