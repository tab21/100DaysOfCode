#include <bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode *root, int &deep, int curr, int &res)
{
    if (!root)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        if (deep == curr)
        {
            res += root->val;
        }
        else if (deep < curr)
        {
            deep = curr;
            res = root->val;
        }
        return;
    }

    helper(root->left, deep, curr + 1, res);
    helper(root->right, deep, curr + 1, res);
}

int deepestLeavesSum(TreeNode *root)
{
    int res = 0, curr = 0, deep = 0;

    helper(root, deep, curr, res);
    return res;
}

TreeNode *insertLevelOrder(int arr[], int i, int n)
{
    TreeNode *root = nullptr;
    // Base case for recursion and letting -1 work as null here
    if (i < n && arr[i] != -1)
    {
        root = new TreeNode(arr[i]);

        // insert left child
        root->left = insertLevelOrder(arr, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

TreeNode *makeTree()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    return insertLevelOrder(arr, 0, n);
}

int main()
{
    TreeNode *root = makeTree();
    cout << deepestLeavesSum(root) << endl;

    return 0;
}
