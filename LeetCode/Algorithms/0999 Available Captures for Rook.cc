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
#include <unordered_map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  static bool CheckChar(char current_char, int &count_p) {
    if (current_char == '.') {
      return true;
    }
    if (('a' <= current_char && current_char <= 'z') || ('A' <= current_char && current_char <= 'Z')) {
      if (current_char == 'p') ++count_p;
      return false;
    }
    cout << 'Error' << endl;
    return false;
  }

public:
  static int numRookCaptures(vector<vector<char>>& board) {
    int rook_row = -1, rook_col = -1;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] = 'R') {
          rook_row = i;
          rook_col = j;
          break;
        }
      }
    }
    if (rook_row == -1 || rook_col == -1) return -1;
    int count_p = 0;
    // Check left
    for (int i = rook_col - 1; i >= 0; --i) {
      if (CheckChar(board[rook_row][i], count_p) == false) break;
    }
    // Check right
    for (int i = rook_col + 1; i < board[0].size(); ++i) {
      if (CheckChar(board[rook_row][i], count_p) == false) break;
    }
    // Check up
    for (int i = rook_row - 1; i >= 0; --i) {
      if (CheckChar(board[i][rook_col], count_p) == false) break;
    }
    // Check down
    for (int i = rook_row + 1; i < board.size(); ++i) {
      if (CheckChar(board[i][rook_col], count_p) == false) break;
    }
    return count_p;
  }
};

int main() {
  vector<int> preorder({3, 9, 20, 15, 7});
  vector<int> inorder({9, 3, 15, 20, 7});
  TreeNode *ans = Solution::buildTree(preorder, inorder);
  cout << endl;
  return 0;
}