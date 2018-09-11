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


void num_max_unsigned()
{
	char c = 10;
	//while
	c = fibo_char(c);// >= 2){++c; }
		printf("%d\n", (int) c-1);
	
}



int main()
{
	//printf("%c\n", (char)pow(2,sizeof(unsigned char)*8));
	//printf("%d\n", (int)fibo_char_u(200));
	num_max_unsigned();
	return 0;
}