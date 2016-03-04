from math import sqrt
from math import ceil
from time import time
from sys import argv

def findDivisorsTotal(input_num):
	"""
	Use prime divisor collection to
	quickly get the number of divisors
	"""
	prime_dict = {}
	
	first = 2
	last = input_num	
	while first < last:
		if last % first == 0: # first is a divisor			
			last = last/first			
			prime_dict[first] = prime_dict.get(first, 0) + 1								
		else:
			if(first > int(ceil(sqrt(last)))): 
				prime_dict[last] = prime_dict.get(last, 0) + 1
				break
			if(first == 2): first += 1	
			else: first += 2
		if first == last: prime_dict[first] = prime_dict.get(first, 0) + 1
	total = 1;
	for _, i in prime_dict.iteritems():
		total = total * (i+1)	
	
	#print prime_dict
	
	return total	


cur_tri_num_total = 1
arg_l = len(argv)
if arg_l != 2: 
	print "Usage>> python prob_12.py <divisor lower bound number>"
	exit()
	
div_bound = int(argv[1])
cur_num = div_bound*2
start = time()

total = findDivisorsTotal(cur_tri_num_total)
while total < div_bound:	
	
	if cur_num % 2 == 0:
		cur_tri_num_total = cur_num * ((cur_num)/2) + (cur_num/2)
	else:
		cur_tri_num_total = cur_num * ((cur_num + 2 - 1)/2)

	#at this point we have our new tri-number total
	total = findDivisorsTotal(cur_tri_num_total)	
	#increment num	
	cur_num += 1 

stop = time()	
	
print "tri_num: %d, value: %d, # of divisors: %d exec. time: %f" % (cur_num-1, cur_tri_num_total, total, stop - start)
