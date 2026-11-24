/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
;

class Solution {
public:
   unordered_map<Node*,Node*> mp;
   void dfs(Node* node , Node* temp){
    for(auto i:node->neighbors){
        if(mp.find(i)==mp.end()){
            
            Node* clone = new Node(i->val);
            mp[i] = clone;
            temp->neighbors.push_back(clone);
            dfs(i,clone);
        }
        else{
             temp->neighbors.push_back(mp[i]);
        }
    }
   }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        Node* temp = new Node(node->val);
        mp[node] = temp;
        dfs(node,temp);
        return temp;
    }
};