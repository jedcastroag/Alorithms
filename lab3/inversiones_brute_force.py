import time


def inversiones_brute_force(A, n):
    inv = 0
    for i in range(n-1):
        for j in range(i+1, n):
            if A[i] > A[j]:
                inv += 1
    return inv


N = 10**5

file = open("input.txt", "r")
content = file.readlines()
file.close()
n = int(content[0])
arr = list(map(int, content[1].split()))
t = time.time()
inversiones_brute_force(arr, N)
t = time.time() - t
print t
