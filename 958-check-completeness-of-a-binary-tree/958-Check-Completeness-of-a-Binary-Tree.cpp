class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool isNULL = 0;
        while(q.size()!=0){
            TreeNode* temp = q.front();
            if(temp==NULL) isNULL = 1;
            if(isNULL==1 && temp!=NULL) return false;
            q.pop();
           if(temp!=NULL ) q.push(temp->left);
           if(temp!=NULL ) q.push(temp->right);

        }
        return true;
    }
};