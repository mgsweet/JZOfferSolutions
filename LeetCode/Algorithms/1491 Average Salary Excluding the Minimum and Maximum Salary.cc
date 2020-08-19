class Solution {
public:
  double average(vector<int>& salary) {
    if (salary.size() < 3) return 0;
    double ans = 0;
    int max_num = max(salary[0], salary[1]);
    int min_num = min(salary[0], salary[1]);
    for (int i = 2; i < salary.size(); ++i) {
      if (salary[i] > max_num) {
        ans += max_num;
        max_num = salary[i];
      } else if (salary[i] < min_num) {
        ans += min_num;
        min_num = salary[i];
      } else {
        ans += double(salary[i]);
      }
    }
    return ans / (salary.size() - 2);
  }
};