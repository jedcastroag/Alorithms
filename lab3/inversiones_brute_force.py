import time


def inversiones_brute_force(A, n):
    inv = 0
    for i in range(n-1):
        for j in range(i+1, n):
            if A[i] > A[j]:
                inv += 1
    return inv


N = 10**5


def case1():
    file = open("input.txt", "r")
    content = file.readlines()
    file.close()
    arr = list(map(int, content[1].split()))
    t = time.time()
    ans = inversiones_brute_force(arr, N)
    t = time.time() - t
    print ans, t
    pass


def case2():
    t = time.time()
    ans = inversiones_brute_force(list(range(0, N)), N)
    t = time.time() - t
    print ans, t
    pass


def case3():
    t = time.time()
    ans = inversiones_brute_force(list(range(N, 0, -1)), N)
    t = time.time() - t
    print ans, t
    pass


case1()
case2()
case3()
