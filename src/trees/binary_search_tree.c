//
//  binary search tree.c
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 17/5/24.
//

#include "binary_search_tree.h"

struct BNODE
{
    int label;
    struct BNODE *left, *right;
};
// Hàm tạo nút mới
struct BNODE *bst_createNewNode(int label)
{
    struct BNODE *newNode = (struct BNODE *)malloc(sizeof(struct BNODE));
    newNode->label = label;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
// hàm thêm nút mới là con của nút root
void bst_addNewChild(struct BNODE **root, int label)
{
    // gốc là rỗng --> mọc thêm nút
    if(*root==NULL){
        *root = bst_createNewNode(label);
        return;
    }
    if((*root)->label> label){
        bst_addNewChild(&((*root)->left),label);
    }
    else{
        bst_addNewChild(&((*root)->right),label);
    }
}
// hàm khởi tạo cây
struct BNODE *bst_initTree()
{
    struct BNODE *root;
    bst_addNewChild(&root, 7);
    bst_addNewChild(&root, 3);
    bst_addNewChild(&root, 5);
    bst_addNewChild(&root, 8);
    bst_addNewChild(&root, 4);
    bst_addNewChild(&root, 16);
    bst_addNewChild(&root, 12);
    bst_addNewChild(&root, 11);
    bst_addNewChild(&root, 6);
    return root;
}
// duyệt theo thứ tự trước
void bst_preOrder(struct BNODE *root)
{
    if(root==NULL) return;
    printf("%d, ", root->label);
    bst_preOrder(root->left);
    bst_preOrder(root->right);
}
// duyệt theo thứ tự trước
void bst_inOrder(struct BNODE *root)
{
    if(root==NULL) return;
    bst_inOrder(root->left);
    printf("%d, ", root->label);
    bst_inOrder(root->right);
}
// hàm tính chiều cao của nút
int bst_calHeight(struct BNODE *root)
{
    if(root==NULL) return -1;
    int leftHeight = bst_calHeight(root->left);
    int rightHeight = bst_calHeight(root->right);
    return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
}
// hàm kiểm tra cây nhị phân có gốc là root có phải cây cân bằng
int bst_isBalanced(struct BNODE *root)
{
    if(root==NULL) return 0;
    int leftHeight = bst_isBalanced(root->left);
    int rightHeight = bst_isBalanced(root->right);
    // nếu ko cân bằng
    if(abs(leftHeight-rightHeight)>1) return -1000;
    return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
}
// hàm tìm nút có giá trị label trên cây
struct BNODE *bst_findNode(struct BNODE *root, char label)
{
    if(root==NULL||root->label==label) return root;
    struct BNODE *left = bst_findNode(root->left, label);
    if(left!= NULL) return left;
    return bst_findNode(root->right, label);
}
// hàm tính độ sâu của nút cur với gốc là root
int bst_calDepth(struct BNODE *root, struct BNODE *cur)
{
    if(root==NULL) return -1;
    if(root==cur) return 0;
    int left = bst_calDepth(root->left, cur);
    if(left>=0) return 1+left;
    int right = bst_calDepth(root->right, cur);
    if(right>=0) return 1+right;
    return -1;
}
// hàm kiểm tra đối xứng của 2 cây
int bst_isSymetric(struct BNODE *r1,struct BNODE *r2)
{
    if(r1==NULL && r2==NULL) return 1;
    if((r1==NULL && r2!=NULL) ||(r1!=NULL && r2==NULL)) return 0;
    return bst_isSymetric(r1->left, r2->right) && bst_isSymetric(r1->right, r2->left);
}
