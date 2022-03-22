<a href = "https://cktrace.tistory.com/31">Code Review</a>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumAlgorithmA(int n) {
	// 시간 복잡도 O(1)
	int sum = 0;
	sum = n*(n + 1) / 2;
	//printf("%d\n", sum);
}

int  sumAlgorithmB(int n) {
	// 시간 복잡도 O(n)
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	//printf("%d\n", sum);
}

int sumAlgorithmC(int n) {
	// 시간 복잡도 O(n**2)
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
	// A 알고리즘 시간 체크

	clock_t start, finish;
	double duration;
	start = clock();

	sumAlgorithmA(5); //원하는 n 값 대입

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.30f 초입니다.\n", duration);
	return duration;
}

int timeCheckB() {
	// B 알고리즘 시간 체크

	clock_t start, finish;
	double duration;
	start = clock();

	sumAlgorithmB(5); //원하는 n 값 대입

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.30f 초입니다.\n", duration);
	return duration;
}

int timeCheckC(){
	// C 알고리즘 시간 체크

	clock_t start, finish;
	double duration;
	start = clock();

	sumAlgorithmC(5); //원하는 n 값 대입

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%.30f 초입니다.\n", duration);
	return duration;
}

void main() {
	timeCheckA();
	timeCheckB();
	timeCheckC();
}
