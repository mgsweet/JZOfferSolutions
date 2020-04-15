#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

void Permutation(string & str, int begin, vector<string> & res) {
    if (begin + 1 == str.size()) {
        res.push_back(str);
    } else {
        Permutation(str, begin + 1, res);
        for (int i = begin; i < str.size(); i++) {
            if (str[i] != str[begin]) {
                swap(str[begin], str[i]);
                Permutation(str, begin + 1, res);
                swap(str[begin], str[i]);
            }
        }
    }
}

vector<string> Permutation(string str) {
    vector<string> res;
    if (str.size() == 0) {
        return res;
    }
    Permutation(str, 0, res);
    sort(res.begin(), res.end());
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
