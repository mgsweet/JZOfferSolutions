/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 func getVals(p *ListNode) <- chan int {
    c := make(chan int)
    go func() {
        for p != nil {
            c <- p.Val
            p = p.Next
        }
        close(c)
    }()
    return c
}

// Use three gophers, but with a very bad result
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    p := dummy
    ch1, ch2 := getVals(l1), getVals(l2)
    var sum, carry int
    for {
        sum = carry
        v1, ok1 := <-ch1
        if ok1 {
            sum += v1
        }
        v2, ok2 := <-ch2
        if ok2 {
            sum += v2
        }
        if !ok1 && !ok2 && sum == 0 {
            break
        }
        p.Next = &ListNode{sum % 10, nil}
        p = p.Next
        carry = sum / 10
    }
    return dummy.Next
}