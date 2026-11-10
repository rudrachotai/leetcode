class Solution {
public:
    unordered_map <int,int> map;
    
    TreeNode* helper(vector<int> &postorder,int st,int end,int &idx){
     if(st>end) return NULL;
     TreeNode* temp = new TreeNode(postorder[idx]);
     idx--;
     temp->right = helper(postorder,map[temp->val]+1,end,idx);
     temp->left = helper(postorder,st,map[temp->val]-1,idx);
     
     return temp;
     
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return helper(postorder,0,inorder.size()-1,idx);
    }
};