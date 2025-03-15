// problems => ask to count the number of integers ‘x‘ between two integers say ‘a‘ and ‘b‘ 
// such that x satisfies a specific property that can be related to its digits.
  
// So, if we say G(x) tells the number of such integers between 1 to x (inclusively), 
// then the number of such integers between a and b can be given by G(b) – G(a-1). 
// This is when Digit DP (Dynamic Programming) comes into action. 
 





// Key Concept => For all DIGIT DP problems

// Let given number x has n digits. 
// The main idea of digit DP is to first represent the digits as an array of digits t[]. 
// Let’s say a we have [tn, tn-1, tn-2, ... t2, t1] as the decimal representation.
// eg=> 1234 will be stored as => [4,3,2,1] => REVERSE order => because we did push_back
 
// Now => generate the numbers less than the given number
// and simultaneously calculate using DP, if the number satisfy the given property. 
// We start generating integers having number_of_digits = 1 and then till number_of_digits = n. 
 





// Example Problem : 
// Given two integers a and b. Your task is to print the sum of all the digits appearing in the integers between a and b.
// For example if a = 5 and b = 11, then answer is 38 (5 + 6 + 7 + 8 + 9 + 1 + 0 + 1 + 1)
  
// Constraints : 1 <= a < b <= 10^18

// What is the use of DP here?
// Now we see that if we have calculated the answer for state having n-1 digits, i.e., [tn-1, tn-2, ... t2, t1]
// and we need to calculate answer for state having n digits [tn, tn-1, tn-2, ... t2, t1].
// So, clearly, we can use the result of the previous state instead of re-calculating it. Hence, it follows the overlapping property.
  







  

// Our DP state will be dp(idx, tight, sum)

// 1) idx : 
// tells about the index value FROM RIGHT in the array of digits we generated => since 1234 => [4,3,2,1] (reverse)



// 2) tight :
// This will tell if the current digits range is restricted or not. 
// If the current digit’s range is NOT restricted then it will span from {0 to 9} (inclusively) => {tight == 0}
// else it will span from {0 to digit[idx]} (inclusively) => {tight == 1}
  
// Example: consider our limiting integer to be 3245 and we need to calculate G(3245) 
// digits : 3 2 4 5 
 
// Unrestricted range: 
// Now suppose the integer generated till now is : 3 1 * * 
// unrestricted range => can have digits from range 0 to 9(inclusively). 
// For unrestricted range tight = 0

// Restricted range: 
// Now suppose the integer generated till now is : 3 2 * * 
// restricted range => can only have digits from range 0 to 4 (inclusively) 
// For restricted range tight = 1
  
  

// 3) sum :
// store the sum of digits in the generated integer from msd(most significant digit) to idx. 
// Max value for this parameter sum can be 9*18 = 162, considering 18 digits in the integer => **VVIMP**









// Time Complexity => O(10*idx*sum*tight) => 10 bcz of for loop (digits 0-9)
// observe that tight = 2, idx can be max 18 for 64 bit unsigned integer, sum will be max 9*18 ~ 200. 
// So, overall we have 10*18*200*2 ~ 10^5 iterations which can be easily executed in 0.01 seconds.

// Space Complexity => O(d*sum*tight) as it uses a dp array of size d*sum*tight. where d is the number of digits in the number.








// Given two integers a and b. The task is to print sum of all the digits appearing in the integers between a and b

long long dp[20][180][2];  //dp[index][sum][tight] ... remember we discussed above ... sum can go only till 162


void getDigits(long long x, vector <int> &digit)
{
	while (x)
	{
		digit.push_back(x%10);
		x /= 10;
	}
}


long long digitSum(int idx, int sum, int tight, vector <int> &digit)
{
	if (idx == -1)  //base case
		return sum;

	if ( (dp[idx][sum][tight] != -1) && (tight != 1) )  // 2 condn => IMP => since tight==1 means aage ka nahi pata => calculate karna paega
		return dp[idx][sum][tight];
	
	//one VVIMP thing to NOTE in this function => we are storing and calling DP ONLY when tight==0
	//why?
	//because DP parameters are just (idx, sum and tight) => tells idx index tak kya sum aaya hai => can be memoized ONLY when tight==0

	long long ret = 0;

	int k = tight ? digit[idx] : 9;   // new number range depends on 'tight' boolean

	for (int i = 0; i <= k ; i++)
	{
		int newTight = (digit[idx] == i) ? tight : 0;

		ret += digitSum(idx-1, sum+i, newTight, digit);
	}

	if(tight == 0)    //IMP => store ONLY when tight == 0
		dp[idx][sum][tight] = ret;

	return ret;
}


// Returns sum of digits in numbers from a to b.
int rangeDigitSum(int a, int b)
{
	memset(dp, -1, sizeof(dp));

	vector<int> digitA;
	getDigits(a-1, digitA);   // (a-1) => NOT a

	long long ans1 = digitSum(digitA.size()-1, 0, 1, digitA);

	vector<int> digitB;
	getDigits(b, digitB);

	long long ans2 = digitSum(digitB.size()-1, 0, 1, digitB);

	return (ans2 - ans1);   //fun(b) - fun(a-1) ... NOT fun(a)
}

