package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers1(l1 *ListNode, l2 *ListNode) *ListNode {
	dummyHead := &ListNode{}
	p := dummyHead
	var sum, carry int

	for l1 != nil || l2 != nil || carry != 0 {
		sum = carry
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}

		p.Next = &ListNode{Val: sum % 10}
		carry = sum / 10
		p = p.Next
	}
	return dummyHead.Next
}
