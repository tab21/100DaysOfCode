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

// making Tree
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

// flattening tree to linked list
void flatten(TreeNode *root)
{
    if (root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    if (root->left)
    {
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = NULL;

        while (root->right)
            root = root->right;

        root->right = right;
    }
}

void Print(TreeNode *ans)
{
    // moving only to right child for linked list
    while (ans and ans->right)
    {
        cout << ans->val << " " << ans->left << " ";
        ans = ans->right;
    }

    cout << ans->val << endl;
}
int main()
{
    TreeNode *root = makeTree();
    flatten(root);
    Print(root);

    return 0;
}
