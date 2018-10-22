# Hecho por Jeffersn Daniel Castro Aguilar


import math


def nlogn(t):
    n = 1
    while (n**2) * math.log(n**2, 2) <= t:
        n += 1
    n = (n-1)**2
    while n*math.log(n, 2) <= t:
        n += 1

    return n-1


def fac_n(t):
    n = 1
    fac = 1
    while fac <= t:
        n += 1
        fac *= n

    return n-1


def print_all():
    arr = [1e+9, 6*1e+10, 3.6*1e+12, 8.64*1e+13, 2.592*1e+15, 3.153*1e+16, 3.153*1e+18]
    for i in arr:
        print nlogn(i)
    # for i in arr:
    #    print fac_n(i)


print_all()
