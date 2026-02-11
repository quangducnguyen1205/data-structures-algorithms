//
//  tree data structure.h
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 15/4/24.
//

#ifndef tree_data_structure_h
#define tree_data_structure_h

#include <stdio.h>
#include <stdlib.h>

struct TNODE;
struct TNODE *tree_createNewNode(char label);
void tree_addNewChild(struct TNODE *root, char label);
struct TNODE *tree_initTree();
void tree_preOrder(struct TNODE *root);
void tree_postOrder(struct TNODE *root);
int tree_getHeight(struct TNODE *root);
int tree_countNodes(struct TNODE *root);

//int main()
//{
//    struct TNODE *root = initTree();
//    printf("Duyet cay theo thu tu truoc: ");
//    preOrder(root);
//    printf("\n");
//    printf("Duyet cay theo thu tu truoc: ");
//    postOrder(root);
//    printf("\n");
//    printf("Chiều cao %c : %d\n",root->label, getHeight(root));
//    struct TNODE *cRoot = root->firstChild->nextSibling;
//    printf("Chiều cao %c : %d\n",cRoot->label, getHeight(cRoot));
//    printf("Số nút con : %d\n",countNodes(root));
//    return 0;
//}

#endif /* tree_data_structure_h */
