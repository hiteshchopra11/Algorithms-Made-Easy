/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
     int decimal(vector<int> v){
        int n=0;
        for(int i=0;i<v.size();i++)
            n=n*2+v[i];
        return n;
    }
    
    void rootToLeaf(TreeNode* root,vector<int> v)
    {
        //Base condition
        if(root==NULL)return;
        
        //Recursive conditions
        v.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            ans=ans+decimal(v);
        }
        rootToLeaf(root->left,v);
        rootToLeaf(root->right,v);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> v;
        rootToLeaf(root,v);
        return ans;
    }
};
