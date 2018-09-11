def fibo(n):
	if(n < 1):
		return 0
	f0 = 0
	f1 = 1
	for x in xrange(1,n):
		temp = f0 + f1
		f0 = f1
		f1 = temp
		pass
	return f1
	pass

try:
    n=long(input('Number: '))
except ValueError:
    print "Not a number"

print (fibo(n));