class SolutionBruteForce:
    def mySqrt(self, x: int) -> int:
        i = 0

        while i < x:
            if i * i > x:
                break
            i += 1

        return i - 1


class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x

        s, e = 0, x
        result = 0

        while s <= e:
            mid = s + (e - s) // 2

            if mid * mid <= x:
                result = mid
                s = mid + 1
            else:
                e = mid - 1

        return result


if __name__ == "__main__":
    x = 8
    sol_brute_force = SolutionBruteForce()
    print("Brute Force Solution: ans -->", sol_brute_force.mySqrt(x))

    sol = Solution()
    print("Optimized Solution: ans -->", sol.mySqrt(x))
