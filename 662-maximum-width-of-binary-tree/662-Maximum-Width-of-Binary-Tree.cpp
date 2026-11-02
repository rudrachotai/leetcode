
class Solution {
    typedef unsigned long long ll;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll width = 0;
        while(q.size()!=0){
              ll  left = q.front().second;
              ll  right = q.back().second; 
            width = max(width,right-left+1);
            int lvlsize = q.size();
            for(int i=0;i<lvlsize;i++){
                pair<TreeNode*,ll> p = q.front();
                q.pop();
                ll cur_id = p.second - left; //////what the fuck 
                if(p.first->left!=NULL) q.push({p.first->left,2*cur_id + 1});
                if(p.first->right!=NULL) q.push({p.first->right,2*cur_id + 2});
            }
        }
        return width;
    }
};