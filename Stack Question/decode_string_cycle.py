class Solution:
    def decodeString(self, s: str) -> str:
        stack = []

        for i in range(len(s)):
            if s[i] != ']':
                stack.append(s[i])
            else:
                # Get the substring
                substr = ""
                while stack and stack[-1] != '[':
                    substr = stack.pop() + substr
                stack.pop()

                k = ""
                while stack and stack[-1].isdigit():
                    k = stack.pop() + k
                k = int(k)

                repeated_str = substr * k
                stack.append(repeated_str)

        return "".join(stack)


print(Solution().decodeString("1[1]"))
