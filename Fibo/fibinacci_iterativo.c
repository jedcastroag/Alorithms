#include <stdio.h>

long long fibo(long n)
{
	if (n == 0)
	{
		return 0;
	}
	long long f0 = 0, f1 = 1, temp = 0; 
	for (long i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

int main()
{
	long n;
	scanf(" %li", &n);
	printf("%lli\n", fibo(n));
	return 0;
}