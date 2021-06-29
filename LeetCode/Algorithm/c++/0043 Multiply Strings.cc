#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <string>
#include <limits>
#include <array>
#include <thread>
#include <assert.h>

//struct ListNode {
//  int val;
//  ListNode *next;
//  ListNode() : val(0), next(nullptr) {}
//  ListNode(int x) : val(x), next(nullptr) {}
//  ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

using namespace std;

class Solution {
public:
  string static multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    if (num1.size() > num2.size()) {
      // To prevent "00"
      swap(num1, num2);
    }
    vector<string> mid_mults;
    string mid_mult;
    for (int i = 0; i < num1.size(); ++i) {
      mid_mult.clear();
      int carry = 0;
      int digit1 = num1[i] - '0';
      if (digit1 == 0) {
        mid_mults.push_back("0");
      } else {
        for (int j = 0; j < num2.size(); ++j) {
          int digit2 = num2[j] - '0';
          int tmp = digit1 * digit2 + carry;
          mid_mult.push_back(tmp % 10 + '0');
          carry = tmp / 10;
        }
        if (carry != 0) {
          mid_mult.push_back(carry + '0');
        }
        mid_mults.push_back(mid_mult);
      }
    }
    int carry = 0;
    int i = 0;
    string ans;
    while(1) {
      if (carry == 0 && i >= mid_mults[mid_mults.size() - 1].size() + mid_mults.size() - 1)
        break;
      int sum = 0;
      for (int j = 0; j <= i; ++j) {
        if (j < mid_mults.size() && i - j < mid_mults[j].size()) {
          sum += mid_mults[j][i - j] - '0';
        }
      }
      sum += carry;
      ans.push_back(sum % 10 + '0');
      carry = sum / 10;
      ++i;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  cout << Solution::multiply("123", "456") << endl;
  return 0;
}