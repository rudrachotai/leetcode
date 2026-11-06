class Solution {
public:
    stack<TreeNode*> asc;
    stack<TreeNode*> dsc;
    TreeNode* getsmall(){
        if(asc.size()==0) return NULL;
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* right = small->right;
        
        while(right){
          asc.push(right);
          right = right->left;
        }
        return small;
    }
    TreeNode* getbig(){
        if(dsc.size()==0) return NULL;
        TreeNode* big = dsc.top();
        dsc.pop();
        TreeNode* left = big->left;
        
        while(left){
          dsc.push(left);
          left = left->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* temp = root;
        if(root==NULL) return false;
        while(temp){
            asc.push(temp);
            temp = temp->left;
        }
        temp = root;
        while(temp){
            dsc.push(temp);
            temp = temp->right;
        }
        TreeNode* i = getsmall();
        TreeNode* j = getbig();
        int target = k ;
        while( i && j && i->val<j->val){
        int sum = i->val + j->val;
        if(sum==target) return true;
        else if(sum<target) i = getsmall();
        else j = getbig();
        }
        return false;
    }
};