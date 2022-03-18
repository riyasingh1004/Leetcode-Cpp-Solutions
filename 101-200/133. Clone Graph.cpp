// Time Complexity O(V+E)

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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (!node)
            return NULL;
        
        Node* copy = new Node(node->val,{});
        queue<Node*> q;
        unordered_map<Node*,Node*> copies;
        copies[node] = copy;
        q.push(node);
        
        while (!q.empty()) {
            
            Node* curr = q.front();
            q.pop();
            
            for (auto neighbour : curr->neighbors) {
                
                if(copies.find(neighbour) == copies.end()) {
                    copies[neighbour] = new Node(neighbour->val,{});
                    q.push(neighbour);
                }
                
                copies[curr]->neighbors.push_back(copies[neighbour]);
            }
            
        }
        
        return copy;
        
    }
};