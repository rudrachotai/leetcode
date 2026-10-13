class Solution {
public: 
  struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Extracts and compares the actual integer values
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode*,vector<ListNode*>,Compare> pq;
        for(int i=0;i<lists.size();i++){
         if(lists[i]!=NULL)   pq.push(lists[i]);
        }
        int i=0;
        ListNode* result = new ListNode(10);
        result->next = NULL;
        ListNode* ptr = result;
        while(pq.size()!=0){
       ListNode* temp = pq.top();
       pq.pop();
       ptr->next = temp;
       ptr=ptr->next;
       if(temp->next!=NULL){
        pq.push(temp->next);
       }
    
        }
        return result->next;
    }
};