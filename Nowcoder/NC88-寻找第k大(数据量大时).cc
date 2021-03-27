#include <set>

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        multiset<int, less<int>> my_red_black;
        for (size_t i = 0; i < a.size(); ++i) {
            if (my_red_black.size() < K) {
                my_red_black.insert(a[i]);
            } else {
                if (a[i] > *my_red_black.begin()) {
                    my_red_black.erase(my_red_black.begin());
                    my_red_black.insert(a[i]);
                }
            }
        }
        return *my_red_black.begin();
    }
};