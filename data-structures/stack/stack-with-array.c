
/**********************************************
***** Stack Data Structure Implementation  ****
***********************************************
***** Author:  Nfor Glen Yinyu, FE21A253  *****
***********************************************
***********************************************/

#include<stdio.h>
#include <stdlib.h>
#define STACK_SIZE  200


typedef struct{
	int pointer;
	int container[STACK_SIZE];
} Stack;

/**********************************************
** Stack Operations and utility functions *****
***********************************************/

Stack create();

int peek(Stack stack);

int pop(Stack* stack);

void push(Stack* stack, int data);

int size(Stack stack);

void print(Stack stack);

int isEmpty(Stack stack);

int isFull(Stack stack);



//create a new stack object
Stack create(){
	Stack stack;
	stack.pointer = -1;
	return stack;
}

//returns the element at the top of the stack
int peek(Stack stack){
	return stack.container[stack.pointer];
}

//removes and returns the top element of the stack
int pop(Stack* stack){
	return stack->container[stack->pointer--];
}

//pushes an element to the top of the stack
void push(Stack* stack, int data){
	stack->container[++stack->pointer] = data;
}

//displays the elements of the stack
void print(Stack stack){
	printf("Stack: Bottom[");
	int ind = 0; 
	while(ind <= stack.pointer)
		printf(" %d", stack.container[ind++]);
	printf(" ]Top \n");
}

//returns the number of elements in the stack
int size(Stack stack){
	return stack.pointer >= 0 ? stack.pointer + 1 : 0;
}

//checks if the stack is empty
int isEmpty(Stack stack){return (stack.pointer < 0);}

//checks if the stack is full
int isFull(Stack stack){return (stack.pointer >= STACK_SIZE);}



/*******************************************************
************ Test Function [main] **********************
*******************************************************/

int main(){
	Stack stack = create();
	do{
		printf("\n[---- Stack Operations ----]\n");
		print(stack);
		printf("1.Push  2.Pop  3.Peek 4.Size 5.Display 0.Exit\n");

		int choice, data;
		scanf("%d", &choice);
		switch(choice){
			case 0:
				system("pause");
				exit(EXIT_SUCCESS);

			case 1:
				if(isFull(stack)){
					printf("[Stack Overflow Error] - Stack is full\n");
					continue;
				}
				printf("Enter the new element: ");
				scanf("%d", &data);
				push(&stack, data);
				break;

			case 2:
				if(isEmpty(stack)){
					printf("[Stack Underflow Error] - Stack is empty\n");
					continue;
				}
				data = pop(&stack);
				printf("Element %d has been popped from the stack.\n", data);
				break;

			case 3:
				if(isFull(stack)){
					printf("[Stack Underflow Error] - Stack is empty\n");
					continue;
				}
				data = peek(stack);
				printf("Element %d is at the top of the stack.\n", data);
				break;

			case 4:
				int stackSize = size(stack);
				printf("The stack has %d element%s\n", stackSize, stackSize == 1 ? "" : "s");
				break;

			case 5:
				printf("\nStack Info: Size:%d  ", size(stack));
				print(stack);
				break;

			default:
				printf("[Error] - Cannot recognise this command\n");
				system("pause");
				exit(0);
		}
	}while(1);
	return 0;
}