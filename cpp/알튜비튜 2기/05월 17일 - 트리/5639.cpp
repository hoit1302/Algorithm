#include <iostream>

using namespace std;
struct node {
    int v;
    node* l;
    node* r;
};

node* makeBST(node* root, int cur) {
    if (root == nullptr) {
        root = new node();
        root->v = cur;
        root->l = root->r = nullptr;
    } else if (root->v < cur) {
        root->r = makeBST(root->r, cur);
    } else if (cur < root->v) {
        root->l = makeBST(root->l, cur);
    }
    return root;
}

void postOrder(node* root) { // 후위순회, L R V
    if (root == nullptr) {
        return;
    }
    postOrder(root->l);
    postOrder(root->r);
    cout << root->v << '\n';
}

int main() {
    freopen("../input.txt", "r", stdin);
    int in;
    node* root = nullptr;
    while (cin >> in) {
        root = makeBST(root, in);
        // cout << root->v << ' ';
    }
    // cout << '\n';
    postOrder(root);
}