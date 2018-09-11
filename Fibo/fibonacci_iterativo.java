import java.io.*;

class FibinacciIterativo{

	public static long fibo(long n){
		if (n<0)
			return -1;
		else if (n == 0)
		{
			return 0;
		}
		long f0 = 0, f1 = 1, temp = 0; 
		for (long i = 1; i < n; i++)
		{
			temp = f0 + f1;
			f0 = f1;
			f1 = temp;
		}
		return f1;
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = null;
		br = new BufferedReader(new InputStreamReader(System.in));

		System.out.println(fibo(Integer.parseInt(br.readLine())));
	}
}