/*You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.
Example 2:

Input: N = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), 
the total number of set bits is 35.

Your Task: The task is to complete the function countSetBits() that takes n as a parameter and returns the count of all bits.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 108*/

class Solution{
public:
    int countSetBits(int n) {
        if (n == 0)
            return 0;
        int x = largestPowerOf2(n);
        int bitsUpTo2PowX = x * (1 << (x - 1));
        int msbFrom2PowXToN = n - (1 << x) + 1;
        int remaining = n - (1 << x);
        
        return bitsUpTo2PowX + msbFrom2PowXToN + countSetBits(remaining);
    }
private:
    int largestPowerOf2(int n) {
        int x = 0;
        while ((1 << x) <= n)
            x++;
        return x - 1;
    }
};