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

TreeNode *helper(vector<int> &nums, int l, int r)
{
    if (nums.size() == 0 || l > r)
    {
        return NULL;
    }

    int m = l + (r - l) / 2;
    TreeNode *root = new TreeNode(nums[m]);
    root->left = helper(nums, l, m - 1);
    root->right = helper(nums, m + 1, r);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return helper(nums, 0, nums.size() - 1);
}

void displayPreorder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (q.size())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    TreeNode *root = sortedArrayToBST(nums);
    displayPreorder(root);
    return 0;
}
