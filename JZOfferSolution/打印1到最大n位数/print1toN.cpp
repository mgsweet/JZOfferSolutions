void printNum(char* num, int length) {
    bool findFirstNoneZero = false;
    for (int i = 0; i < length; i++) {
        if (!findFirstNoneZero && num[i] != '0') findFirstNoneZero = true;
        if (findFirstNoneZero) cout << num[i];
    }
    if (findFirstNoneZero == 0) cout << '0';
    cout << endl;
}

void print2MaxOfDigitsRecursively(char* num, int digit, int length) {
    for (int i = 0; i < 10; i++) {
        num[digit] = '0' + i;
        if (digit != length - 1) {
            print2MaxOfDigitsRecursively(num, digit + 1, length);
        } else {
            printNum(num, length);
        }
    }
}

void print2MaxOfDigits(int n) {
    if (n <= 0) exit(EXIT_FAILURE);
    
    char* num = new char[n + 1];
    
    num[n] = '\0';
    
    print2MaxOfDigitsRecursively(num, 0, n);
    
    delete[] num;
}