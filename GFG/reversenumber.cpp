class Solution
{
	public:
		long long int reverse_digit(long long int n)
		{
		    // Code here
		    long long int temp = n;
		    long long int rev = 0;
		    
		    while(temp != 0)
		    {
		        long long int rem = temp % 10;
		        rev = rev * 10 + rem;
		        temp = temp/10;
		    }
		    
		    return rev;
		}
};
