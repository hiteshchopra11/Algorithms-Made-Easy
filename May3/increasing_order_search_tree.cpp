#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        vector<TreeNode *> nodes;
        inOrder(root, nodes);

        for (int i = 0; i < nodes.size() - 1; i++)
        {
            nodes.at(i)->left = NULL;
            nodes.at(i)->right = nodes.at(i + 1);
        }

        //back() is used to fetch the last element of a vector
        nodes.back()->left = NULL;
        nodes.back()->right = NULL;
        return nodes.at(0);
    }

    void inOrder(TreeNode *node, vector<TreeNode *> &nodes)
    {

        if (node == NULL)
            return;

        inOrder(node->left, nodes);
        nodes.push_back(node);
        inOrder(node->right, nodes);
    }
};

int main()
{
    Solution solution;

    struct TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(1);
    root1->right = new TreeNode(6);
    root1->right->right = new TreeNode(8);
    root1->right->right->left = new TreeNode(7);
    root1->right->right->right = new TreeNode(9);
    solution.increasingBST(root1);
}
