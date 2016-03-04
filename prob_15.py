import time

nums_1 = [1] * 21
nums_2 = [1] * 21
isFirst = True

start = time.clock()

for i in range (0, 21):
	for j in range(0, i+1):
		if isFirst:
			if j == 0:
				nums_2[j] = 1
			elif j == i:
				nums_2[j] = nums_2[j-1] * 2
			else:
				nums_2[j] = nums_2[j-1] + nums_1[j]						
		else:
			if j == 0:
				nums_1[j] = 1
			elif j == i:
				nums_1[j] = nums_1[j-1] * 2
			else:
				nums_1[j] = nums_1[j-1] + nums_2[j]
			
	isFirst = not isFirst
	
stop = time.clock()	
	
print "Result: ", 
print nums_2[20],
print " Taking: ",
print stop - start, 
print " seconds."

