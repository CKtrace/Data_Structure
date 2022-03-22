/*
조건 1 : 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 한다.
조건 2 : 같은 타입의 괄호에서 왼쪽 괄호는 오른쪽 괄호보다 먼저 나와야 한다.
조건 3 : 서로 다른 타입의 괄호 쌍이 서로를 교차하면 안된다.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // 스택 요소 저장을 위한 배열의 크기
typedef int Element; // 스택 요소의 자료형 정의

Element data[MAX_STACK_SIZE]; // 실제 스택 요소의 배열
int top; //실제 스택의 탑

void error(char str[]) // 오류 상황 처리를 위한 함수로써 메시지 출력 후 프로그램 종료
{
	printf("%s\n", str);
	exit(1);
}

void init_stack() // 스택 초기화 함수
{
	top = -1;
}

int is_empty() // 스택 비어있는지 확인 함수 
{
	return top == -1;
}

int is_full() // 스택 꽉 차 있는지 확인 함수
{
	return top == MAX_STACK_SIZE;
}

int size() // 스택 내의 요소 개수 반환 함수
{
	return top + 1;
}

void push(Element a) // 스택 맨 위 요소 추가
{
	if (is_full())
	{
		error("스택 포화 에러");
	}
	data[++top] = a;
}

Element pop() // 스택 맨 위 요소 삭제
{
	if (is_empty())
	{
		error("스택 공백 에러");
	}
	return data[top--];
}

Element peek() // 스택 맨 위 요소 삭제 안하고 반환
{
	if (is_empty)
	{
		error("스택 공백 에러");
	}
	return data[top];
}

int check_matching(char filename[]) // 파일을 처리할 수 있도록 수정
{
	FILE* fp;
	fopen_s(&fp, filename, "r");

	if (fp == NULL)
	{
		printf("FILE OPEN ERROR\n");
		exit(0);
	}

	int i = 0, prev_check;
	char ch;

	init_stack();

	do {
		ch = fgetc(fp);

		if (ch == '[' || ch == '{' || ch == '(')
		{
			push(ch);
		}
		else if (ch == '39')
		{
			
		}
		else if (ch == ']' || ch == '}' || ch == ')')
		{
			if (is_empty()) {
				return 2;
			}
			prev_check = pop();
			if ((ch == ']' && prev_check != '[') || (ch == '}' && prev_check != '{') || (ch == ')' && prev_check != '(')) {
				return 3;
			}
		}
	} while (ch != EOF);

	if (is_empty() == 0) //비어 있지 않은 경우
	{
		return 1;
	}

	fclose(fp);

	return 0;
}

void main()
{
	char filename[200] = "filecheck.txt";

	int err_code;

	for (int i = 0; i < 1; i++)
	{
		err_code = check_matching(filename);
		if (err_code == 0)
		{
			printf("정상입니다\n");
		}
		else
		{
			printf("오류입니다.\n");
		}
	}
}
