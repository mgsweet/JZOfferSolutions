class Solution {
public:
    void replaceSpace(char *str,int length) {
        if (length < 0 && str == nullptr)
            return;
        int oriLength = 0;
        int blankCount = 0;
        
        int i = 0;
        while (str[i] != '\0') {
            oriLength++;
            if (str[i] == ' ')
                blankCount++;
            i++;
        }
        int newLength = oriLength + 2 * blankCount;
        if (length < newLength + 1)
            return;
        str[newLength] = '\0';
        i = newLength - 1;
        int j = oriLength - 1;
        while (i >= 0 && j >= 0) {
            if (str[j] == ' ') {
                str[i--] = '0';
                str[i--] = '2';
                str[i--] = '%';
            } else {
                str[i--] = str[j];
            }
            j--;
        }
    }
};
