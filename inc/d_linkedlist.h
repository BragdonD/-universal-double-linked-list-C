#ifndef D_d_linkedList_H
#define D_LINKED_LIST_H

typedef struct d_linkedList {
    struct d_linkedList *before;
    struct d_linkedList *next;
    void *data;
} d_linkedList;

d_linkedList* d_linkedList_createNode(void* data);
void* d_linkedList_first_data(d_linkedList* head);
void* d_linkedList_last_data(d_linkedList* head);
d_linkedList* d_linkedList_first(d_linkedList* head);
d_linkedList* d_linkedList_last(d_linkedList* head);
d_linkedList* d_linkedList_insert_last(d_linkedList* head, d_linkedList* elem);
d_linkedList* d_linkedList_insert_after(d_linkedList* head, d_linkedList* elem);
d_linkedList* d_linkedList_insert_before(d_linkedList* head, d_linkedList* elem);
void* d_linkedList_delete_last(d_linkedList* head);
void* d_linkedList_delete_after(d_linkedList* head);
d_linkedList* d_linkedList_delete_before(d_linkedList* head);
d_linkedList* d_linkedList_delete_head(d_linkedList* head);
void d_linkedList_free(d_linkedList* head);
d_linkedList* d_linkedList_create_from_list(void* arr, int len, size_t type_size);

#endif