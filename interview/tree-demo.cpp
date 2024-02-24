//
// Created by Administrator on 2024/2/24.
//

/*
 * 广州敏视数码科技有限公司-嵌入式
 */



//二叉树的先序遍历
//请用C语言实现:编写一个函数对二叉树先序遍历，按照如下格式输出。格式:根节点（左节点，右节点)
//例如:49(28(14,31),53(50,64))表示如下二叉树。
//49
//2853
//14315064

#include <stdio.h>
#include <stdlib.h>

typedef int elemType;

struct BTreeNode {
    elemType data;
    struct BTreeNode *left;
    struct BTreeNode *right;
};


//笔试的时候写的代码
// 一开始只写出了一个中序遍历
// 后来由于时间比较多，因此有时间思考最终完成了如下代码
void printBTree(struct BTreeNode *bt) {
    if (bt == NULL) return;

    printf("%d", bt->data);
    if (bt->left || bt->right) printf("(");
    printBTree(bt->left);
    if (bt->left && bt->right) printf(",");
    printBTree(bt->right);
    if (bt->left || bt->right) printf(")");
}



//////////////  测试 ///////////////////
// 创建新的二叉树节点
struct BTreeNode* createNode(elemType data) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    if (!newNode) {
        exit(-1); // 分配内存失败，退出程序
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 先序遍历二叉树，并按照指定格式输出
// 文心一言
//void printBTree(struct BTreeNode *bt) {
//    if (bt == NULL) {
//        return;
//    }
//
//    // 先输出根节点
//    printf("%d", bt->data);
//
//    // 如果有左子树，则递归输出左子树，并在前后加上括号和逗号
//    if (bt->left != NULL) {
//        printf("(");
//        printBTree(bt->left);
//        printf(",");
//    }
//
//    // 如果有右子树，则递归输出右子树，并在后加上括号
//    if (bt->right != NULL) {
//        printBTree(bt->right);
//        printf(")");
//    }
//
//    // 如果是叶子节点，则在后面加上括号
//    if (bt->left == NULL && bt->right == NULL) {
//        printf("()");
//    }
//}

int main() {
    // 构造示例二叉树
    struct BTreeNode *root = createNode(49);
    root->left = createNode(28);
    root->right = createNode(53);
    root->left->left = createNode(14);
    root->left->right = createNode(31);
    root->right->left = createNode(50);
    root->right->right = createNode(64);

    // 打印二叉树
    printBTree(root);

    // 释放二叉树内存
    // ...（这里需要编写释放二叉树内存的函数）

    return 0;
}