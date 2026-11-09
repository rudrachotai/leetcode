class Solution {
public:
TreeNode * temp =NULL;

bool flag=true;
   void inorder(TreeNode * root){
    if(root==NULL) return;
    inorder(root->left);
    if(temp!=NULL){
        if(temp->val>=root->val){
            flag = false;
              return;
        }
      
    }
    temp=root;
    inorder(root->right);
   }
    bool isValidBST(TreeNode* root) {
        
        inorder(root);
        return flag;

    }
};