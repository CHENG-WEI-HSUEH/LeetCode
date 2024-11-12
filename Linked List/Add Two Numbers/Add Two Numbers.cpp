/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Help(ListNode* a, ListNode* b, int c)
    {
        //所有輸入都為空且進位為0時，返回NULL
        if(a == NULL && b == NULL && c == 0) return NULL;

        ListNode* ans;

        // 計算當前節點的值，空值則跳過
        int sum = c;
        if(a != NULL) sum += a->val;
        if(b != NULL) sum += b->val;

        // 更新進位
        c = sum/10;
        ans = new ListNode(sum%10);

        // 遞歸處理下一個節點
        ans->next = Help(a?a->next:NULL, b?b->next:NULL, c);

        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        return Help(l1,l2,0);
    }
};
