# https://leetcode.com/problems/palindrome-number/

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (str(x) == str(x)[::-1]):
            return True
        return False

if __name__== "__main__":
    s = Solution()
    tests = [121, -121, 10]
    for t in tests:
        print(f"Test {t}: {s.isPalindrome(t)}")