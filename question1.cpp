#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream> // For comma-separated input
using namespace std;

struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

treeNode* BuildTree(const vector<int>& levelorder) {
    if (levelorder.empty() || levelorder[0] == -1) return nullptr;
    
    treeNode* root = new treeNode(levelorder[0]);
    
    queue<treeNode*> q;
    q.push(root);
    int i = 1;
    
    while (i < levelorder.size()) {
        treeNode* current = q.front();
        q.pop();
        
        if (i < levelorder.size() && levelorder[i] != -1) {
            current->left = new treeNode(levelorder[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < levelorder.size() && levelorder[i] != -1) {
            current->right = new treeNode(levelorder[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int diameterHelper(treeNode* root, int& diameter) {
    if (root == nullptr) return 0;
    
    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);
    
    diameter = max(diameter, leftHeight + rightHeight);
    
    return max(leftHeight, rightHeight) + 1;
}

int diameterBinaryTree(treeNode* root) {
    int diameter = 0;
    diameterHelper(root, diameter);
    return diameter;
}

vector <int> ParseInput(const string& input) {
    vector <int> result;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ',')) {
        result.push_back(stoi(token));
        }
        return result;
}

int main() {
    string input;
    int val;

    cout << "Enter a list of integers(Comma-separated, use -1 for null nodes):" << endl;
    getline(cin, input);

    vector<int> levelorder = ParseInput(input);
    
    treeNode* root = BuildTree(levelorder);

    //Output
    cout << diameterBinaryTree(root) << endl;

    return 0;
}
