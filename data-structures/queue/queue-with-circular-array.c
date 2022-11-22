


/**********************************************
***** Queue Data Structure Implementation  ****
***********************************************
***** Author:  Nfor Glen Yinyu, FE21A253  *****
***********************************************
***********************************************/

#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE  5


typedef struct{
	int rear , front;
	int container[QUEUE_SIZE];
} Queue;


/**********************************************
** Queue Operations and utility functions *****
***********************************************/

Queue create();
int peekHead(Queue quueue);
int peekTail(Queue queue);
int dequeue(Queue* queue);
void enqueue(Queue* queue, int data);
int size(Queue queue);
void print(Queue queue);
int isEmpty(Queue queue);
int isFull(Queue queue);



//create a new queue object
Queue create(){
	Queue queue;
	queue.front = 0;
	queue.rear = -1;
	return queue;
}

//returns the element at head of the queue
int peekHead(Queue queue){
	return queue.container[queue.front];
}

//returns the elements at the tail of the queue
int peekTail(Queue queue){
	return queue.container[queue.rear];
}

//removes and returns the element at the head of the queue
int dequeue(Queue* queue){
	//get the element
	int dequeuedElement = queue->container[queue->front];
	queue->front = (queue->front + 1) % QUEUE_SIZE;
	return dequeuedElement;
}

//adds element to the tail of the queue
void enqueue(Queue* queue, int data){
	queue->rear = (queue->rear + 1) % QUEUE_SIZE;
	queue->container[queue->rear] = data;
}

//returns the size of the queue
int size(Queue queue){      
	if(queue.rear < queue.front && queue.rear > -1)
		return (queue.rear  +  QUEUE_SIZE - queue.front);
	return (queue.rear - queue.front + 1);
}

//displays the queue
void print(Queue queue){
	printf("Queue: Head[");
	int ind = queue.front; 
	while(ind <= queue.rear % QUEUE_SIZE)
		printf(" %d", queue.container[ind++]);
	printf(" ]Tail \n");
}


///checks if the queue is empty
int isEmpty(Queue queue){
	return (queue.front > queue.rear  && queue.rear == -1);
}

//checks if the queue is full
int isFull(Queue queue){
	return ((queue.rear + 1) % QUEUE_SIZE == queue.front && queue.rear != -1);
}


/*******************************************************
************ Test Function [main] **********************
*******************************************************/

int main(){
	Queue queue = create();
	do{
		printf("\n[---- Queue Operations ----]\n");
		print(queue);
		printf("Head = %d  | Tail = %d | Size = %d\n", queue.front, queue.rear, size(queue));
		printf("1.Enqueue  2.Dequeue  3.Peek Head 4.Peek Tail\n"
			   "5.Size 6.Display 0.Exit\nChoose: ");

		int choice, data;
		scanf("%d", &choice);
		switch(choice){
			case 0:
				system("pause");
				exit(EXIT_SUCCESS);

			case 1:
				if(isFull(queue)){
					printf("[Queue Overflow Error] - Queue is full\n");
					continue;
				}
				printf("Enter the new element: ");
				scanf("%d", &data);
				enqueue(&queue, data);
				break;

			case 2:
				if(isEmpty(queue)){
					printf("[Queue Underflow Error] - Queue is empty\n");
					continue;
				}
				data = dequeue(&queue);
				printf("Element %d has been dequeued from the queue.\n", data);
				break;

			case 3:
				if(isEmpty(queue)){
					printf("[Queue Underflow Error] - Queue is empty\n");
					continue;
				}
				data = peekHead(queue);
				printf("Element %d is at the head of the queue.\n", data);
				break;

			case 4:
				if(isEmpty(queue)){
					printf("[Queue Underflow Error] - Queue is empty\n");
					continue;
				}
				data = peekTail(queue);
				printf("Element %d is at the tail of the queue.\n", data);
				break;

			case 5:
				int queueSize = size(queue);
				printf("The queue has %d element%s\n", queueSize, queueSize == 1 ? "" : "s");
				break;

			case 6:
				printf("\n Queue Info: Size:%d  ", size(queue));
				print(queue);
				break;

			default:
				printf("[Error] - Cannot recognise this command\n");
		}
	} while(1);
	return 0;
}