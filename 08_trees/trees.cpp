//Deepak Aggarwal, Coding Blocks
//deepak@codingblocks.com

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node * left;
    Node * right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* createBT() {
    // cout << "Enter root ";
    int x;
    cin >> x;
    if (x == -1) return NULL;

    Node * root = new Node(x);
    // cout << "Enter the left child of " << root->data << ": \n";
    root->left = createBT();
    // cout << "Enter the right child " << root->data << " : \n";
    root->right = createBT();
    return root;
}

void printBT(Node * root) {
    if (root == NULL) {
        return;
    }

    printBT(root->left);
    cout << root->data << " ";
    printBT(root->right);
}

Node* inputLevel() {
    Node * root = NULL;
    int x;
    cin >> x;
    if (x == -1) return NULL;

    root = new Node(x);
    queue<Node*> q;
    q.push(root);
    while (q.empty() == false) {
        Node * cur = q.front();
        q.pop();

        //setting the left child
        cin >> x;
        if (x != -1) {
            cur->left = new Node(x);
            q.push(cur->left);
        }

        cin >> x;
        if (x != -1) {
            cur->right = new Node(x);
            q.push(cur->right);
        }
    }
    return root;
}


void printLevel(Node * root) {
    if (root == NULL) {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.empty() == false) {
        Node * cur = q.front();
        q.pop();

        if (cur == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << cur->data << " ";
        if (cur->left)  q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }

}

int cnt(Node * root) {
    if (root == NULL) return 0;
    return cnt(root->left) + 1 + cnt(root->right);
}


int height(Node * root) {
    if (root == NULL) return 0;

    int leftHt = height(root->left);
    int rgtHt = height(root->right);
    return max(leftHt, rgtHt) + 1;
}

int diameter(Node * root) {
    if (root == NULL) return 0;
    int curDiameter = height(root->left) + 1 + height(root->right);
    return max(max(diameter(root->left), diameter(root->right)), curDiameter);
}

int diameterInterview(Node* root) {
    //fn declaration
    pair<int, int> diameterOpt(Node * root); //function declaration
    pair<int, int> ans = diameterOpt(root);
    return ans.second;
}


typedef pair<int, int> ii;  //ht, dia
pair<int, int> diameterOpt(Node* root) {
    if (root == NULL) {
        return ii(0, 0);
    }

    ii leftPair = diameterOpt(root->left);
    ii rightPair = diameterOpt(root->right);
    int curHt = max(leftPair.first, rightPair.first) + 1;
    int curDia = leftPair.first + rightPair.first + 1;

    ii ans;
    ans.first = curHt;
    ans.second = max(max(leftPair.second, rightPair.second), curDia);
    return ans;
}

bool isHtBalanced(Node * root) {
    if (root == NULL) return true;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return ((abs(leftHt - rightHt) <= 1) &&
            isHtBalanced(root->left) &&
            isHtBalanced(root->right)
           );

}

typedef pair<int, bool> ib; //ht, isBalanced

ib isHtBalancedOpt(Node * root) {
    if (root == NULL) {
        return pair<int, bool>(0, true);
    }
    auto leftAns = isHtBalancedOpt(root->left);
    auto rightAns = isHtBalancedOpt(root->right);
    ib ans;
    ans.first = max(leftAns.first, rightAns.first) + 1;
    ans.second = (
                     leftAns.second && rightAns.second &&
                     abs(leftAns.first - rightAns.first) <= 1
                 );
}

void mirror(Node * root) {
    if (root == 0) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
    /*
    Node * tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    */
}

int sumTree(Node * root) {
    //returns sum of a tree and sets the tree accordingly
    if (root == NULL) {
        return 0;
    }

    int left = sumTree(root->left);
    int right = sumTree(root->right);
    int curSum = left + right + root->data;
    root->data = left + right;
    return curSum;
}

int bestNonAdjSum(Node * root, bool includeRoot) {
    if (root == NULL) return 0;

    if (includeRoot) {
        int left = bestNonAdjSum(root->left, false);
        int right = bestNonAdjSum(root->right, false);
        return max(left + right , max(left, right)) + max(root->data, 0);
    } else{
        int left = bestNonAdjSum(root->left, true);
        int right = bestNonAdjSum(root->right, true);
        return max(left + right, max(left, right));
    }
}

int bestNonAdjSum(Node* root) {
    int bestNonAdjSum(Node * , bool); //fn overloading

    int rootInc = bestNonAdjSum(root, true);
    int rootExc = bestNonAdjSum(root, false);

    return max(rootInc, rootExc);
}

void printKthLevel(Node * root, int K){
    if (root == NULL) return;

    if (K == 0){
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, K - 1);
    printKthLevel(root->right, K - 1);
}

void printPath(Node * arr[], int be, int en){
    while(be <= en){
        cout << arr[be]->data << " ";
        ++be;
    }
    cout << endl;
}

Node * arr[100];    //array of Nodes
void printRoot2Leaf(Node root , ArrayList<Node> a);


void printRoot2Leaf(Node * root, int idx){
    if(root == NULL) return;
    
    // if leaf Node
    if (root->left == NULL && root->right == NULL){
        //append
        arr[idx] = root;
        printPath(arr, 0, idx);
        return; 
    }

    arr[idx] = root;
    printRoot2Leaf(root->left, idx + 1);
    printRoot2Leaf(root->right, idx + 1);
}

int main() {
    // Node * root = createBT();
    Node * root = inputLevel();
    // printBT(root);
    // printLevel(root);

    // int cntAns = cnt(root);
    // cout << cntAns << endl;

    // cout << height(root) << endl;

    // cout << diameter(root) << endl;

    // sumTree(root);
    // printLevel(root);

    // int ans = bestNonAdjSum(root);
    // cout << ans;

    // printKthLevel(root, 2);

    printRoot2Leaf(root, 0);



}