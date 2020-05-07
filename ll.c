#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*Node of the list*/

struct Node
{
	struct Node *next;
	int data;	
};

void addbyint(struct Node **headref, int dat) //addbyint(&head,14);
{
	struct Node *new= (struct Node*)malloc(sizeof(struct Node));
	new->data=dat;
	new->next = *headref;
	*headref = new;
}

void deletebyval(struct Node **headref, int val) /*considering no duplicates*/
{
	//printf("VAL %d \n",val);
	struct Node *temp = *headref, *prev; 
	if(*headref == NULL)
	{
		printf("Cannot delete empty LL! \n");
		return;
	}

	if(temp!=NULL && temp->data==val)
	{
		*headref = temp->next;
		free(temp);
		return;
	}

	else
	{
		while(temp != NULL && temp->data != val)
		{
			prev=temp;
			temp = temp->next;
		}

		if(temp == NULL)
		{
			printf("No data found!\n"); /*traversed to the end without the value matching*/
		}

		else
		{
			prev->next= temp->next;

			free(temp);
		}
	}
}

void deletebypos(struct Node **headref, int pos) //deletebypos(&head,2);
{
	struct Node *temp=*headref,*prev;
	int i=0;

	if(*headref == NULL)
	{
		printf("Cannot delete empty LL! \n");
		return;
	}

	if(pos == 0)
	{
		*headref = temp->next;
		free(temp);
		return;
	}

	else
	{
		while(temp!=NULL && i<pos-1)
		{
			temp = temp->next;
			i++;
		}

		if(temp == NULL || temp->next == NULL)
			return;

		prev= temp->next->next;
		free(temp->next);
		temp->next=prev;
	}
}

void reverse(struct Node **headref) //reverse(&head);	printll(head);
{
	struct Node *current= *headref, *prev = NULL, *next=NULL;

	while(current!=NULL)
	{
		next=current->next;
		current->next = prev;
		prev=current;
		current=next;
	}

	*headref=prev;
}

void retn(struct Node *headref, int n) //retn(head,6);	printll(head);
{

	struct Node *temp = headref, *temp2 = headref, *temp3 = headref;
	int i=0;

	while(i<n-1)
	{
		temp2=temp2->next;
		i++;
	}

	while(temp2->next !=NULL)
	{
		temp2 = temp2->next;
		temp3=temp;
		temp=temp->next;
	}

	printf("nth value: %d \n", temp->data);

	temp3->next = temp->next;
	free(temp);

}

void printll(struct Node *headref)
{
	struct Node *temp = headref;

	while(temp != NULL)
	{
		printf("%d \t", temp->data);
		temp=temp->next;
	}
	printf("\n");
}


void dupli(struct Node **headref) //dupli(&head);	printll(head);
{
	struct Node *temps = *headref;
	struct Node *del = *headref;
	struct Node *h = *headref;

	int i;

	while(temps!=NULL)
	{
		i=0;
		//printf("%d ",temps->data);		
		while(del!=NULL)
		{
			if(temps->data == del->data)
			{
				i++;
				if(i == 2)
				{
					//printf("%d \n",del->data);
					temps=temps->next;
					deletebyval(&h,del->data);
				}
			}
			
			del = del->next;
		}
		del = *headref;
		if(i !=2)
		{
			temps=temps->next;
		}

	}
}

------------------------------***********************************---------------------------

/*CHECK LOOP*/

// C program to detect loop in a linked list 
#include <stdio.h> 
#include <stdlib.h> 

/* Link list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 
int detectloop(struct Node* list) 
{ 
	struct Node *slow_p = list, *fast_p = list; 

	while (slow_p && fast_p && fast_p->next) { 
		slow_p = slow_p->next; 
		fast_p = fast_p->next->next; 
		printf("LOOPING: %d, %d\n",slow_p->data,fast_p->data);
		if (slow_p == fast_p) { 
			printf("Found Loop \n"); 
			return 1; 
		} 
	} 
	return 0; 
} 

/* Driver program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 
	push(&head, 20); 
	push(&head, 4); 
	push(&head, 7);
	push(&head, 8);

	/* Create a loop for testing */
	head->next->next->next = head; 
	detectloop(head); 
	return 0; 
} 
------------------********************************---------------------

/*QUEUE*/

#include <stdio.h> 
#include <stdlib.h> 

// A linked list (LL) node to store a queue entry 
struct QNode { 
	int key; 
	struct QNode* next; 
}; 

// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
struct Queue { 
	struct QNode *front, *rear; 
}; 

// A utility function to create a new linked list node. 
struct QNode* newNode(int k) 
{ 
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
	temp->key = k; 
	temp->next = NULL; 
	return temp; 
} 

// A utility function to create an empty queue 
struct Queue* createQueue() 
{ 
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	return q; 
} 

// The function to add a key k to q 
void enQueue(struct Queue* q, int k) //	struct Queue* q = createQueue(); enQueue(q, 10); //first in
{ 
	// Create a new LL node 
	struct QNode* temp = newNode(k); 

	// If queue is empty, then new node is front and rear both 
	if (q->rear == NULL) { 
		q->front = q->rear = temp; 
		return; 
	} 

	// Add the new node at the end of queue and change rear 
	q->rear->next = temp; 
	q->rear = temp; 
} 

// Function to remove a key from given queue q 
void deQueue(struct Queue* q) //deQueue(q); 
{ 
	// If queue is empty, return NULL. 
	if (q->front == NULL) 
		return; 

	// Store previous front and move front one node ahead 
	struct QNode* temp = q->front; 

	q->front = q->front->next; 

	// If front becomes NULL, then change rear also as NULL 
	if (q->front == NULL) 
		q->rear = NULL; 

	free(temp); 
} 

//merge two ll
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
void mergecall(struct Node *ht1,struct Node *ht2, struct Node *ht3)
{
	struct Node *h1 = ht1;
	struct Node *h2 = ht2;
	struct Node *h3 = ht3;
	int num=0;
	while(num <= 8)
	{
		if(h1->data <= h2->data)
		{
			addbyint(&h3,h1->data);
			h1 = h1->next;
		}
		else
		{
			addbyint(&h3,h2->data);
			h2 = h2->next;
		}
		num++;

		printf("%d ", h3->data);
}
}
