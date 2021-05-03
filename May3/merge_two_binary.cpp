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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return merge(root1, root2);
    }

    TreeNode *merge(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return NULL;
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;

        root1->val = root1->val + root2->val;
        root1->left = merge(root1->left, root2->left);
        root1->right = merge(root1->right, root2->right);
        return root1;
    }
};

int main()
{
    Solution solution;

    struct TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(2);

    struct TreeNode *root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);
    solution.mergeTrees(root1, root2);
}
