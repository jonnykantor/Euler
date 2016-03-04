from time import clock
from math import factorial

def sumFactNum(fact_base):
	num = str(factorial(fact_base))
	total = 0
	start = clock()
	for i in num:
		total += int(i)
	stop = clock()
	return total, (stop - start)

total, runtime = sumFactNum(100)
print total, runtime