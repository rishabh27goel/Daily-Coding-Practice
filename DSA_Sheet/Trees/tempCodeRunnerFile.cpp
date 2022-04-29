void postorderTraversal(Node* root, vector<int> &postorder){

    if(root == NULL) return;

    // Left Node : Right Node : Root Node
    postorderTraversal(root->left, postorder);
    postorderTraversal(root->right, postorder);

    postorder.push_back(root->data);
}