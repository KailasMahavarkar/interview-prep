class Solution:
    def decodeString(self, s: str) -> str:
        st = []

        for i in range(len(s)):
            if s[i] != ']':
                st.append(s[i])
            else:
                substr = ""
                while st[-1] != '[':
                    substr = st.pop() + substr
                st.pop() 

                k = ""
                while st and st[-1].isdigit():
                    k = st.pop() + k
                st.append(int(k) * substr)
        return "".join(st)


print(Solution().decodeString("2[2[aa]]"))