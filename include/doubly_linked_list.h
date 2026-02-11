//
//  doubly linked list.h
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 15/4/24.
//

#ifndef doubly_linked_list_h
#define doubly_linked_list_h

#include<stdio.h>
#include<stdlib.h>

struct DNODE;
struct DNODE* dll_createNewNode(int data);
void dll_printList(const struct DNODE* head);
void dll_push_front(struct DNODE** head, int data);
void dll_insertAt(struct DNODE** head, int data, int idx);
void dll_pop_front(struct DNODE** head);

#endif /* doubly_linked_list_h */
