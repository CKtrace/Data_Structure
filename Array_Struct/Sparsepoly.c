#include <stdio.h>
#define MAX_TERMS 101

typedef struct {
	int expon; //exponent : 지수
	float coeff;  // coefficient : 계수
} Term;

typedef struct {
	int nTerms; // 항의 개수
	Term term[MAX_TERMS];
} SparsePoly;

SparsePoly read_spoly()
{
	SparsePoly p;

	printf("다항식의 항의 개수를 입력하시오 ");
	scanf_s("%d", &p.nTerms);

	for (int i = 0; i < p.nTerms; i++)
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

SparsePoly add_Spoly(SparsePoly a, SparsePoly b)
{
	SparsePoly p;
	int a1 = 0; 
	int a2 = 0; 
	int newterm = 0;
	int cnt = 0;
	int i;
	
	newterm = a.nTerms + b.nTerms;

	for (i = 0; i < newterm; i++)
	{
		if ((a1 >= a.nTerms) || a2 >= b.nTerms) {
			break;
		}
		if (a.term[a1].expon == b.term[a2].expon)
		{
			p.term[i].coeff = a.term[a1].coeff + b.term[a2].coeff;
			p.term[i].expon = a.term[a1].expon;
			a1++;
			a2++;
		}
		else if (a.term[a1].expon > b.term[a2].expon)
		{
			p.term[i].expon = a.term[a1].expon;
			p.term[i].coeff = a.term[a1].coeff;
			a1++;
		}
		else
		{
			p.term[i].expon = b.term[a2].expon;
			p.term[i].coeff = b.term[a2].coeff;
			a2++;
		}
	}
	for (; a1 < a.nTerms; a1++)
	{
		p.term[i].expon = a.term[a1].expon;
		p.term[i].coeff = a.term[a1].coeff;
		i++;
	}
	for (; a2 < b.nTerms; a2++)
	{
		p.term[i].expon = b.term[a2].expon;
		p.term[i].coeff = b.term[a2].coeff;
		i++;
	}
	p.nTerms = i;

	return p;
}

void main()
{
	SparsePoly a, b, c;
	a = read_spoly();
	b = read_spoly();
	c = add_Spoly(a, b);
	printSpoly(c, "C = ");
}
