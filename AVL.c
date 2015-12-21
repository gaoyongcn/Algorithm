#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
typedef int dataType;
typedef struct AVLTreeNode {
    dataType key;
    int balance;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
} Node,*AVLTree;
static dataType arr[] = {4,3,2,1,5,6,7,16,15,14,13,12,11,10,8,9};
//static dataType arr[] = {4,3,2,1,5,6,7,16,15};
Node* createNode(dataType key)
{
    Node* p;
    if((p = (Node *)malloc(sizeof(Node))) == NULL) {
        return NULL;
    }
    p ->key = key;
    p ->balance = 0;
    p ->left = NULL;
    p ->right = NULL;
    return p;
}
Node* RR_rotation(Node* root)
{
    Node *rchild =  root->right;
    root->right = rchild->left;
    rchild->left = root;
    root = rchild;
    return root;
}

Node* LL_rotation(Node* root)
{
    Node *lchild =  root->left;
    root->left = lchild->right;
    lchild->right = root;
    root = lchild;
    return root;
}

Node* LR_rotation(Node* root)
{
    Node *lchild = root->left;
    Node *rgchild = lchild->right;
    lchild->right = rgchild->left;
    rgchild->left = lchild;
    root->left = rgchild;
    root = LL_rotation( root);
    return root;
}

Node* RL_rotation(Node* root)
{
    Node *rchild = root->right;
    Node *lgchild = rchild->left;
    rchild->left = lgchild->right;
    lgchild->right = rchild;
    root->right = lgchild;
    root = RR_rotation(root);
    return root;
}

int getHeight(Node* node)
{
    if(node == NULL) return 0;
    else {
        int m = getHeight(node->left);
        int n = getHeight(node->right);
        return(m > n)?(m+1):(n+1);
    }
}
int getBalance(Node* node)
{
    int height = 0;
    int l = getHeight(node->left);
    int r =getHeight(node->right);
    height = abs(getHeight(node->left) - getHeight(node->right));
    return height;
}
Node* insertNode(AVLTree root, dataType key)
{
    if(root == NULL) {
        Node *p = createNode(key);
        root = p;
        return root;
    }
    if(key<root->key ) {
        root->left = insertNode(root->left, key);
        if(getBalance(root)==2) {
            if(key < root->left->key) {
                root = LL_rotation(root);
            } else {
                root=LR_rotation(root);
            }
        }
    } else {
        root->right = insertNode(root->right, key);
        if(getBalance(root)==2) {
            if(key >  root->right->key) {
                root =RR_rotation(root);
            } else {
                root=RL_rotation(root);
            }
        }
    }
    return root;
}

void printTree(Node* tree)
{
    char i;
    static char level = 1;	// 记录当前层数，根结点所在层为第1层
    static char right = 0;	// 记录是第几次进入右子树
    if(!tree) {
        return;
    }
    printf("%d\n", tree->key);
    if(!tree->left && !tree->right) {
        return;
    }

    if(tree->left) {
        for(i=1; i<level-right; ++i) {
            printf("│   ");
        }
        for(i=0; i<right; ++i) {
            printf("    ");
        }

        if(tree->right) {
            printf("├──");
        } else {
            printf("└──");
        }

        ++level;	// 开始先序进入下一层
        printTree(tree->left);
        --level;	// 回到当前层
    }

    if(tree->right) {
        for(i=1; i<level-right; ++i) {
            printf("│   ");
        }
        for(i=0; i<right; ++i) {
            printf("    ");
        }
        printf("└──");

        ++level;
        ++right;	// 每进入一次右子树，记录值+1
        printTree(tree->right);
        --right;	// 从右子树出来后，再-1
        --level;
    }
}

int main()
{
    int len,i;
    GET_ARRAY_LEN(arr, len);
    AVLTree root = NULL;
    for(i=0; i<len; i++) {
        root = insertNode(root, arr[i]);
    }
    printTree(root);
    return 0;
}


