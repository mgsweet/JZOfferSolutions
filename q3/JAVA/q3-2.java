import java.util.ArrayList;
import java.util.Stack;

public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        ListNode pNode = listNode;
        // Inverse List
        ListNode preNode = null;
        ListNode tempNode = null;
        while (pNode != null) {
            tempNode = preNode;
            preNode = pNode;
            pNode = pNode.next;
            preNode.next = tempNode;
        }
        listNode = preNode;
        pNode = listNode;
        
        while (pNode != null) {
            result.add(pNode.val);
            pNode = pNode.next;
        }
        return result;
    }
}