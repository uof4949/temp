#include <stdio.h>
#include <malloc.h>

typedef int element;        //int를 스택 element의 자료형으로 정의

typedef struct  stackNode {  //스택의 노드 구조 정의
	element data;
	struct stackNode *link;
}stackNode;

stackNode* top = NULL;     //스택의 top 노드를 지정하기 위한 포인터 top 선언

void push(element item) //스택의 삽입 연산
{
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()      //스택의 삭제 후 반환 연산
{
	element item;
	stackNode* temp = top;

	if (top == NULL) {   //현재 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {               //현재 스택이 공백 리스트가 아닌 경우
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek()        //스택의 top 원소 검색 연산
{
	element item;
	if (top == NULL) {   //현재 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {              //현재 스택이 공백 리스트가 아닌 경우
		item = top->data;
		return item;
	}
}

void del()              //스택의 삭제 연산 pop
{
	stackNode* temp;
	if (top == NULL) {    //현재 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
	}
	else {              //현재 스택이 공백 리스트가 아닌 경우
		temp = top;
		top = top->link;
		free(temp);
	}
}

void printStack()        //스택의 내용 출력 연산
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}


void printTotal()        //스택의 내용 주소 출력 연산
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%3d  %u ", p->data, p);
		p = p->link;
	}
	printf("] ");
}

void reverse() { //스택 역정렬 [링크드리스트 역정렬 이용한]
	stackNode* p;
	stackNode* q;
	stackNode* r;

	p = top;
	q = NULL;
	r = NULL;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	top = q;
}

void main(void)
{
	element item;
	int sel, sum;


	while (1) {
		printf("\n선택 기능과 데이터 값을 입력하시오\n");
		scanf("%d", &sel);
		rewind(stdin);

		if (sel == 1) {
			scanf("%d", &item);
			reverse(); // 위에서 정렬된 것 다시 정렬 후 연산
			push(item);
			push(item*item);
			reverse(); // 역정렬
			printStack();
			printf("\n");

		}

		else if (sel == 2) {
			reverse();// 역정렬해야 pop값이 위에 출력된 것과 동일하게 연산됨
			sum = pop();
			sum += pop();

			printf("pop => %d\n", sum);
			reverse(); // 출력을 위한 재 정렬
			printStack();
			printf("\n");
		}
		else if (sel == 3) {
			// 역정렬을 안하는 이유는 이미 select 1,2 에서 출력 후 역정렬 되었기에 불필요
			printTotal();
			printf("\n");
		}


		else if (sel == -1) {
			printf("종료합니다.\n");
			break;
		}
	}

}