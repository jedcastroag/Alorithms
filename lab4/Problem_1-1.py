# Hecho por Jeffersn Daniel Castro Aguilar


import math


def nlogn(t):
    n = 1
    while(n*int(math.log(n,2)) <= t):
        n += 1
    return n-1


def fac_n(t):
    n = 1;
    fac = 1;
    while fac <= t:
        n += 1;
        fac *= n


    return n-1

print nlogn(1e+6)
print fac_n(1e+6)
