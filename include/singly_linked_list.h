//
//  singly linked list.h
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 15/4/24.
//

#ifndef singly_linked_list_h
#define singly_linked_list_h

#include <stdio.h>
#include <stdlib.h>

struct NODE;
struct NODE* createNewNode(int data);
void push_front_v1(struct NODE** head, int data);
struct NODE* push_front_v2(struct NODE* head, int data);
void push_back(struct NODE** head, int data);
void printList(const struct NODE* head);
void push_end_v1(struct NODE** head, int data);
void freeList(struct NODE** head);

#endif /* singly_linked_list_h */
