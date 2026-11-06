class Solution {
public:
  
    void helper(TreeNode* root, int targetSum,int sum,bool &ispossible){
        if (ispossible) return; // Add this to the top of helper() to save time

        if(root==NULL) return;
        sum = sum + root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum) ispossible = true;
            return;
        }
        helper(root->left,targetSum,sum,ispossible);
        helper(root->right,targetSum,sum,ispossible);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ispossible = false;
         int sum = 0;
         helper(root,targetSum,sum,ispossible);
         return ispossible;
    }
};