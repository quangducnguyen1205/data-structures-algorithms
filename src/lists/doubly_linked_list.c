//
//  doubly linked list.c
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 15/4/24.
//

#include "doubly_linked_list.h"

// cấu trúc 1 nút của danh sách liên kết đôi
struct DNODE
{
    int data; // dữ liệu chỉ là số nguyên, DEMO
    struct DNODE* next, * prev; // con trỏ tới phần tử kế tiếp, và liền trước
};
 
// hàm cấp phát 1 nút mới với các giá trị con trỏ là mặc định
// dữ liệu nút mới là data
struct DNODE* dll_createNewNode(int data)
{
    struct DNODE* pnew = (struct DNODE*)malloc(sizeof(struct DNODE));
    pnew->data = data;
    pnew->next = NULL;
    pnew->prev = NULL;
    return pnew;
}
// hàm in ra danh sách hiện tại
void dll_printList(const struct DNODE* head)
{
    printf("Danh sach hien tai: \n");
    while (head != NULL) {
        printf("%d --> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// Hàm thêm phần tử vào đâu danh sách
void dll_push_front(struct DNODE** head, int data)
{
    struct DNODE* pnew = dll_createNewNode(data);
    // nếu danh sách ban đầu là rỗng thì phần tử mới là đầu mới luôn
    if (*head == NULL) {
        *head = pnew;
    }
    else // ngươc lại gắn pnew vào vị trí thích hợp
    {
        pnew->next = *head;
        (*head)->prev = pnew;
        *head = pnew;
    }
}
// hàm chèn phần tử mới vào sau vị trí thứ idx trong danh sách hiện tại
// nếu idx > số phần tử hiện có thì chèn vào cuối danh sách
// đầu danh sách là 1
void dll_insertAt(struct DNODE** head, int data, int idx)
{
    // nếu danh sách hiện tại rỗng --> chèn vào đầu
    struct DNODE* pnew = dll_createNewNode(data);
    if (*head == NULL) {
        *head = pnew;
        return;
    }
    // ngược lại, tìm với vi trí idx
    int count = 1;
    struct DNODE* prev=*head;
    while (prev->next != NULL && count < idx)
    {
        prev = prev->next;
        count++;
    }
    // nếu prev đã là cuối danh sách --> chèn vào cuối
    if (prev->next == NULL) {
        // chèn pnew vào sau prev
        prev->next = pnew;
        pnew->prev = prev;
    }
    else // prev chưa phải cuối danh sách --> cần xử lý đoạn prev->next
    {
        prev->next->prev = pnew;
        pnew->next = prev->next;
        prev->next = pnew;
        pnew->prev = prev;
    }
 
}
 
// hàm xóa phần tử khỏi danh sách liên kết đơn
// hàm này sẽ làm thay đổi giá trị head --> truyền vào địa chỉ
void dll_pop_front(struct DNODE** head)
{
    if (*head == NULL) return;
 
    // lưu lại địa chỉ phần tử cần xóa
    struct DNODE* tmp = *head;
    *head = (*head)->next;
    free(tmp);
 
    (*head)->prev = NULL;
}
