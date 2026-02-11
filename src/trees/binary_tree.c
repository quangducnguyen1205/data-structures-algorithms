//
//  binary tree.c
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 17/5/24.
//

#include "binary_tree.h"


struct BNODE
{
    char label;
    struct BNODE *left, *right;
};
// Hàm tạo nút mới
struct BNODE *bt_createNewNode(char label)
{
    struct BNODE *newNode = (struct BNODE *)malloc(sizeof(struct BNODE));
    newNode->label = label;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
// hàm thêm nút mới là con của nút root
// root phải khác NULL
// nếu isLeftChild=1 thfi là con trái, ngược lại là con phải
void bt_addNewChild(struct BNODE *root, char label, int isLeftChild)
{
    struct BNODE *newNode = bt_createNewNode(label);
    if(isLeftChild){
        root->left = newNode;
    }
    else{
        root->right = newNode;
    }
}
// hàm khởi tạo cây
struct BNODE *bt_initTree()
{
    struct BNODE *root;
    // nút gốc là A
    root = bt_createNewNode('A');
    // thêm con trái và con phải của A
    bt_addNewChild(root,'B',1);
    bt_addNewChild(root,'F',0);
    // thêm con phải của B (root->left)
    bt_addNewChild(root->left,'C',0);
    // thêm con trái của F(root->right)
    bt_addNewChild(root->right,'E',1);
    // thêm con trái,phải E(root->right->left)
    bt_addNewChild(root->right->left,'D',1);
    bt_addNewChild(root->right->left,'G',0);
    return root;
}
// duyệt theo thứ tự trước
void bt_preOrder(struct BNODE *root)
{
    if(root==NULL) return;
    printf("%c, ", root->label);
    bt_preOrder(root->left);
    bt_preOrder(root->right);
}
// duyệt theo thứ tự trước
void bt_inOrder(struct BNODE *root)
{
    if(root==NULL) return;
    bt_inOrder(root->left);
    printf("%c, ", root->label);
    bt_inOrder(root->right);
}
// hàm tính chiều cao của nút
int bt_calHeight(struct BNODE *root)
{
    if(root==NULL) return -1;
    int leftHeight = bt_calHeight(root->left);
    int rightHeight = bt_calHeight(root->right);
    return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
}
 
// hàm kiểm tra cây nhị phân có gốc là root có phải cây cân bằng
int bt_isBalanced(struct BNODE *root)
{
    if(root==NULL) return 0;
    int leftHeight = bt_isBalanced(root->left);
    int rightHeight = bt_isBalanced(root->right);
    // nếu ko cân bằng
    if(abs(leftHeight-rightHeight)>1) return -1000;
    return 1+ (leftHeight>rightHeight?leftHeight:rightHeight);
}
// hàm tìm nút có giá trị label trên cây
struct BNODE *bt_findNode(struct BNODE *root, char label)
{
    if(root==NULL||root->label==label) return root;
    struct BNODE *left = bt_findNode(root->left, label);
    if(left!= NULL) return left;
    return bt_findNode(root->right, label);
}
// hàm tính độ sâu của nút cur với gốc là root
int bt_calDepth(struct BNODE *root, struct BNODE *cur)
{
    if(root==NULL) return -1;
    if(root==cur) return 0;
    int left = bt_calDepth(root->left, cur);
    if(left>=0) return 1+left;
    int right = bt_calDepth(root->right, cur);
    if(right>=0) return 1+right;
    return -1;
}
 
// hàm kiểm tra đối xứng của 2 cây
int bt_isSymetric(struct BNODE *r1,struct BNODE *r2)
{
    if(r1==NULL && r2==NULL) return 1;
    if((r1==NULL && r2!=NULL) ||(r1!=NULL && r2==NULL)) return 0;
    return bt_isSymetric(r1->left, r2->right) && bt_isSymetric(r1->right, r2->left);
}
