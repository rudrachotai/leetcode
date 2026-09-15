
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* left = head;
        ListNode* prevleft = NULL;
        ListNode* right = head;
       

        int k=2;
        for(int i=0;i<k-1;i++){
        if(right)right=right->next;
        }
        if(!right) return head;
        ListNode* result = right;
        while(left!=NULL && right!=NULL){
         int times = 2;
        ListNode* prev = NULL;
        ListNode* curr = left;
         while(times && curr){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nex;
            times--;
         }
        if(prevleft) prevleft->next = right;
        
        prevleft = left;
        left = curr;
        right = left;
        {for(int i=0;i<k-1;i++){
        if(right) right=right->next;
        }}
        if (right==NULL && left!=NULL) {
            prevleft->next = left;
            
        }
        }
        return result;
    }
};