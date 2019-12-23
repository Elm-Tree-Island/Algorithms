/**
 *    Author: Mark Chen
 *    Date: 2019.12.10
 *
 *    https://leetcode-cn.com/problems/add-binary/
 **/
char * addBinary(char *a, char *b)
{
	int a_length = 0;
	int b_length = 0;
	
	if (!a && b)
	{
		return b;
	}
	
	if (!a && !b)
	{
		return NULL;
	}
	
	if (a && !b)
	{
		return a;
	}
	
    // Get the a,b string length
	int idx = 0;
	char ch = a[0];
	while (ch != '\0') {
		a_length++;
		idx++;
		ch = a[idx];
	}
	
	idx = 0;
	ch = b[0];
	while (ch != '\0') {
		b_length++;
		idx++;
		ch = b[idx];
	}
	
	printf("1=> a string length : %d, b string length : %d\n", a_length, b_length);
	int max = a_length > b_length ? a_length : b_length;
	int min = a_length < b_length ? a_length : b_length;
	
	// 技巧：利用整数数组，而不是字符串数组进行解决
	const int RESULT_SIZE = max+1;
	int rslt[RESULT_SIZE];		// 结果数组
	int tmp = 0;

	// Read both array from back to left
	for (int i = 0; i < min; i++)
	{
		tmp += a[a_length - i - 1] - '0';
		tmp += b[b_length - i - 1] - '0';
		rslt[RESULT_SIZE - i - 1] = tmp%2;
		tmp /= 2;
	}

	// process all the left elements in the longest array
	for (int j = min; j < max; j++)
	{
		if (a_length > b_length)
		{
			tmp += a[a_length - j - 1] - '0';
		} else {
			tmp += b[b_length - j - 1] - '0';
		}
		rslt[RESULT_SIZE - j - 1] = tmp%2;
		tmp /= 2;
	}
	rslt[0] = tmp;

	for (int i = 0; i < RESULT_SIZE; ++i)
	{
		printf("%d --> %d\n", i, rslt[i]);
	}

	int result_length = 0;
	if (rslt[0] == 0)
	{
		result_length = RESULT_SIZE;
	} else {
		result_length = RESULT_SIZE+1;
	}

	char *resChars = (char *)calloc(result_length, sizeof(char));
	int i = 0;
	int j = 0;
	if (rslt[0] == 0)
	{
		i = 1;
	}
	for (; i < RESULT_SIZE; i++, j++)
	{
		resChars[j] = (char)(rslt[i] + '0');
		printf("Add ==> %c\n", resChars[j]);
	}
	resChars[result_length-1] = '\0';

	return resChars;


	// ----------------- 代码量比较多的方法，基本思想是一致的 -----------------
	// const int c_length = max+1;
	// char *c = (char *)calloc(c_length, sizeof(char));
	
 //    // Read the short string from back to front.
 //    bool carry = false;    // 是否进位
 //    int i = 1;
 //    for (; i <= min; i++)
 //    {
 //    	char a_ch = a[a_length - i];
 //    	char b_ch = b[b_length - i];
    	
 //    	if (a_ch == '0' && b_ch == '0')
 //    	{
 //    		if (carry)
 //    		{
 //    			c[c_length-i] = '1';
 //    		}
 //    		else
 //    		{
 //    			c[c_length-i] = '0';
 //    		}
 //    		carry = false;
 //    	}
    	
 //    	if ((a_ch == '0' && b_ch == '1') || (a_ch == '1' && b_ch == '0'))
 //    	{
 //    		if (carry)
 //    		{
 //    			c[c_length-i] = '0';
 //    			carry = true;
 //    		}
 //    		else
 //    		{
 //    			c[c_length-i] = '1';
 //    			carry = false;
 //    		}
 //    	}
    	
 //    	if (a_ch == '1' && b_ch == '1')
 //    	{
 //    		if (carry)
 //    		{
 //    			c[c_length-i] = '1';
 //    		}
 //    		else
 //    		{
 //    			c[c_length-i] = '0';
 //    		}
 //    		carry = true;
 //    	}
 //    }
    
 //    printf("c = %s(size = %d), carry = %d\n", c, (int)sizeof(c), carry);
    
 //    // copy all the a left char into c
 //    char *p = a_length > b_length ? a : b; 
 //    for (; i <= max; i++)
 //    {
 //    	printf("Loop 1 time, i = %d\n", i);
 //    	char cc = p[max - i];
 //    	if (cc == '1' && carry)
 //    	{
 //    		c[c_length-i] = '0';
 //    		carry = true;
 //    		printf("debug => index = %d, carry = %d, currentChar = %c\n", c_length-i, carry, c[c_length-i]);
 //    	}
 //    	else if ((cc == '0' && carry) || (cc == '1' && !carry))
 //    	{
 //    		printf("aaaa");
 //    		c[c_length-i] = '1';
 //    		carry = false;
 //    	}
 //    	else
 //    	{
 //    		printf("bbbb");
 //    		c[c_length-i] = '0';
 //    		carry = false;
 //    	}
 //    }
    
 //    if (carry)
 //    {
 //    	printf("carry is true.\n");
 //    	c[0] = '1';
 //    } else {
 //    	c = c+1;
 //    }
 //    printf("3: c = %s, carry = %d\n", c, carry);
    
 //    return c;
}