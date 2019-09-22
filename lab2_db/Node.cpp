#include "Node.h"

Node* list1_head = NULL;
Node* list2_head = NULL;
Node* list3_head = NULL;

void create(Node** head_ref)
{
	bool more = true;
	while (more)
	{
		Node* temp = new Node;
		if (!temp)
			break;

		std::cout << "Input integer data: ";
		std::string ans;
		std::cin >> ans;
		if (ans == "stop")
		{
			more = false;
			break;
		}
		temp->data = std::stoi(ans);

		temp->next = NULL;

		if (!*head_ref)
			* head_ref = temp;
		else
		{
			Node* trav = *head_ref;

			while (trav->next)
				trav = trav->next;

			trav->next = temp;
		}
	}
}

void push(Node** head_ref, int new_data)
{
	Node* temp = new Node;
	if (!temp)
		return;

	temp->data = new_data;
	temp->next = *head_ref;
	*head_ref = temp;
}

void insert_after(Node** head_ref, int index, int new_data)
{
	Node* prev = *head_ref;

	for (int i = 0; i < index; i++)
	{
		prev = prev->next;
	}

	if (!prev)
	{
		std::cout << "Previous node is NULL." << std::endl;
		return;
	}

	Node* temp = new Node;
	if (!temp)
		return;

	temp->data = new_data;
	temp->next = prev->next;
	prev->next = temp;
}

void append(Node** head_ref, int new_data)
{
	Node* temp = new Node;
	if (!temp)
		return;

	temp->data = new_data;
	temp->next = NULL;

	if (!*head_ref)
	{
		*head_ref = temp;
		return;
	}

	Node* trav = *head_ref;
	while (trav->next)
		trav = trav->next;

	trav->next = temp;
}

void print(Node* head_ref)
{
	Node* trav = head_ref;
	std::cout << "***** LINKED LIST *****" << std::endl;
	while (trav)
	{
		std::cout << " " << trav->data;
		trav = trav->next;
	}
}

void delete_node_by_index(Node** head_ref, int index)
{
	if (!*head_ref)
		return;

	Node* trav = *head_ref;

	if (index == 0)
	{
		*head_ref = trav->next;
		delete trav;
	}

	// Find previous node of the node to be deleted.
	for (int i = 0; trav && i < index - 1; i++)
		trav = trav->next;

	// If position is more than number of nodes.
	if (!trav || !trav->next)
		return;

	// Node trav->next is the node to be deleted.
	// Store pointer to the next of node to be deleted.
	Node* next = trav->next->next;

	delete(trav->next);

	trav->next = next;
}

void delete_every_nth_node(Node** head_ref, int n)
{
	if (!*head_ref)
		return;

	if (n == 1)
	{
		delete_list(&list1_head);
		return;
	}

	Node* trav = *head_ref;
	Node* prev = NULL;

	int count = 0;
	while (trav != NULL)
	{
		count++;

		if (n == count)
		{
			prev->next = trav->next;
			delete(trav);
			trav = prev->next;

			count = 0;
		}

		// update prev if count is not 0 
		if (count != 0)
			prev = trav;

		trav = prev->next;
	}
}

void delete_list(Node** head_ref)
{
	Node* current = *head_ref;
	Node* next;

	while (current)
	{
		next = current->next;
		delete current;
		current = next;
	}

	*head_ref = NULL;
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra node should go in the front list.
	Uses the fast/slow pointer strategy. */
void front_back_split(Node* source, Node** front_ref,
	struct Node** back_ref)
{
	struct Node* fast;
	struct Node* slow;
	if (source == NULL || source->next == NULL)
	{
		/* length < 2 cases */
		*front_ref = source;
		*back_ref = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;

		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		/* 'slow' is before the midpoint in the list,
			so split it in two at that point. */
		*front_ref = source;
		*back_ref = slow->next;
		slow->next = NULL;
	}
}

/* See https://www.geeksforgeeks.org/?p=3622 for details
   of this function */
Node* sorted_merge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	/* Pick either a or b, and recur */
	if (a->data <= b->data)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return result;
}


/* sorts the linked list by changing next pointers
  (not data) */
void merge_sort(Node** head_ref)
{
	Node* head = *head_ref;
	Node* a;
	Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL))
		return;

	/* Split head into 'a' and 'b' sublists */
	front_back_split(head, &a, &b);

	/* Recursively sort the sublists */
	merge_sort(&a);
	merge_sort(&b);

	/* answer = merge the two sorted lists together */
	*head_ref = sorted_merge(a, b);
}

/* Function to get union of two linked lists head1 and head2 */
Node* get_union(Node* head1, Node* head2)
{
	merge_sort(&head1);
	merge_sort(&head2);

	Node* result = NULL;
	Node* t1 = head1, * t2 = head2;

	// Traverse both lists and store the  element in 
	// the resu1tant list 
	while (t1 != NULL && t2 != NULL)
	{
		// Move to the next of first list 
		// if its element is smaller 
		if (t1->data < t2->data)
		{
			push(&result, t1->data);
			t1 = t1->next;
		}

		// Else move to the next of second list 
		else if (t1->data > t2->data)
		{
			push(&result, t2->data);
			t2 = t2->next;
		}

		// If same then move to the next node 
		// in both lists 
		else
		{
			push(&result, t2->data);
			t1 = t1->next;
			t2 = t2->next;
		}
	}

	/* Print remaining elements of the lists */
	while (t1 != NULL)
	{
		push(&result, t1->data);
		t1 = t1->next;
	}
	while (t2 != NULL)
	{
		push(&result, t2->data);
		t2 = t2->next;
	}

	return result;
}

/* Function to get intersection of two linked lists
head1 and head2 */
Node* get_intersection(Node* head1, Node* head2)
{
	merge_sort(&head1);
	merge_sort(&head2);

	Node* result = NULL;
	Node* t1 = head1, * t2 = head2;

	// Traverse both lists and store the same element 
	// in the resu1tant list 
	while (t1 != NULL && t2 != NULL)
	{
		// Move to the next of first list if smaller 
		if (t1->data < t2->data)
			t1 = t1->next;

		// Move to the next of second list if it is smaller 
		else if (t1->data > t2->data)
			t2 = t2->next;

		// If both are same 
		else
		{
			// Store current element in the list 
			push(&result, t2->data);

			// Move to the next node of both lists 
			t1 = t1->next;
			t2 = t2->next;
		}
	}

	//return the resultant list 
	return result;
}

void move_node(Node** head_ref, int index, int n)
{
	if (!*head_ref || !(*head_ref)->next)
		return;

	Node* prev = NULL;
	Node* curr = *head_ref;

	for (int i = 0; curr && i < index; i++)
	{
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;

	for (int i = 0; curr->next->next && i < n; i++)
	{
		curr->next = curr->next->next;
		prev = prev->next;
	}

	prev->next = curr;
}

Node* clone_list(struct Node* head)
{
	Node* current = head;
	Node* new_list = NULL;
	Node* tail = NULL;

	while (current)
	{
		if (!new_list)
		{
			push(&new_list, current->data);
			tail = new_list;
		}
		else
		{
			push(&(tail->next), current->data);
			tail = tail->next;
		}
		current = current->next;
	}

	return new_list;
}