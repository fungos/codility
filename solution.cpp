#include <stdio.h>

int solution(int N)
{
	if (N == 0)
		return 1;

	return N*N;
}

int main(int, char **)
{
	for (int i = 0; i < 10;++i)
		printf("%d -> %d\n", i, solution(i));
	return 0;
}

