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

vector<int> h(TreeNode *root)
{
    if (root)
    {
        vector<int> l = h(root->left);
        vector<int> r = h(root->right);
        int root1 = max({l[0], r[0], 1 + l[1] + r[1]});
        int root2 = 1 + max(l[1], r[1]);
        return {root1, root2};
    }

    return {0, 0};
}

int diameterOfBinaryTree(TreeNode *root)
{
    return h(root)[0] - 1;
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
    cout << diameterOfBinaryTree(root) << endl;
    return 0;
}
