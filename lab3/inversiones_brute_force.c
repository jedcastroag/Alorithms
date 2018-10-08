#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1e+5

long long inversiones_brute_force(int *A, int n)
{
    long long inv = 0;
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = i+1; j < n; j++) {
            if (A[i] > A[j]) {
                inv++;
            }
        }
    }
    return inv;
}

int main(int argc, char const *argv[]) {
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
    return 0;
}
