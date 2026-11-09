class Solution {
public:
    TreeNode* temp=NULL;//used to save previous Node;
    TreeNode* f1=NULL;
    TreeNode* f2=NULL;
    TreeNode* s1=NULL;
    TreeNode* s2=NULL;
    int wrong = 0;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(temp == NULL){}
        else if(temp!=NULL && temp->val>=root->val){
            if(wrong==0) {
                f1 = temp;
                f2 = root;
                wrong++;
            }
            else if(wrong==1){
                s1 = temp;
                s2 = root;
                wrong++;
            }
        }
        temp = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(s1==NULL || s2==NULL) swap(f1->val,f2->val);
        else swap(f1->val,s2->val);
    }
};