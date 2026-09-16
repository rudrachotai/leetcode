
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
        return head;
    }
       ListNode* h = head;
       int n = 1;
       while(h->next!=NULL) 
       {h=h->next;
       n++;}
       ListNode* tail = h;
       h = head;
       k=k%n;
       if (k == 0) {
        return head; // No rotation needed
    }
       for(int i=1 ; i<=n-k-1 ; i++){
             h=h->next;
       }
       ListNode* result = h->next;
       h->next = NULL;
       tail->next = head;
       return result;
    }
};