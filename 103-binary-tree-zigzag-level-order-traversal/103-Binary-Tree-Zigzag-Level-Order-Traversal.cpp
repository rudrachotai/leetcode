class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     if(root==NULL) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> res;
        int lvlidx = 0;
        while(!q.empty()){
        int lvlsize = q.size();
        vector<int> temp(q.size(),0);
        int first = 0;
        int last = temp.size()-1;
        
        while(lvlsize!=0){
            TreeNode* tmp = q.front();
            q.pop();
            if(lvlidx==1){
                temp[last] = tmp->val;
                last--;
            }
            else{
                temp[first] = tmp->val;
                first++;
            }
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
            lvlsize--;
        }
        lvlidx = 1-lvlidx;
        res.push_back(temp);

        }
        return res;   
    }
};