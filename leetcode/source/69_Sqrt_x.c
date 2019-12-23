/**
 * https://leetcode.com/problems/sqrtx/
 * 
 Implement int sqrt(int x).

 Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 
 Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 
 Example 1:
 Input: 4

 Output: 2
 Example 2:

 Input: 8
 Output: 2
 Explanation: The square root of 8 is 2.82842..., and since 
             	the decimal part is truncated, 2 is returned.
 *
 */

int mySqrt(int x){
	if (x <= 0)
	{
		return 0;
	}

	// BEGIN, 二分解法：
	long mid = 0;
	long left = 0;
	long right = x/2;

	while (left <= right) {
		mid = left + (right-left)/2;
		if (mid * mid > x)
		{
			right = mid - 1;
		}
		else
		{
			if ((mid+1) * (mid+1) > x)
			{
				return mid;
			}
			left = mid + 1;
		}
	}
    return left;
	// END.

	// BEGIN, 粗鲁解法：从1开始自增，当最接近目标值时，退出循环
	// unsigned int r = 1;
	// unsigned int tmp = 1;
	// while (tmp <= x) {
	// 	r++;
	// 	tmp = r*r;
	// }
	// if (tmp > x)
	// {
	// 	r--;
	// }
	// return r;
	// END, 粗鲁解法：从1开始自增，当最接近目标值时，退出循环
}
