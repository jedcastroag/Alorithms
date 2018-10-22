# Hecho por Jefferson Castro.


# f = 100n^2  vs  g = 2^n
def f_vs_g():
    n = 1
    while 100*(n**2) >= 2**n:
        n += 1

    return n
    pass


print f_vs_g()


# respuesta: 12
