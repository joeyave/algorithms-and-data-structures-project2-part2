#pragma once
#include <fstream>
#include <iostream>
#include <string>

struct Node
{
	int data;
	Node* next;
};

extern Node* list1_head;
extern Node* list2_head;
extern Node* list3_head;

// Create a list.
void create(Node** head_ref);

//Add a node at the front of the list.
void push(Node** head_ref, int new_data);

// Add a node after a given node.
void insert_after(Node** head_ref, int index, int new_data);

// Add a node to the end of the list.
void append(Node** head_ref, int new_data);

// Print the list.
void print(Node* head_ref);

// Delete a node at the given position.
void delete_node_by_index(Node** head_ref, int index);

// Delete every Nth node.
void delete_every_nth_node(Node** head_ref, int n);

// Delete a list.
void delete_list(Node** head_ref);

// Sort list.
void merge_sort(Node** head_ref);

Node* get_intersection(Node* head1, Node* head2);

Node* get_union(Node* head1, Node* head2);

// Move node by N.
void move_node(Node** head_ref, int index, int n);

//Clone a list.
Node* clone_list(struct Node* head);


