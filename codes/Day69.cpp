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

string tree2str(TreeNode *root)
{
    if (!root)
        return "";
    stringstream ss;
    ss << root->val;
    string res;
    ss >> res;

    if (!root->left && !root->right)
    {
        return res;
    }
    else if (root->right)
    {
        res += "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }
    else if (root->left)
    {
        res += "(" + tree2str(root->left) + ")";
    }

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
    cout << tree2str(root) << endl;

    return 0;
}
