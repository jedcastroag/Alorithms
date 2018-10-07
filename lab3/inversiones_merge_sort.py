import time
import numpy as np


def merge(A, s, m, e):
    p, q = s, m+1
    inv, comp = 0, 0
    aux = []
    for i in range(s, e+1):
        if p > m:
            aux.append(A[q])
            q += 1
        elif q > e:
            aux.append(A[p])
            p += 1
        elif A[p] <= A[q]:
            comp += 1
            aux.append(A[p])
            p += 1
        else:
            comp += 1
            aux.append(A[q])
            q += 1
            inv += m-p+1

    for i in range(len(aux)):
        A[s+i] = aux[i]
    return list((inv, comp))


def merge_sort(A, s, e):
    inv, comp = 0, 0
    aux = []
    if s < e:
        mid = (s+e)/2
        aux = merge_sort(A, s, mid)
        inv += aux[0]
        comp += aux[1]
        aux = merge_sort(A, mid+1, e)
        inv += aux[0]
        comp += aux[1]
        aux = merge(A, s, mid, e)
        inv += aux[0]
        comp += aux[1]
    return list((inv, comp))


file = open("input.txt", "r")
content = file.readlines()
file.close()
N = 10**5-1
arr = list(map(int, content[1].split()))
times = []
ans = []
for i in range(100):
    # aux = arr[:]
    N = i + 2
    aux = list(range(N, 0, -1))
    t = time.time()
    ans = merge_sort(aux, 0, N-1)
    t = time.time() - t
    print (i+2), " ", ans[1]
    times.append(t)
np_times = np.array(times)
print "ans: ", ans[0], "\ncomp: ", ans[1], "\ntime: ", np_times.mean(), " s"
