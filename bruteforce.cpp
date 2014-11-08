#include <stdio.h>

int solution(int N)
{
	int count = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			++count;	
		}
	}

	return count;
}

int main(int, char **)
{
	for (int i = 0; i < 10;++i)
		printf("%d -> %d\n", i, solution(i));
	return 0;
}
