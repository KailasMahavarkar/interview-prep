class Solution:
    def minJumps(self, arr, n):
        maxR = arr[0]
        step = arr[0]
        jump = 1

        # base case 
        if n==1:
            # 0 implies element is already at end 
            # step taken to reach was 0
            return 0 
        elif arr[0] == 0:
            # if element was 0 it means it never gonna reach end
            return -1
        else:
            pass
            # running loop from 1 to n since we already covered case for 0
            for i in range(1, n):
                # this means we are at the end of array and we return answer
                if (i == n-1):
                    return jump

                maxR = max(maxR, i + arr[i])
                print(arr[i], i + arr[i], maxR)
                step -= 1
                if (step == 0): 
                    jump  += 1
                    if (i > maxR):
                        return -1
                    step = maxR - i
                
        return jump
                



tArr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Solution().minJumps(arr=tArr, n=len(tArr))
