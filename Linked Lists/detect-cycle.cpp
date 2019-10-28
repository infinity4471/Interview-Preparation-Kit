/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    if( head == NULL ) return false;
    Node* start_head = head, *prev = NULL;
    while( head->next != NULL ) {
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    if( head == start_head ) return true;
    else return false;
}
