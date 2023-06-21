from typing import List
import ipaddress


def check_valid_ip(ip: str):
    if ip == '':
        return False
    try:
        ipaddress.ip_address(ip)
    except Exception as e:
        return False


    return True


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
        octets = []

        if len(s) > 12:
            return result


        def backtrack(idx: int):
            if len(octets) == 4 and idx == len(s):
                result.append(".".join(octets))
                return

            for size in range(1, 4):
                octet = s[idx:idx+size]

                # 8.05.268.1
                # 05  -> (len is 2) and starts with 0 -> false
                # 268 -> 268 > 255 -> false
                if len(octet) > 1 and (octet[0] == '0' or  (int(octet) > 255)):
                    continue
                
                if len(octets) < 4:
                    octets.append(octet)
                    backtrack(idx + size)
                    octets.pop()
                                
                
        backtrack(0)
        return result


ans = Solution().restoreIpAddresses(s='8844')
print("ans -->", ans)
