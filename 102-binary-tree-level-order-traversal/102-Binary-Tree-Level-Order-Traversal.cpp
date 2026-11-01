class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> res;
        while(!q.empty()){
        int lvlsize = q.size();
        vector<int> temp;
        while(lvlsize!=0){
            TreeNode* tmp = q.front();
            q.pop();
            temp.push_back(tmp->val);
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
            lvlsize--;
        }
        res.push_back(temp);

        }
        return res;
    }
};