#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

void recPermutation(const string & str, set<string> & mySet, vector<bool> & visited, string & combination) {
    int count = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            combination.push_back(str[i]);
            recPermutation(str, mySet, visited, combination);
            combination.pop_back();
            visited[i] = false;
        } else {
            count++;
        }
    }
    if (count == str.size()) {
        mySet.insert(combination);
    }
}

vector<string> Permutation(string str) {
    vector<string> res;
    if (str.size() == 0) {
        return res;
    }
    set<string> mySet;
    vector<bool> visited(str.size(), false);
    string combination = "";
    recPermutation(str, mySet, visited, combination);
    
    res = vector<string>(mySet.begin(), mySet.end());
    return res;
}

int main(int argc, const char * argv[]) {
    string str = "abc";
    vector<string> res = Permutation(str);
    
    for (string s: res) {
        cout << s << endl;
    }
    return 0;
}
