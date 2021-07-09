/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    p1, p2, p3 := l1, l2, dummy
    var sum, digit, carry int
    for p1 != nil || p2 != nil || carry != 0 {
        sum = carry
        if p1 != nil {
            sum += p1.Val
            p1 = p1.Next
        }
        if p2 != nil {
            sum += p2.Val
            p2 = p2.Next
        }
        digit, carry = sum % 10, sum / 10
        p3.Next = &ListNode{digit, nil}
        p3 = p3.Next
    }
    return dummy.Next
}