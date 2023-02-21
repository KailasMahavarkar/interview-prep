from sys import maxsize
# Bruteforce solution
class Solution(object):
    def maxSubArray(self, nums):
        zmax = 0
        for i in range(len(nums)):
            for j in range(0, len(nums)):
                zmax = max(zmax, sum(nums[i:j]))
        print(zmax)

# Kadans algorithm
class Solution(object):
    def maxSubArray(self, nums):
        lmax = 0
        gmax = -maxsize
        for x in range(0, len(nums)):
            lmax = lmax + nums[x]
            # gmax = max(lmax, gmax)
            if (lmax > gmax):
                gmax = lmax
            
            # lmax = max(lmax, 0)
            if (lmax < 0):
                lmax = 0

            print("gmax :", gmax)
            print("lmax : ", lmax)
            print("-----------")

Solution().maxSubArray(nums=[1,2,3,-2,5])