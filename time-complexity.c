#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumAlgorithmA(int n) {
	// �ð� ���⵵ O(1)
	int sum = 0;
	sum = n*(n + 1) / 2;
	//printf("%d\n", sum);
}

int  sumAlgorithmB(int n) {
	// �ð� ���⵵ O(n)
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	//printf("%d\n", sum);
}

int sumAlgorithmC(int n) {
	// �ð� ���⵵ O(n**2)
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int a = 1; a <= i; a++) {
			sum++;
		}
	}
	//printf("%d\n", sum);
}

int timeCheckA() {
	// A �˰��� �ð� üũ

	clock_t start, finish;
	double duration;
	start = clock();

	sumAlgorithmA(5); //���ϴ� n �� ����

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.30f ���Դϴ�.\n", duration);
	return duration;
}

int timeCheckB() {
	// B �˰��� �ð� üũ

	clock_t start, finish;
	double duration;
	start = clock();

	sumAlgorithmB(5); //���ϴ� n �� ����

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.30f ���Դϴ�.\n", duration);
	return duration;
}

int timeCheckC(){
	// C �˰��� �ð� üũ

	clock_t start, finish;
	double duration;
	start = clock();

	sumAlgorithmC(5); //���ϴ� n �� ����

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.30f ���Դϴ�.\n", duration);
	return duration;
}

int main() {
	timeCheckA();
	timeCheckB();
	timeCheckC();
}