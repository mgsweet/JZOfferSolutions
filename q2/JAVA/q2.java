public class Solution {
    public String replaceSpace(StringBuffer str) {
        int blankCount = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                blankCount++;
            }
        }
        int preIndex = str.length() - 1;
        int newLength = str.length() + 2 * blankCount;
        str.setLength(newLength);
        int newIndex = str.length() - 1;

        while (preIndex >= 0 && newIndex >= 0) {
            if (str.charAt(preIndex) == ' ') {
                str.setCharAt(newIndex--, '0');
                str.setCharAt(newIndex--, '2');
                str.setCharAt(newIndex--, '%');
            } else {
                str.setCharAt(newIndex--, str.charAt(preIndex));
            }
            preIndex--;
        }
        return str.toString();
    }
}