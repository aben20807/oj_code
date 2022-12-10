/** 2022/12/10
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 解題思路:
 *  先找長的，sum 直接更新在長的上
 *  最後補上 carry
 *  小技巧:
 *      利用 tail1 去記錄最後一個 node 就不用再用 while 跑一次
 *      利用 tail2 重複利用現有的 node
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    struct ListNode* tail1;
    struct ListNode* tail2;
    struct ListNode* ret;
    int carry = 0;
    // find the long one
    while (cur1 && cur2) {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    cur2 = cur1? l2: l1;
    cur1 = cur1? l1: l2;
    ret = cur1;

    while (cur1) {
        int sum = cur1->val + carry + (cur2 ? cur2->val : 0);
        // printf("%d %d %d\n", cur1->val, (cur2 ? cur2->val : 0), carry);
        carry = sum / 10;
        cur1->val = sum % 10;

        // record the tail node
        tail1 = cur1;
        tail2 = (cur2 ? cur2 : tail2);

        // next
        cur1 = cur1->next;
        cur2 = (cur2 ? cur2->next : NULL);
    }
    if (carry) {
        // use tail2 as the last carry node to prevent malloc
        tail2->val = carry; //tail2->next is already NULL
        tail1->next = tail2;
    }
    return ret;
}
