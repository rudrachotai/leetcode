class Solution {
public:
    void helper(TreeNode* root, int targetSum,vector<int> &v,vector<vector<int>> &ans,int sum){
        if(root==NULL) return;
        sum+=root->val;
        v.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
         if(sum==targetSum)   ans.push_back(v);
         v.pop_back();
            return;
        }
        helper(root->left,targetSum,v,ans,sum);
        helper(root->right,targetSum,v,ans,sum);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> v;
        vector<vector<int>> ans;
        helper(root,targetSum,v,ans,sum);
        return ans;
    }
};