class Solution {
public:

    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {

        if (left > right)
            return NULL;

        // Last element of postorder is the root
        int rootValue = postorder[postIndex--];

        TreeNode* root = new TreeNode(rootValue);

        int mid = mp[rootValue];

        // IMPORTANT:
        // Postorder is Left -> Right -> Root.
        // Since we are moving from the end, we get:
        // Root -> Right -> Left
        // Therefore build Right first.
        root->right = build(inorder, postorder, mid + 1, right);

        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Store index of every value in inorder
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};