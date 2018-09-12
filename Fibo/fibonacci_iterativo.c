#include <stdio.h>
#include <math.h>

unsigned long long fibo_long_long_u(unsigned long long n)
{
	if (n == 0)
	{
		return 0;
	}
	unsigned long long f0 = 0, f1 = 1, temp = 0; 
	for (unsigned long long i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

unsigned long fibo_long_u(unsigned long n)
{
	if (n == 0)
	{
		return 0;
	}
	unsigned long  f0 = 0, f1 = 1, temp = 0; 
	for (unsigned long i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

long double fibo_double_u(long double n)
{
	if (n == 0)
	{
		return 0;
	}
	long double  f0 = 0, f1 = 1, temp = 0; 
	for (long double i = 1.0; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

unsigned int fibo_int_u(unsigned int n)
{
	if (n == 0)
	{
		return 0;
	}
	unsigned int  f0 = 0, f1 = 1, temp = 0; 
	for (unsigned int i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

unsigned short fibo_short_u(unsigned short n)
{
	if (n == 0)
	{
		return 0;
	}
	unsigned short  f0 = 0, f1 = 1, temp = 0; 
	for (unsigned short i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

unsigned char fibo_char_u(unsigned char n)
{
	if (n == 0)
	{
		return 0;
	}
	unsigned char  f0 = 0, f1 = 1, temp = 0; 
	for (unsigned char i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

long long fibo_long_long(long long n)
{
	if (n == 0)
	{
		return 0;
	}
	long long f0 = 0, f1 = 1, temp = 0; 
	for (long long i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

long fibo_long(long n)
{
	if (n == 0)
	{
		return 0;
	}
	long  f0 = 0, f1 = 1, temp = 0; 
	for (long i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

double fibo_double(double n)
{
	if (n == 0)
	{
		return 0;
	}
	double  f0 = 0, f1 = 1, temp = 0; 
	for (double i = 1.0; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

float fibo_float(float n)
{
	if (n == 0)
	{
		return 0;
	}
	float  f0 = 0, f1 = 1, temp = 0; 
	for (float i = 1.0; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

int fibo_int(int n)
{
	if (n == 0)
	{
		return 0;
	}
	int  f0 = 0, f1 = 1, temp = 0; 
	for (int i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

short fibo_shor(short n)
{
	if (n == 0)
	{
		return 0;
	}
	short  f0 = 0, f1 = 1, temp = 0; 
	for (short i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}

char fibo_char(char n)
{
	if (n == 0)
	{
		return 0;
	}
	char  f0 = 0, f1 = 1, temp = 0; 
	for (char i = 1; i < n; i++)
	{
		temp = f0 + f1;
		f0 = f1;
		f1 = temp;
	}
	return f1;
}


void num_max()
{
	char c = 0;
	while(fibo_char(++c) >= fibo_char(c-1));
	printf("char %d\n", c-1);

	short sh = 0;
	while(fibo_shor(++sh) >= fibo_shor(sh-1));
	printf("short %d\n", sh-1);

	int i = 0;
	while(fibo_int(++i) >= fibo_int(i-1));
	printf("int%d\n", i-1);

	long li = 0;
	while(fibo_long(++li) >= fibo_long(li-1));
	printf("long %li\n", li-1);

	long long lli = 0;
	while(fibo_long_long(++lli) >= fibo_long_long(lli-1));
	printf("long long %Li\n", lli-1);

	float fl = -1.0;
	float fb = 0.0;
	while((fb = fibo_float(++fl)) <= pow(2,sizeof(float)*8));
	printf("float %f\n", fl-1.0);

	double db = 0.0;
	while(fibo_double(++db) <= pow(2,sizeof(double)*8));
	printf("double %f\n", db-1.0);
	
}

void num_max_unsigned()
{
	unsigned char c = 0;
	while(fibo_char_u(++c) >= fibo_char_u(c-1));
	printf("char %hhu\n", c-1);

	unsigned short sh = 0;
	while(fibo_short_u(++sh) >= fibo_short_u(sh-1));
	printf("short %hu\n", sh-1);

	unsigned int i = 0;
	while(fibo_int_u(++i) >= fibo_int_u(i-1));
	printf("int %u\n", i-1);

	unsigned long li = 0;
	while(fibo_long_u(++li) >= fibo_long_u(li-1));
	printf("long %lu\n", li-1);

	unsigned long long lli = 0;
	while(fibo_long_long_u(++lli) >= fibo_long_long_u(lli-1));
	printf("long long %llu\n", lli-1);

	long double ldb = 0.0;
	while(fibo_double_u(++ldb) <= pow(2,sizeof(long double)*8));
	printf("long double %Lf\n", ldb-1.0);
	
}


int main()
{
	//printf("%c\n", (char)pow(2,sizeof(unsigned char)*8));
	//printf("%d\n", (int)fibo_char_u(200));
	printf("--------------Signed---------------\n");
	num_max();
	printf("--------------Unsigned---------------\n");
	num_max_unsigned();
	return 0;
}