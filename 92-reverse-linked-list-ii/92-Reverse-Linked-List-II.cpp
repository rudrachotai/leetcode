class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode* before = head;
        ListNode* L = head;
        int ct = 1;
        while(ct<left){
            before = L;
            L=L->next;
            ct++;
        }
        int times = right-left+1;
        ListNode* curr = L;
        ListNode* prev = NULL;
        
        while(times){
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr=next;
        times--;
        }
        L->next=curr;
        if(left==1) return prev;
        
        before->next=prev;
        return head;
    }
};