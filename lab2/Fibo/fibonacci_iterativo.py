import time as t
import numpy as np
import matplotlib.pyplot as plt

def fibo(n):
    if(n < 1):
        return 0
    f0 = 0
    f1 = 1
    for x in range(1,n):
        temp = f0 + f1
        f0 = f1
        f1 = temp
    return f1

def time_comp(n):   
    times = []
    for i in range(0,n+1,1000):
        start = t.time()
        fibo(i)
        finish = t.time()-start
        times.append([i,finish])
    return np.array(times)
        
def plot(n):
    np_times = time_comp(n)
    plt.plot(np_times[:,0],np_times[:,1])


plot(100000)