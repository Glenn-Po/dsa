#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct Node{
	int data;
	struct Node *next, *previous;
}Node;

typedef struct DoublyLinkedList{
	struct Node *head;
}DoublyLinkedList;

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
	newNode->next = newNode->previous = NULL;
	return newNode;
}

//destroys a single Node
void destroy(Node **node){
	if(*node == NULL) return;
	free(*node);
	*node = NULL;
}

//Destroys a chain of nodes connected from currentNode
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
******* Doubly Linked List functions  ***********
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

//creates and initiliases an empty linked dList
DoublyLinkedList* createList(){
	DoublyLinkedList *dList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	if(dList != NULL){
		dList->head = NULL;
	}
	return dList;
}

//initiliases an already created linked dList
void init(DoublyLinkedList **dList){
	*dList = createList();
}

//insert an element into a linked dList
//if position is invalid, insert at back
void insert(DoublyLinkedList **dList, int data, int position){
	Node *ptrNewNode = createNode(data);
	if((*dList)->head == NULL){
		(*dList)->head = ptrNewNode;
		return;
	}

	//at head, position = 0
	if(position == 0){
		(*dList)->head->previous = ptrNewNode;
		ptrNewNode->next = (*dList)->head;
		(*dList)->head = ptrNewNode;
		return;
	}

	int index = 0;
	Node *tmpNode = (*dList)->head;
	while(tmpNode->next != NULL){
		if(index == position) break;
		tmpNode = tmpNode->next;
		++index;
	}
	ptrNewNode->next = tmpNode->next;
	tmpNode->next = ptrNewNode;
}
