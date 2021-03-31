class Solution {
public:
  int GetUglyNumber_Solution(int index) {
    if (index <= 0) return 0;
    vector<int> ugly_num(index, 0);
    ugly_num[0] = 1;
    int i_2, i_3, i_5;
    i_2 = i_3 = i_5 = 0;
    for (int i = 1; i < index; ++i) {
      ugly_num[i] = min(
          min(ugly_num[i_2] * 2, ugly_num[i_3] * 3),
          ugly_num[i_5] * 5
      );
      while (i_2 < index && ugly_num[i_2] * 2 <= ugly_num[i]) ++i_2;
      while (i_3 < index && ugly_num[i_3] * 3 <= ugly_num[i]) ++i_3;
      while (i_5 < index && ugly_num[i_5] * 5 <= ugly_num[i]) ++i_5;
    }
    return ugly_num[index - 1];
  }
};