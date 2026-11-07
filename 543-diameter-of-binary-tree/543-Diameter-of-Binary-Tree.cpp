
class Solution {
public:
int result = INT_MIN;
int levels(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int leftheight = levels(root->left);
    int rightheight = levels(root->right);
    int dia = leftheight+rightheight;
    result = max(result,dia);
    return 1+max(leftheight,rightheight);
}

    int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    levels(root);
    return result;
    }
};