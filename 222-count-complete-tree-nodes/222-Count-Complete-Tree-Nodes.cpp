class Solution {
public:
   
    int left(TreeNode* root){
        int sum = 0;
        while(root){
         sum++;
         root = root->left;
        }
        return sum;
    }
    int right(TreeNode* root){
        int sum = 0;
        while(root){
         sum++;
         root = root->right;
        }
        return sum;
    }
    int countNodes(TreeNode* root) {
       if(root==NULL) return 0;
       if(root->left==NULL && root->right==NULL) return 1;
       int lefth = left(root);
       int righth = right(root);
       if(lefth==righth) return pow(2,lefth)- 1;
       return  countNodes(root->left)+countNodes(root->right)+1;
    }
};