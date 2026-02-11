//
//  binary search tree.h
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 17/5/24.
//

#ifndef binary_search_tree_h
#define binary_search_tree_h

#include <stdio.h>
#include <stdlib.h>

struct BNODE;
struct BNODE *bst_createNewNode(int label);
void bst_addNewChild(struct BNODE **root, int label);
struct BNODE *bst_initTree();
void bst_preOrder(struct BNODE *root);
void bst_inOrder(struct BNODE *root);
int bst_calHeight(struct BNODE *root);
int bst_isBalanced(struct BNODE *root);
struct BNODE *bst_findNode(struct BNODE *root, char label);
int bst_calDepth(struct BNODE *root, struct BNODE *cur);
int bst_isSymetric(struct BNODE *r1,struct BNODE *r2);

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

#endif /* binary_search_tree_h */
