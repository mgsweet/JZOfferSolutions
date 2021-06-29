class Solution {
private:
  static void lights2time(array<bool, 10> &lights, vector<string> &ans) {
    int hour = 0, minutes = 0;
    for (int i = 0; i < 4; ++i) {
      hour += lights[i] ? pow(2, i) : 0;
    }
    if (hour > 11) return;
    for (int i = 4; i < 10; ++i) {
      minutes += lights[i] ? pow(2, i - 4) : 0;
    }
    if (minutes > 59) return;
    string str_mins = "";
    if (minutes == 0)
      str_mins = "00";
    else if (minutes < 10) {
      str_mins = "0" + to_string(minutes);
    } else {
      str_mins = to_string(minutes);
    }
    ans.push_back(to_string(hour) + ':' + str_mins);
  }
  static void assist(array<bool, 10> &lights, int start, int num, vector<string> &result) {
    if (num == 0) {
      lights2time(lights, result);
      return;
    } else {
      for (int i = start; i < 10; ++i) {
        lights[i] = true;
        assist(lights, i + 1, num - 1, result);
        lights[i] = false;
      }
    }
  }
public:
  static vector<string> readBinaryWatch(int num) {
    array<bool, 10> lights;
    lights.fill(false);
    num = min(num, 10);
    vector<string> result;
    assist(lights, 0, num, result);
    return result;
  }
};