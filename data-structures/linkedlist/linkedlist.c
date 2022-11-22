#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct LinkedList{
	struct Node *head;
}LinkedList;

/************************************************
**************    Node functions  ***************
*************************************************
*create
*destroy
*destroyChain
*swapNodeData
*compareNodes
************************************************/

//create a new node with passed data
Node* createNode(int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//destroys a single Node
void destroy(Node **node){
	if(*node == NULL) return;
	free(*node);
	*node = NULL;
}

//Destroys a chain of nodes connected to currentNode
void destroyChain(Node **currentNode){
	if(*currentNode == NULL) return;
	destroyChain(&((*currentNode)->next));
	destroy(currentNode);
}

//swaps the data of two nodes
void swapNodeData(Node **firstNode, Node **secondNode){
	int tmp = (*firstNode)->data;
	(*firstNode)-> data = (*secondNode)->data;
	(*secondNode)->data = tmp;
}

//compares two nodes by data
int compareNodes(Node *firstNode, Node *secondNode){
	return(firstNode-> data ==secondNode->data ? 0 :
			firstNode-> data > secondNode->data ? 1 : -1);
}



/************************************************
***********   Linked List functions  ************
*************************************************
*createList
*init
*insert (0, pos, -1)
*delete (0, pos, -1)
*get  (0, pos, -1)
*clear
*size
*isEmpty
*print
----utilities---------
*merge
*insertMultiple
*find
*sort

0 = front, pos = position, -1 = back
************************************************/

//creates and initiliases an empty linked list
LinkedList* createList(){
	LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
	if(list != NULL){
		list->head = NULL;
	}
	return list;
}

//initiliases an already created linked list
void init(LinkedList **list){
	*list = createList();
}

//insert an element into a linked list
//if position is invalid, insert at back
void insert(LinkedList **list, int data, int position){
	Node *ptrNewNode = createNode(data);
	if((*list)->head == NULL){
		(*list)->head = ptrNewNode;
		return;
	}

	//at head, position = 0
	if(position == 0){
		ptrNewNode->next = (*list)->head;
		(*list)->head = ptrNewNode;
		return;
	}

	int index = 0;
	Node *tmpNode = (*list)->head;
	while(tmpNode->next != NULL){
		if(index == position) break;
		tmpNode = tmpNode->next;
		++index;
	}
	ptrNewNode->next = tmpNode->next;
	tmpNode->next = ptrNewNode;
}

//deletes a node at particluar position
//if position is invalid, deletes last item
void delete(LinkedList **list, int position){
	if((*list)->head == NULL) return;
	
	//at head, position = 0
	if(position == 0){
		Node* tmpNode = (*list)->head;
		(*list)->head = (*list)->head->next;
		destroy(&tmpNode);
	}

	int index = 0;
	Node *currentNode = (*list)->head, *prevNode = (*list)->head;
	while(currentNode->next != NULL){
		if(index == position) break;
		prevNode = currentNode;
		currentNode = currentNode->next;
		++index;
	}

	prevNode->next = currentNode->next;
	destroy(&currentNode);
}

//retrieves the data at position
//if invalid, returns last. If empty list, returns INT_MIN
int get(LinkedList *list, int position){
	if(list->head == NULL) return INT_MIN;
	int index = 0;
	Node *currentNode = list->head;
	while(currentNode->next != NULL){
		if(index == position) break;
		currentNode = currentNode->next;
		++index;
	}
	return currentNode->data;
}

//emptys the linked list
void clear(LinkedList **list){
	destroyChain(&(*list)->head);
}

//returns number of elements in the list
int size(LinkedList *list){
	int count = 0;
	Node *currentNode = list->head;
	while(currentNode != NULL){
		currentNode = currentNode->next;
		++count;
	}
	return count;
}

_Bool isEmpty(LinkedList *list){
	return (list->head == NULL);
}

void print(LinkedList* list){
	Node *tmpNode = list->head;
	printf("List[ ");
	while(tmpNode != NULL){
		printf("%d ", tmpNode->data);
		tmpNode = tmpNode->next;
	}
	printf("]\n");
}

//merges two list
LinkedList* merge(LinkedList **firstList, LinkedList **secondList){
	LinkedList *finalList = *firstList;
	Node *tmpNode = finalList->head;
	while(tmpNode->next != NULL)
		tmpNode = tmpNode->next;
	tmpNode->next = (*secondList)->head;
	return finalList;
}


void insertMultiple(LinkedList **list, int count, ...){
	va_list args;
    va_start(args, count);
 
 	int ind = 0;
 	while(ind < count){
 		int data = va_arg(args, int);
 		insert(list, data, -1);
 		++count;
 	} 
    va_end(args);
}


//returns position if found, else -1
int find(LinkedList *list, int element){
	Node *tmpNode = list->head;
	int index = 0;
	while(tmpNode != NULL){
		if(tmpNode->data == element)
			return index;
		tmpNode = tmpNode->next;
		++index;
	}
	return -1;
}


//sorts linked list: uses selections sort for now
void sort(LinkedList **list, int(*compare)(Node*, Node*)){
	int i, j;
	Node *tmpNode = (*list)->head;
	for(Node* tmpNode = (*list)->head; tmpNode != NULL; tmpNode = tmpNode->next){
		Node *currentNode = tmpNode, *minNode = NULL;
		while(currentNode != NULL){
			if(compare(tmpNode, currentNode) > 0){
				minNode = currentNode;
			}
			currentNode = currentNode->next;
		}
		if(minNode != NULL){
			swapNodeData(&tmpNode, &minNode);
		}
	}
	return;
}



/************************************************
***********   Main Function: Test    ************
*************************************************/

int main(int argc, char const *argv[], char *env[]){
	LinkedList* ptrList = createList();
	insert(&ptrList, 78, -1);
	insert(&ptrList, 789, -1);
	print(ptrList);
	clear(&ptrList);
	print(ptrList);
	printf("\n----------------\n");
	insert(&ptrList, 2345, -1);
	insert(&ptrList, 1, -1);
	insert(&ptrList, 23, 0);
	insert(&ptrList, 0, 1);
	print(ptrList);
	sort(&ptrList, compareNodes);
	print(ptrList);
	free(ptrList);
	return 0;
}


/**
*binary trees
*trees
*graphs

--container ---
set
vector
list
map/dictionary
tuple
string

queue, stack, deque, pqueue
*/

