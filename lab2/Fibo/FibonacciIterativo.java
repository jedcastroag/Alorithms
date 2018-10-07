package javaapplication1;

import java.io.*;

public class FibonacciIterativo{

	public static byte fibo_byte(byte n){
		if (n<=0)
			return 0;
		byte f0 = 0, f1 = 1, temp; 
		for (byte i = 1; i < n; i++)
		{
			temp = (byte) (f0 + f1);
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

	public static char fibo_char(char n){
		if (n<=0)
			return 0;
		char f0 = 0, f1 = 1, temp; 
		for (char i = 1; i < n; i++)
		{
			temp = (char)(f0 + f1);
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

	public static short fibo_short(short n){
		if (n<=0)
			return 0;
		short f0 = 0, f1 = 1, temp; 
		for (short i = 1; i < n; i++)
		{
			temp = (short)(f0 + f1);
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

	public static int fibo_int(int n){
		if (n<=0)
			return 0;
		int f0 = 0, f1 = 1, temp; 
		for (int i = 1; i < n; i++)
		{
			temp = (int)(f0 + f1);
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

	public static long fibo_long(long n){
		if (n<=0)
			return 0;
		long f0 = 0, f1 = 1, temp; 
		for (long i = 1; i < n; i++)
		{
			temp = (long)(f0 + f1);
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

	public static float fibo_float(float n){
		if (n<=0)
			return 0;
		float f0 = (float) 0.0, f1 = (float) 1.0, temp; 
		for (float i = (float) 1.0; i < n; i++)
		{
			temp = (float)(f0 + f1);
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

	public static double fibo_double(double n){
		if (n<=0)
			return 0;
		double f0 = 0.0, f1 = 1.0, temp; 
		for (double i = 1.0; i < n; i++)
		{
			temp = (double)(f0 + f1);
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

        @SuppressWarnings("empty-statement")
	public static void printAll(){
		byte by = 0;
		while(fibo_byte(++by) > 0);
		System.out.println("byte " + by);

		char ch = 0, ch_b=0,ch_c;
		while((ch_c = fibo_char(++ch)) >= ch_b){
                    ch_b = ch_c;
                }
		System.out.println("char " + (int)(ch));

		short sh = 0;
		while(fibo_short(++sh) > 0);
		System.out.println("short " + sh);

		int i = 0;
		while(fibo_int(++i) > 0);
		System.out.println("int " + i);

		long l = 0;
		while(fibo_long(++l) > 0);
		System.out.println("long " + l);
                
		float f = (float) 0.0;
		while(fibo_float(++f) < Float.MAX_VALUE);
		System.out.println("float " + f);

		double d = 0.0;
		while(fibo_double(++d) < Double.MAX_VALUE);
		System.out.println("double " + d);
                

	}

	public static void main(String[] args) throws IOException{
		printAll();
	}
}