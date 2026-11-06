class Solution {
public:
void helper(TreeNode* root,int sum,int &totalsum){
    if(root==NULL) return;
    sum = sum*10+root->val;
    if(root->left==NULL && root->right==NULL){
       totalsum+=sum;
       return;
    }
    helper(root->left,sum,totalsum);
    helper(root->right,sum,totalsum);
    

}
    int sumNumbers(TreeNode* root) {
       int sum = 0;
       int totalsum = 0;
       helper(root,sum,totalsum); 
       return totalsum;
    }
};