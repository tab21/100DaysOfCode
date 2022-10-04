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

int c = 0;

void count(TreeNode *root, int prv_maxi)
{
    if (!root)
    {
        return;
    }

    if (root->val >= prv_maxi)
    {
        c++;
    }
    prv_maxi = max(root->val, prv_maxi);

    count(root->left, prv_maxi);
    count(root->right, prv_maxi);
}

int goodNodes(TreeNode *root)
{
    if (root)
        count(root, root->val);
    return c;
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
    cout << goodNodes(root) << endl;

    return 0;
}
