#ifndef LLIST_H_INCLUDED
#define LLIST_H_INCLUDED

#include <sys/types.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int tickets;
    int job_length;
    int run_count; // Total Timeslices Ran
    char job_id;
    struct Node* next;
} node_t;

node_t* head = NULL; // Initialize Head of Linked List to NULL

void insert(char job_id, int tickets, int job_length) {
    // Insert new node into linked list
    node_t* new_node = (node_t*) malloc(sizeof(node_t)); 
    new_node->tickets = tickets;
    new_node->job_id = job_id;
    new_node->job_length = job_length;
    new_node->next = head;

    if (!head) head = new_node;
    else {
        node_t* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new_node;
        curr->next->next = NULL;
    }   
}

node_t* remove_node(node_t* node) {
    // removes node that is passed into this function
    node_t* temp = node; // Store node in temp object to free memory later
    if (node == head) {
        // If node to be remove is the head, set the next node to be the new head
        if (node->next == NULL) head = NULL; //If only one node in list, head = null
        head = node->next;
        free(temp); // free memory location of removed node
        return head; // return new head
    }
    else {
        node_t* curr = head;
        while (curr->next != node) {
            curr = curr->next; // Traverse to the location before the node to be removed
        }
        curr->next = curr->next->next; // Remove Node and set the previous node's next pointer to next->next
        free(temp); // free memory location of removed node
        return curr->next; // return next node after removed node
    }
    
}

void display() {
    // Display Nodes and Important Properties
    node_t* curr = head;
    if (!curr) printf("Linked List is Empty\n");
    while (curr) {
        printf("Job ID: %c\n", curr->job_id);
        printf("  - Job Length: %d\n", curr->job_length);
        printf("  - Number of Tickets: %d\n", curr->tickets);
        curr = curr->next;
    }
}

#endif