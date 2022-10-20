#include <stdlib.h>
#include "d_linkedlist.h"

d_linkedList* d_linkedList_createNode(void* data) {
    d_linkedList* temp = NULL;
    temp = malloc(sizeof *temp);
    if(temp == NULL) return temp;
    temp->before = NULL;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

d_linkedList* d_linkedList_first(d_linkedList* head) {
    d_linkedList *pnow = head;
    if(head == NULL) return NULL;
    while(pnow->before != NULL) {
        pnow = pnow->before;
    }
    return pnow;
}

d_linkedList* d_linkedList_last(d_linkedList* head) {
    d_linkedList *pnow = head;
    if(head == NULL) return NULL;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    return pnow;
}

d_linkedList* d_linkedList_insert_last(d_linkedList* head, d_linkedList* elem) {
    d_linkedList *pnow = head;
    if(head == NULL) return elem;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    elem->before = pnow;
    pnow->next = elem;
    return head;
}

d_linkedList* d_linkedList_insert_after(d_linkedList* head, d_linkedList* elem) {
    if(head == NULL) return elem;
    if(elem == NULL) return head;
    head->next = d_linkedList_insert_last(elem, head->next);
    head->next->before = head;
    return head; 
}

d_linkedList* d_linkedList_insert_before(d_linkedList* head, d_linkedList* elem) {
    if(head == NULL) return elem;
    if(elem == NULL) return head;
    head->before = elem;
    elem->next = head;
    return elem;
}

void* d_linkedList_delete_last(d_linkedList* head) {
    d_linkedList *pnow = head;
    void* data = NULL;
    if(head == NULL) return NULL;
    while(pnow->next != NULL) {
        pnow = pnow->next;
    }
    pnow->before->next = NULL;
    data = pnow->data;
    free(pnow);
    return data;    
}

void* d_linkedList_delete_after(d_linkedList* head) {
    d_linkedList *temp = NULL;
    void* data = NULL;
    if(head == NULL) return NULL;
    if(head->next == NULL) return NULL;
    temp = head->next->next;
    data = head->next->data;
    free(head->next);
    head->next = temp;
    return data;    
}

d_linkedList* d_linkedList_delete_before(d_linkedList* head) {
    d_linkedList* root = head;
    d_linkedList* toreturn = NULL;
    if(head == NULL) return NULL;
    if(head->before == NULL) return NULL;
    while(root->before->before != NULL) {
        root = root->before;
    }
    toreturn = malloc(sizeof *toreturn);
    if(toreturn == NULL) return NULL;
    toreturn->data = head->before->data;
    toreturn->next = root;
    free(head->before);
    return toreturn;
}

d_linkedList* d_linkedList_delete_head(d_linkedList* head) {
    d_linkedList* root = head;
    d_linkedList* toreturn = NULL;
    if(head == NULL) return NULL;
    while(root->before != NULL) {
        root = root->before;
    }

    toreturn = malloc(sizeof *toreturn);
    if(toreturn == NULL) return NULL;

    toreturn->data = root->data;
    root->next->before = NULL;
    toreturn->next = root->next;
    free(root);
    return toreturn;
}

void d_linkedList_free_recursive(d_linkedList* head) {
    if(head == NULL) return;
    d_linkedList_free_recursive(head->next);
    free(head);
}

void d_linkedList_free(d_linkedList* head) {
    d_linkedList *root = d_linkedList_first(head);
    if(root == NULL) return;
    d_linkedList_free_recursive(root);    
}

d_linkedList* d_linkedList_create_from_list(void* arr, int len, size_t type_size) {
    d_linkedList* head = d_linkedList_createNode(arr);
    if(head == NULL) return NULL;
    for(int i=1; i<len; i++) {
        head = d_linkedList_insert_last(head,d_linkedList_createNode((((char*)arr) + (i) * type_size)));
    }
    return head;
}