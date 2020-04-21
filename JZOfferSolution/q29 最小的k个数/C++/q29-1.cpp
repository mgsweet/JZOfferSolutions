#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    typedef multiset<int, greater<int>> MyHeap;
    MyHeap myheap;
    
    if (k < 1 || k > input.size()) return vector<int>();
    
    for (auto num: input) {
        if (myheap.size() < k) {
            myheap.insert(num);
        } else {
            if (num < *myheap.begin()) {
                myheap.erase(myheap.begin());
                myheap.insert(num);
            }
        }
    }
    return vector<int>(myheap.rbegin(), myheap.rend());
}

int main(int argc, const char * argv[]) {
    vector<int> v = {4,5,1,6,2,7,3,8};
    v = GetLeastNumbers_Solution(v, 4);
    for (int num : v) {
        cout << num << endl;
    }
    return 0;
}
