import time
import numpy as np


def merge(A, s, m, e):
    p, q = s, m+1
    inv = 0
    aux = []
    for i in range(s, e+1):
        if p > m:
            aux.append(A[q])
            q += 1
        elif q > e:
            aux.append(A[p])
            p += 1
        elif A[p] <= A[q]:
            aux.append(A[p])
            p += 1
        else:
            aux.append(A[q])
            q += 1
            inv += m-p+1

    for i in range(len(aux)):
        A[s+i] = aux[i]
    return inv


def merge_sort(A, s, e):
    inv = 0
    if s < e:
        mid = (s+e)/2
        inv += merge_sort(A, s, mid)
        inv += merge_sort(A, mid+1, e)
        inv += merge(A, s, mid, e)
    return inv


def case1():
    file = open("input.txt", "r")
    content = file.readlines()
    file.close()
    N = 10**5
    arr = list(map(int, content[1].split()))
    times = []
    ans = 0
    for i in range(100):
        aux = arr[:]
        t = time.time()
        ans = merge_sort(aux, 0, N-1)
        t = time.time() - t
        times.append(t)
    np_times = np.array(times)
    print ans, " time: ", np_times.mean(), " s"
    pass


def case2():
    N = 10**5
    ans = 0
    times = []
    for i in range(100):
        t = time.time()
        ans = merge_sort(list(range(N)), 0, N-1)
        t = time.time() - t
        times.append(t)
    np_times = np.array(times)
    print ans, " time: ", np_times.mean(), " s"
    pass


def case3():
    N = 10**5
    times = []
    ans = 0
    for i in range(100):
        t = time.time()
        ans = merge_sort(list(range(N, 0, -1)), 0, N-1)
        t = time.time() - t
        times.append(t)
    np_times = np.array(times)
    print ans, " time: ", np_times.mean(), " s"
    pass


case1()
case2()
case3()
