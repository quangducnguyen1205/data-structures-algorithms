//
//  main.c
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 15/4/24.
//

#include "singly_linked_list.h"


int main(int argc, const char * argv[]) {
    struct NODE* head = NULL;
        
        push_front_v1(&head, 5);
        push_front_v1(&head, 6);
        push_front_v1(&head, 7);
        push_front_v1(&head, 3);
        printList(head);
        
        // thêm vào cuối dãy
//        push_back(&head, 11);
//        push_back(&head, 22);
//        push_back(&head, 25);
//        push_back(&head, 3);
//        printList(head);
     
        // giải phóng bộ nhớ trước khi kết thúc
        freeList(&head);
        return 0;
}
