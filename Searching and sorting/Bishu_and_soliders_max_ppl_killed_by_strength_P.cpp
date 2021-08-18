/*
There are infinite people standing in a row, indexed from 1. A person having index i has strength of i2. You have strength P and the 
task is to tell what is the maximum number of people you can kill with strength P. 
You can only kill a person with strength X if P ≥ X and after killing him, your strength decreases by X. 




We can do the same problem in time complexity O(logn) and Space Complexity in O(1). Start your binary search by considering 
the value of low as 0 and high as 10^15. We will calculate the mid-value and according to mid, we will change the position
 of low and high. 
Below is the implementation of the above approach.
 
*/

# Python3 implementation of the approach

# helper function which returns the sum
# of series (1^2 + 2^2 +...+ n^2)
def squareSeries(n):
	return (n*(n+1)*(2*n+1))//6

# maxPeople function which returns
# appropriate value using Binary Search
# in O(logn)

def maxPeople(n):

	# Set the lower and higher values
	low = 0
	high = 1000000000000000
	while low<=high:

		# calculate the mid using
		# low and high

		mid = low + ((high-low)//2)
		value = squareSeries(mid)

		#compare value with n
		if value<=n:
			ans = mid
			low = mid+1
		else:
			high = mid-1

	# return the ans
	return ans

if __name__=='__main__':
	p=14
	print(maxPeople(p))

# This code is contributed bu chaudhary_19
# (* Mayank Chaudhary)


