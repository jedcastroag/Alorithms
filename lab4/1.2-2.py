#Hecho por Jefferson Castro


import math


def is_vs_ms():
    n = 2
    while(n < 8*int(math.log(n,2))):
        n += 1
    print n-1, 8*int(math.log(n-1,2))
    return n-1;
    pass


print is_vs_ms()


#Respuesta 39
