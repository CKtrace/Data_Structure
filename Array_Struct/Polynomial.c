#include <stdio.h>
#define MAX_DEGREE 101

typedef struct{
	int degree; // 차수
	float coef[MAX_DEGREE]; //coef 계수 배열
}Polynomial;

void view_poly(Polynomial p, char str[]){
	printf("\t%s", str);
	for (int i = 0; i < p.degree; i++)
	{
		if (p.coef[i] != 0)
		{
			printf("%5.1f x^%d + ", p.coef[i], p.degree - i);
		}
	}
	printf("%4.1f\n", p.coef[p.degree]);
}

Polynomial read_poly(){
	Polynomial p;

	printf("다항식의 최고 차수를 입력하시오 ");
	scanf_s("%d", &p.degree);
	printf("각 항의 계수를 입력하시오(총 %d개 입력!)\n", p.degree + 1);
	for (int i = 0; i <= p.degree; i++)
	{
		scanf_s("%f", &p.coef[i]);
	}
	return p;
}

Polynomial add_poly(Polynomial a, Polynomial b) {
	Polynomial p;

	if (a.degree > b.degree)
	{
		p = a;
		for (int i = 0; i <= b.degree; i++)
		{
			p.coef[i + (p.degree-b.degree)] += b.coef[i];
		}
	}
	else
	{
		p = b;
		for (int i = 0; i <= a.degree; i++)
		{
			p.coef[i + (p.degree - a.degree)] += a.coef[i];
		}
	}
	return p;
}

Polynomial sub_poly(Polynomial a, Polynomial b) {
	Polynomial p;

	if (a.degree > b.degree)
	{
		p = a;
		for (int i = 0; i <= b.degree; i++)
		{
			p.coef[i + (a.degree - b.degree)] -= b.coef[i];
		}
	}
	else
	{
		if (a.degree == b.degree)
		{
			p = a;
			for (int i = 0; i <= b.degree; i++)
			{
				p.coef[i] -= b.coef[i];
			}
		}
		else
		{
			p = b;
			for (int  i = 0; i <= a.degree; i++)
			{
				p.coef[i + (b.degree - a.degree)] -= a.coef[i];
			}
			for (int q = 0; q <= p.degree; q++)
			{
				p.coef[q] = -p.coef[q];
			}
		}
	}
	return p;
}

Polynomial mult_poly(Polynomial a, Polynomial b)
{
	Polynomial p;

	p.degree = a.degree + b.degree;

	for (int z = 0; z <= p.degree ; z++)
	{
		p.coef[z] = 0;
	}

	for (int i = 0; i <= a.degree; i++)
	{
		for (int j = 0; j<= b.degree; j++) 
		{
			p.coef[i + j] += a.coef[i] * b.coef[j];
		}
	}
	return p;
}

void trimPoly(Polynomial* p) {
	while (1){

		if (p->coef[0] == 0)
		{
			for (int z = 0; z <= p->degree; z++)
			{
				p->coef[z] = p->coef[z + 1];
			}
			p->degree--;
		}
		else
		{
			break;
		}
	}
}

void main()
{
	// 계산하고자 하는 다항식을 구조체로 선언하시고 함수를 이용해 계산하시면 됩니다!
}
