info = {
    "companies": [],
    "platform": "geeksforgeeks",
    "tags": ['prime', 'superprime'],
    "date": "",
    "question": """
        A prime number is Super Prime if it is a sum of two primes.
        Find all the Super Primes upto N
    """,
    "attempts": [
        {
            "01-05-2022": ""
        },
        {

        }
    ]
}


# User function Template for python3
class Solution:
    def superPrimes(self, n):
        primes = []
        def isPrime(n):
            isPrime = True
            if (n == 1):
                return False
            for x in range(1, n // 2):
                if x % n == 0:
                    isPrime = False
                    break
            return isPrime
        
        for x in range(1, n):
            primes.append(isPrime(x))
        
        return primes
                            

x = Solution().superPrimes(7)
print(x)