from time import clock
months_list = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def countSundays(num_years):
	month_count = 1
	num_sundays = 0
	year = 0
	start = clock()
	while year < num_years:
		if year % 4 == 0 and year != 0:
			months_list[1] = 29
		else:
			months_list[1] = 28			
		for month in months_list:
			month_count += month
			if month_count % 7 == 0:				
				num_sundays += 1
		year += 1
	stop = clock()
	
	return num_sundays, (stop-start)

num, runtime = countSundays(99)
print num, runtime

