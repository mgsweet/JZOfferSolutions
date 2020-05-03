class Solution {
public:
  Solution(): first_char_pos_(-1) {
    myHash_.fill(0);
  }
  //Insert one char from stringstream
  void Insert(char ch) {
    str_.push_back(ch);
    if (myHash_[static_cast<int>(ch)] < 2) {
      ++myHash_[static_cast<int>(ch)];
    }
    if (first_char_pos_ == -1) {
      if (myHash_[static_cast<int>(ch)] < 2) {
        first_char_pos_ = static_cast<int>(str_.size()) - 1;
      }
    } else if (ch == str_[first_char_pos_]) {
      int i = first_char_pos_;
      while (i < str_.size()) {
        if (myHash_[str_[i]] < 2) {
          first_char_pos_ = i;
          break;
        }
        ++i;
      }
      if (i == str_.size()) {
        first_char_pos_ = -1;
      }
    }
  }
  //return the first appearence once char in current stringstream
  char FirstAppearingOnce() {
    if (first_char_pos_ == -1) {
      return '#';
    } else {
      return str_[first_char_pos_];
    }
  }
private:
  array<int, 256> myHash_;
  int first_char_pos_;
  string str_;
};
