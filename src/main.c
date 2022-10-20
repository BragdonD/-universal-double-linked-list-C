#include <stdio.h>
#include <stdlib.h>
#include "d_linkedlist.h"

void d_linkedList_print_int(d_linkedList* head);
void d_linkedList_print_reverse_int(d_linkedList* head);

int main(int argc, char const *argv[])
{
    d_linkedList* head = d_linkedList_create_from_list((int[]){1,2,3,4,5,6,7,8,9,10}, 10, sizeof(int));
    d_linkedList_print_int(head);
    d_linkedList_free(head);
    return 0;
}

void d_linkedList_print_int(d_linkedList* head) {
    if(head == NULL) return;
    printf("Node value is : %d\n", *(int*)head->data);
    d_linkedList_print_int(head->next);
}

void d_linkedList_print_reverse_int(d_linkedList* head) {
    if(head == NULL) return;
    d_linkedList_print_reverse_int(head->next);
    printf("Node value is : %d\n", *(int*)head->data);
}