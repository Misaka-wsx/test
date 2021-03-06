/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head||!head->next) 
        {
            return;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode *secondHalf=findSecondhalf(fast,slow);
        ListNode *secondHalfReversed=reverse(secondHalf);
        while (secondHalfReversed)
        {
            ListNode *headnext=head->next;
            ListNode *secondNext=secondHalfReversed->next;
            head->next=secondHalfReversed;
            secondHalfReversed->next=headnext;
            head=headnext;
            secondHalfReversed=secondNext;
        }
        
        
    }
    ListNode* findSecondhalf(ListNode* fast,ListNode *slow)
    {
        while(fast&&fast->next&&fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* newhead=slow->next;
        slow->next=nullptr;
        return newhead;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre=nullptr;
        ListNode* curr=head;
        while (curr)
        {
            ListNode* Nextptr=curr->next;
            curr->next=pre;
            pre=curr;
            curr=Nextptr;
        }
        return pre;
    }
};