#include <iostream>
#include <limits>
#include <map>
#include <array>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> GetVectorWithRange(int start, int end) {
    vector<int> res;
  for (int i = start; i <= end; ++i) {
        res.push_back(i);
    }
    return res;
}

vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > ans;
    if (sum < 2) return ans;
    int mid = sum / 2 + 1;
    int current_sum = 0;
    for (int i = 1, j = 1; i < mid + 1; ++i) {
        current_sum += i;
        while (current_sum > sum) {
            current_sum -= j;
            ++j;
        }
        if (current_sum == sum) {
            if (i - j > 0)
              ans.push_back(GetVectorWithRange(j, i));
        }
    }
    return ans;
}

int main(int argc, const char* argv[]) {
  vector<vector<int> > ans = FindContinuousSequence(3);
  for (auto v : ans) {
    for (auto num: v) {
      cout << num << ' ';
    }
    cout << endl;
  }
  return 0;
}
