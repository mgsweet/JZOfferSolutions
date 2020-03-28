public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        ListNode pNode = listNode;
        
        Stack<Integer> myStack = new Stack<Integer>();
        while (pNode != null) {
            myStack.push(pNode.val);
            pNode = pNode.next;
        }
        
        while (!myStack.isEmpty()) {
            result.add(myStack.pop());
        }
        return result;
    }
}