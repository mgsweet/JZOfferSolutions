import java.util.ArrayList;
import java.util.Stack;

public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        ListNode pNode = listNode;
        if (pNode != null) {
            if (pNode.next != null) {
                result = printListFromTailToHead(pNode.next);
            }
            result.add(pNode.val);
        }
        return result;
    }
}