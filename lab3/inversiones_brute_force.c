#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1e+5

long long inversiones_brute_force(int *A, int n)
{
    long long inv = 0;
    int i,j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (A[i] > A[j]) {
                inv++;
            }
        }
    }
    return inv;
}


void case1()
{
    FILE *f;
    int *arr,n;
    time_t s,t;
    long long ans;

    f = fopen("input.txt", "r");
    if (f == NULL) {
        perror("error al abrir el archivo input.txt");
    }
    fscanf(f," %i",&n);
    arr = (int*) malloc(n*sizeof(int));
    for (size_t i = 0; i < N; i++) {
        fscanf(f," %i",&arr[i]);
    }
    fclose(f);
    time(&s);
    ans = inversiones_brute_force(arr,N);
    time(&t);
    free(arr);
    t = t - s;
    printf("%lli\n",ans);
    printf("%1.3f\n", (float)t);
}


void case2()
{
    int *arr, i;
    time_t s,t;
    long long ans;

    arr = (int*) calloc(N,sizeof(int));
    for(i = 0; i < N; ++i)
    {
        arr[i] = i;
    }
    time(&s);
    ans = inversiones_brute_force(arr, N);
    time(&t);
    t = t - s;
    free(arr);
    printf("%lli\n%1.3f\n", ans, (float)t);
}

void case3()
{
    int *arr, i, j;
    time_t s,t;
    long long ans;

    arr = (int*) calloc(N,sizeof(int));
    for(i = 0; i < N; ++i)
    {
        arr[i] = N - i;
    }
    time(&s);
    ans = inversiones_brute_force(arr, N);
    time(&t);
    free(arr);
    t = t - s;
    printf("%lli\n%1.3f\n", ans, (float)t);
}


int main(int argc, char const *argv[]) {
    case1();
    case2();
    case3();
    return 0;
}
