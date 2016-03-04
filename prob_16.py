from time import clock

num_str = str(2**1000)
total = 0

start = clock()

for i in num_str:
	total = total + int(i)

stop = clock()
print total, "time: ",
print stop - start