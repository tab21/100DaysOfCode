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

int minDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    int ans = 1;
    while (q.size())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *tmp = q.front();
            q.pop();

            if (tmp->left == NULL && tmp->right == NULL)
            {
                return ans;
            }

            if (tmp->left != NULL)
            {
                q.push(tmp->left);
            }
            if (tmp->right != NULL)
            {
                q.push(tmp->right);
            }
        }
        ans++;
    }

    return ans;
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
    cout << minDepth(root);
    return 0;
}
