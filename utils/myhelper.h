//
// Created by 邱兆丰 on 2020/10/24.
//

#ifndef DRAFT_MYHELPER_H
#define DRAFT_MYHELPER_H

#include <vector>

/**
 * TreeNode to help solve TreeNode problems.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 2D Matrix
 * @tparam T
 */
template<typename T>
class Matrix {
public:
  static std::vector<std::vector<T>> make_matrix(int n, int m, T default_value) {
    using namespace std;
    if (n <= 0 || m <= 0) {
      cout << "n and m should be greater than zero.";
      abort();
    }
    vector<vector<T>> res;
    for (int i = 0; i < n; ++i) {
      res.push_back(vector<T>(m, default_value));
    }
    return res;
  }

  static void print(std::vector<std::vector<T>> matrix) {
    for (const auto &v: matrix) {
      for (const auto &num: v) {
        std::cout  << num << ' ';
      }
      std::cout << std::endl;
    }
  }
};

/**
 * Make int 2d matrix using python str format.
 * @param str
 * @return
 */
std::vector<std::vector<int>> make_int_matrix(std::string str) {
  using namespace std;
  vector<vector<int>> res;
  vector<int> tmp;
  int status = 0;
  int num;
  for (int i = 0; i < str.size(); ++i) {
    switch (status) {
      case 0:
        if (str[i] == '[') status = 1;
        break;
      case 1:
        if (str[i] == ']') {
          status = INT_MAX;
        } else if (str[i] == '[') {
          status = 2;
          num = 0;
        } else if (str[i] == ',') {
          tmp.clear();
        }
        break;
      case 2:
        if (str[i] == ']') {
          status = 1;
          tmp.push_back(num);
          res.push_back(tmp);
        } else if (str[i] >= '0' && str[i <= '9']) {
          num = num * 10 + str[i] - '0';
        } else if (str[i] == ',') {
          tmp.push_back(num);
          num = 0;
        }
        break;
      case INT_MAX:
        break;
    }
  }
  return res;
}
#endif //DRAFT_MYHELPER_H
