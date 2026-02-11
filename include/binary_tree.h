//
//  binary tree.h
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 17/5/24.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <stdio.h>
#include <stdlib.h>

struct BNODE;
struct BNODE *bt_createNewNode(char label);
void bt_addNewChild(struct BNODE *root, char label, int isLeftChild);
struct BNODE *bt_initTree();
void bt_preOrder(struct BNODE *root);
void bt_inOrder(struct BNODE *root);
int bt_calHeight(struct BNODE *root);
int bt_isBalanced(struct BNODE *root);
struct BNODE *bt_findNode(struct BNODE *root, char label);
int bt_calDepth(struct BNODE *root, struct BNODE *cur);
int bt_isSymetric(struct BNODE *r1,struct BNODE *r2);

//int main()
//{
//    struct BNODE *root = initTree();
//    printf("Duyệt cây thứ tự trước: ");
//    preOrder(root);
//    printf("\n");
//    printf("Duyệt cây thứ tự giữa: ");
//    inOrder(root);
//    printf("\n");
//    printf("Chiều cao cây: %d\n",calHeight(root));
//    struct BNODE *cur = findNode(root, 'C');
//    printf("Độ sâu của nút %c là %d\n",cur->label, calDepth(root, cur));
// 
//    cur = findNode(root, 'D');
//    if(cur!=NULL)
//        printf("Độ sâu của nút %c là %d\n",cur->label, calDepth(root, cur));
//    printf("%d\n",isBalanced(root));
//    if(isBalanced(root)<0) printf("Không phải cây cân bằng!\n");
//    else printf("Cây cân bằng!\n");
//    if(isSymetric(root->left, root->right))
//    {
//        printf("Cây đối xứng!\n");
//    }
//    else
//    {
//        printf("Cây không đối xứng!\n");
//    }
//    return 0;
//}

#endif /* binary_tree_h */
