//
//  singly linked list.c
//  Data structures and algorithms
//
//  Created by QUANG DUC NGUYEN on 15/4/24.
//

#include "singly_linked_list.h"

// định nghĩa cấu trúc 1 nút
// chỉ là DEMO
struct NODE
{
    int data;
    struct NODE* next;
};
 
// hàm tạo 1 nút mới có dữ liệu là data
struct NODE* createNewNode(int data)
{
    struct NODE* newNode;
    newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// hàm thêm phần tử mới vào đầu tiên trong danh sách
// hàm này sẽ làm thay đổi địa chỉ của con trỏ head cũ
void push_front_v1(struct NODE** head, int data)
{
    struct NODE* newNode = createNewNode(data);
    newNode->next = *head;
    *head = newNode;
}
 
// hàm thêm phần tử mới vào đầu tiên trong danh sách
// hàm này sẽ làm thay đổi địa chỉ của con trỏ head cũ
struct NODE* push_front_v2(struct NODE* head, int data)
{
    struct NODE* newNode = createNewNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}
 
// hàm thêm phần tử vào cuối danh sách
// có 2 trường hợp
// TH1. danh sách đang rỗng
// TH2. danh sách khác rỗng
void push_back(struct NODE** head, int data)
{
    struct NODE* newNode = createNewNode(data);
    if (*head == NULL)// danh sách đang rỗng
    {
        newNode->next = *head;
        *head = newNode;
    }
    else // danh sách khác rỗng
    {
        struct NODE* last = *head;
        // tìm tới phần tử cuối
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}
 
// hàm in các phần tử hiện có trong danh sách
void printList(const struct NODE* head)
{
    printf("Danh sach hien tai:\n");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// hàm thêm phần tử mới vào cuối dãy
void push_end_v1(struct NODE** head, int data)
{
    // cấp phát phần tử mới
    struct NODE* newNode = createNewNode(data);
    // nếu danh sách ban đầu là rỗng thì nó là cuối dãy luôn
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    // tìm tới cuối dãy
    struct NODE* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    // gắn phần tử mới vào cuối dãy
    last->next = newNode;
}

// hàm giải phóng danh sách
void freeList(struct NODE** head)
{
    struct NODE* p; // con trỏ phụ lưu địa chỉ đầu trước khi giải phóng
    while (*head != NULL)
    {
        p = *head;
        *head = (*head)->next;
        free(p);
    }
    //*head = NULL; // cho chắc, nhưng có lẽ thừa
}
