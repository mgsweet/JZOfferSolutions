#include <iostream>
#include <limits>
#include <map>
#include <array>
#include <vector>
#include <unordered_map>

using namespace std;

int FindFirstZeroOnRight(int xor_data) {
  unsigned int u_xor_data = static_cast<unsigned int>(xor_data);
  int count = 0;
  while ((u_xor_data & 1) == 0 && count < 8 * sizeof(int)) {
      ++count;
      u_xor_data = u_xor_data >> 1;
  }
  return count;
}

void FindNumsAppearOnce(const vector<int> &data, int* num1, int *num2) {
  if (data.size() < 2 || num1 == nullptr || num2 == nullptr)
      return;
  int xor_data = 0;
  for (const int &num : data) {
      xor_data ^= num;
  }
  int first_right_zero_pos = FindFirstZeroOnRight(xor_data);
  *num1 = 0;
  *num2 = 0;
  int sep = 1 << first_right_zero_pos;
  for (const int &num : data) {
      if (num & sep) {
          *num1 ^= num;
      } else {
          *num2 ^= num;
      }
  }
  if (*num1 > *num2)
      swap(*num1, *num2);
  return;
}

int main(int argc, const char* argv[]) {
  int num1, num2;
  FindNumsAppearOnce(vector<int>({2,4,3,6,3,2,5,5}), &num1, &num2);
  cout << num1 << ' ' << num2 << endl;
  return 0;
}
