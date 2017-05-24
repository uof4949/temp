#include <stdio.h>
#include <malloc.h>

typedef int element;        //int�� ���� element�� �ڷ������� ����

typedef struct  stackNode {  //������ ��� ���� ����
	element data;
	struct stackNode *link;
}stackNode;

stackNode* top = NULL;     //������ top ��带 �����ϱ� ���� ������ top ����

void push(element item) //������ ���� ����
{
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()      //������ ���� �� ��ȯ ����
{
	element item;
	stackNode* temp = top;

	if (top == NULL) {   //���� ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {               //���� ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

element peek()        //������ top ���� �˻� ����
{
	element item;
	if (top == NULL) {   //���� ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {              //���� ������ ���� ����Ʈ�� �ƴ� ���
		item = top->data;
		return item;
	}
}

void del()              //������ ���� ���� pop
{
	stackNode* temp;
	if (top == NULL) {    //���� ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
	}
	else {              //���� ������ ���� ����Ʈ�� �ƴ� ���
		temp = top;
		top = top->link;
		free(temp);
	}
}

void printStack()        //������ ���� ��� ����
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}


void printTotal()        //������ ���� �ּ� ��� ����
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%3d  %u ", p->data, p);
		p = p->link;
	}
	printf("] ");
}

void reverse() { //���� ������ [��ũ�帮��Ʈ ������ �̿���]
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
		printf("\n���� ��ɰ� ������ ���� �Է��Ͻÿ�\n");
		scanf("%d", &sel);
		rewind(stdin);

		if (sel == 1) {
			scanf("%d", &item);
			reverse(); // ������ ���ĵ� �� �ٽ� ���� �� ����
			push(item);
			push(item*item);
			reverse(); // ������
			printStack();
			printf("\n");

		}

		else if (sel == 2) {
			reverse();// �������ؾ� pop���� ���� ��µ� �Ͱ� �����ϰ� �����
			sum = pop();
			sum += pop();

			printf("pop => %d\n", sum);
			reverse(); // ����� ���� �� ����
			printStack();
			printf("\n");
		}
		else if (sel == 3) {
			// �������� ���ϴ� ������ �̹� select 1,2 ���� ��� �� ������ �Ǿ��⿡ ���ʿ�
			printTotal();
			printf("\n");
		}


		else if (sel == -1) {
			printf("�����մϴ�.\n");
			break;
		}
	}

}