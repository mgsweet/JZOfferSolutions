class Solution {
public:
  bool static isNumeric(const char* str_pointer)
  {
    if (str_pointer == nullptr)
      return false;
    bool is_sign_allow = true;
    bool is_e_allow = true;
    bool is_num_need = true;
    bool is_dot_allow = true;
    while(*str_pointer != '\0') {
      if (is_sign_allow && (*str_pointer == '+' || *str_pointer == '-')) {
        is_sign_allow = false;
      } else if (is_e_allow && (*str_pointer == 'e' || *str_pointer == 'E')) {
        is_e_allow = false;
        is_dot_allow = false;
        is_num_need = true;
        is_sign_allow = true;
      } else if (is_dot_allow && *str_pointer == '.') {
        is_dot_allow = false;
        is_num_need = true;
      } else if (*str_pointer >= '0' && *str_pointer <= '9') {
        is_num_need = false;
        is_sign_allow = false;
      } else {
        return false;
      }
      ++str_pointer;
    }
    return is_num_need == false;
  }
};
