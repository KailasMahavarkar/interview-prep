from typing import List
from collections import defaultdict


class Solution:
    def encode(self, strs: List[str]) -> str:
        dictionary = defaultdict(list)

        for i in range(len(strs)):
            if (strs[i] in dictionary):
                dictionary[strs[i]].append(i)
            else:
                dictionary[strs[i]] = [i]

        encoded_string = ""
        for k, v in dictionary.items():
            encoded_string += "~" + k + "?" + "_".join([str(x) for x in v])

        return str(len(strs)) + '=' + encoded_string

    def decode(self, s: str) -> List[str]:
        dlen, cstr = s.split("=")
        str_arr = ["" for _ in range(int(dlen))]

        cstr = [x for x in cstr.split("~") if len(x) > 0]

        for word in cstr:
            w, occ = word.split("?")
            occ = [int(x) for x in occ.split("_")]

            for idx in occ:
                str_arr[idx] = w

        return str_arr


if __name__ == "__main__":
    zero = Solution()

    encoded = zero.encode([
        "that", "girl", "is", "pretty",
        "but", "she", "is", "not", "my", "world", "girl"
    ])

    print("encoded -->", encoded)
    decoded = zero.decode(encoded)
    print("decoded -->", decoded)
