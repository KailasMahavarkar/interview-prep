class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n = numRows - 2

        # mode -> normal or zig
        mode = "normal"

        listNormal = []
        listZig = []

        i = 0
        while(i < len(s)):
            if mode == 'normal':
                # create a list
                listNormal.append(list(s[i: i + numRows]))
                i += numRows
                mode = 'zig'
            else:
                for x in range(0, n):
                    if (i + x < len(s)):
                        listZig.append(s[i + x])
                i += n
                mode = 'normal'

        answer = ""
        mode = 'normal'


Solution().convert(s='abcdefghijklm', numRows=4)
