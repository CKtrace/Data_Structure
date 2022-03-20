#include <stdio.h>
#define MAX_TERMS 101

typedef struct{
	int expon; //exponent : 지수
	float coeff;  // coefficient : 계수
}Term;

typedef struct {
	int nTerms; // 항의 개수
	Term term[MAX_TERMS];
} SparsePoly;

SparsePoly read_spoly()
{
	SparsePoly p;

	printf("다항식의 항의 개수를 입력하시오 ");
	scanf_s("%d", &p.nTerms);

	for (int i = 0; i <p.nTerms; i++)
	{
		printf("지수를 입력하세요! ");
		scanf_s("%d", &p.term[i].expon);
		printf("계수를 입력하세요! ");
		scanf_s("%f", &p.term[i].coeff);
	}
	return p;
}

void  printSpoly(SparsePoly a, char str[])
{
	printf("\t%s", str);
	for (int i = 0; i < a.nTerms - 1; i++)
	{
		printf("%5.1f x^%d + ", a.term[i].coeff, a.term[i].expon);
	}
	if (a.term[a.nTerms - 1].expon != 0)
	{
		printf("%5.1f x^%d ", a.term[a.nTerms - 1].coeff, a.term[a.nTerms - 1].expon);
	}
	else
	{
		printf("%5.1f ", a.term[a.nTerms - 1].coeff);
	}
}

SparsePoly add_poly(SparsePoly a,SparsePoly b)
{
 // 실력 발전 후 다시 시도할 예정입니다.
}

void main() 
{
	SparsePoly a, b;
	a = read_spoly();
	b = read_spoly();
	printSpoly(a, " a = ");
	printSpoly(b, " b = ");
}
