/** 2022/12/06
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * 解題思路:
 *  先測試結尾是不是用 NULL，因為題目沒寫
 *  原先題目看錯以為要按照 val 奇數偶數分類
 *  重新確認是要用位置分類
 *  一開始想用一個 flip 的參數去判斷位置，結束後用 flip = !flip;
 *  這樣做應該是可行，不過程式碼會有點複雜會有多個 if else，我在處理結束的地方一直失敗
 *  所以重新思考
 *  以每個 node 來看要做的動作就以下三步:
 *      1. 確認 next 有沒有東西
 *      2. 如果有，把自己的 next 換成 next 的 next
 *      3. 換下一個 node
 *  這邊要注意換下一個 node 前已經把自己的 next 洗掉了，所以在一開始就要先存到 tmp
 *  這樣就會有兩條: 從 head 出發的 odd、從 even_h (一開始就存第二個) 出發的 even
 *  再來是從 head (odd) 走到底，然後接上 even
 *  空間複雜度 O(1): 用了三個指標 curr, even_h, tmp
 *  時間複雜度 O(n): 雖然有兩個 while，不過最多就是跑 1.5n 次還是 O(n)
 *  最後測資要測試: [], [1], [1,2] (這三個應該就是 corner case, Constraints 寫可能有 0 個 node 且範例都是奇數個)
 */
struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* curr = head;
    struct ListNode* even_h = head->next;
    struct ListNode* tmp = NULL;

    while (curr->next != NULL) {
        tmp = curr->next;
        curr->next = curr->next->next;
        curr = tmp;
    }
    curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = even_h;
    return head;
}
