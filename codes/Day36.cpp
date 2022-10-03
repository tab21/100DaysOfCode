
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
int height(TreeNode *root)
{
    int right, left;
    if (root == NULL)
        return 0;

    right = height(root->right);
    left = height(root->left);

    return (1 + max(left, right));
}
bool isBalanced(TreeNode *root)
{
    if (root == NULL)
        return true;

    bool right = isBalanced(root->right);
    bool left = isBalanced(root->left);

    bool differ = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && differ)
        return true;

    return false;
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
    cout << isBalanced(root) << endl;

    return 0;
}
