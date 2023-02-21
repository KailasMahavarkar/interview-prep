
def maxsum(array):
	best, summ = 0, 0
	for x in range(len(array)):
        # correction when 0th element is negative
		summ = max(0, summ + array[x])
        # compare best among max and best
		best = max(best, summ)
		print("sum : ", summ)
		print("best: ", best)
		print("------------")
	return best


res = maxsum([-1, 2, -2, -2])
print(res)