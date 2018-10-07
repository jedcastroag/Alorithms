#include <stdio.h>
#include <stdlib.h>

#define N 1e+5

long long inversions(int *A, int n)
{
    long long inv = 0;
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = 0; j < n; j++) {
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

    f = fopen("input.txt", "r");
    if (f == NULL) {
        perror("error al abrir el archivo input.txt");
    }
    fscanf(f," %i",&n);
    arr = (int*) malloc(n*sizeof(int));
    for (size_t i = 0; i < n; i++) {
        fscanf(f," %i",&arr[i]);
    }
    printf("%lli\n", inversions(arr,n));
    return 0;
}
