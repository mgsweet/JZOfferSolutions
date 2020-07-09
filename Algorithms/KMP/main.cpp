#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> GenKMPTable(const string &pattern) {
  vector<int> kmp_table(pattern.size() + 1, 0);
  if (pattern.empty()) return kmp_table;
  int pos = 1;  // the current position we are computing in T
  int cnd = 0; // the zero-based index in W of the next character of the current candidate substring
  kmp_table[0] = -1;
  while (pos < pattern.size()) {
    if (pattern[pos] == pattern[cnd]) {
      kmp_table[pos] = kmp_table[cnd];
    } else {
      kmp_table[pos] = cnd;
      cnd = kmp_table[cnd];
      while (cnd >= 0 && pattern[pos] != pattern[cnd]) {
        cnd = kmp_table[cnd];
      }
    }
    ++pos;
    ++cnd;
  }
  kmp_table[pos] = cnd;
  return kmp_table;
}

vector<int> KmpSearch(const string &str, const string &pattern) {
  int j = 0;  // the position of the current character in str
  int k = 0;  // the position of the current character in pattern
  vector<int> kmp_table = GenKMPTable(pattern);
  vector<int> p; // positions in S at which W is found
  while (j < str.size()) {
    if (pattern[k] == str[j]) {
      ++j;
      ++k;
      if (k == pattern.size()) {
        p.push_back(j - k);
      }
    } else {
      k = kmp_table[k];
      if (k < 0) {
        ++j;
        ++k;
      }
    }
  }
  return p;
}

int main(const int argc, const char *argv[]) {
  string str = "abcabcdababcdabcdabde";
  string pattern = "abc";
  vector<int> positions = KmpSearch(str, pattern);
  for (auto num: positions) {
    cout << num << ' ';
  }
  cout << endl;
  cout << str.find(pattern) << endl;
  assert(str.find(pattern) == positions[0]);
  return 0;
}