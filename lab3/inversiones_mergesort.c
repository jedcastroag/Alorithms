#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1e+5

long long merge(int *A, int s, int m, int e)
{
    int p = s,q = m+1,*aux,i,k=0;
    aux = (int*) calloc(e-s+1,sizeof(int));
    long long inv = 0;
    for(i = s; i <= e; ++i)
    {
        if(p>m)
        {
            aux[k++]=A[q++];
        }else if(q>e)
        {
            aux[k++] = A[p++];
        }else if(A[p]<=A[q])
        {
            aux[k++] = A[p++];
        }else
        {
            aux[k++] = A[q++];
            inv += 1LL*(m-p+1);
        }
    }
    for(i = 0; i < k; ++i)
    {
        A[s+i]= aux[i];
    }
    free(aux);
    return inv;
}


long long merge_sort(int *A, int s, int e)
{
    long long inv = 0;
    if(s<e)
    {
        int mid = (s+e)/2;
        inv += merge_sort(A,s,mid);
        inv += merge_sort(A,mid+1,e);
        inv += merge(A,s,mid,e);
    }
    return inv;
}


int main() {
    FILE *f;
    f = fopen("input.txt", "r");
    if(f == NULL){perror("error al abrir archivo..."); exit(-1);}
    int n,r,i,j;
    time_t s,t;
    int *A,*aux;

    fscanf(f," %i",&n);
    n = N;
    aux = (int*) calloc(n, sizeof(int));
    A = (int*) calloc(n,sizeof(int));
    for(i = 0; i < n; ++i)
    {
        fscanf(f," %d",&A[i]);
    }
    fclose(f);

    r = 100;
    time_t times[r];
    for (i = 0; i < r; ++i)
    {
        for(j=0;j<n;++j)aux[j]=A[j];
        time(&s);
         merge_sort(aux, 0, n-1);

        time(&t);
        t = t-s;
        times[i] = t;
    }
    free(aux);
    free(A);
    for (i = 1; i < r; ++i)
    {
        times[0] += times[i];
    }

    printf("%1.10f\n",((float)times[0])/r);
    return 0;
}
