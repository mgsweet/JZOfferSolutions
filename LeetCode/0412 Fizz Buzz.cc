class Solution {
public:
  vector<string> fizzBuzz(int n) {
    int fizz = 0, buzz = 0;
    vector<string> ans;
    string tmp;
    for (int i = 0, fizz = 0, buzz = 0; i < n; ++i, ++fizz, ++buzz) {
      tmp = "";
      if (fizz == 2) {
        fizz = -1;
        tmp += "Fizz";
      }
      if (buzz == 4) {
        buzz = -1;
        tmp += "Buzz";
      }
      if (tmp.empty()) {
        tmp += to_string(i + 1);
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};