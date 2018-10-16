# Hecho por Jefferson Castro.


import math


# f = 100n^2  vs  g = 2^n
def f_vs_g():
    n = 2
    a = int(math.log(100,2))
    while(n <=  a + 2*int(math.log(n,2))):
        n += 1

    return n-1;
    pass

print f_vs_g()


# respuesta: 12
