#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define vi vector<int>
#define pob push_back
#define pf pop_front()
#define mp make_pair
#define loop(i,a,b) for(int i=a ; i<b ; ++i)
#define eloop(i,a,b) for(int i=a ; i<=b ; ++i)
#define rloop(i,a,b) for(int i=b-1 ; i>=b ; --i)
#define MAP map<int,int>
#define DQ deque<int>
#define vf(i) v[i].first
#define vs(i) v[i].second
#define mod 1000000007
#define M 998244353
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
  int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

bool isPowerOfTwo (int x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}  


int countBits( int number) 
{       
      // log function in base 2  
      // take only integer part 
      return (int)log2(number)+1; 
} 
  

 int countSetBits( int n) 
{ 
     int count = 0; 
    while (n) { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 

void SieveOfEratosthenes(int n, bool prime[], 
                         bool primesquare[], int a[]) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // Not a prime, else true. 
    for (int i = 2; i <= n; i++) 
        prime[i] = true; 
  
    // Create a boolean array "primesquare[0..n*n+1]" 
    // and initialize all entries it as false. A value 
    // in squareprime[i] will finally be true if i is 
    // square of prime, else false. 
    for (int i = 0; i <= (n * n + 1); i++) 
        primesquare[i] = false; 
  
    // 1 is not a prime number 
    prime[1] = false; 
  
    for (int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p 
            for (int i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    int j = 0; 
    for (int p = 2; p <= n; p++) { 
        if (prime[p]) { 
            // Storing primes in an array 
            a[j] = p; 
  
            // Update value in primesquare[p*p], 
            // if p is prime. 
            primesquare[p * p] = true; 
            j++; 
        } 
    } 
} 
  
// Function to count divisors 
int countDivisors(int n) 
{ 
    // If number is 1, then it will have only 1 
    // as a factor. So, total factors will be 1. 
    if (n == 1) 
        return 1; 
  
    bool prime[n + 1], primesquare[n * n + 1]; 
  
    int a[n]; // for storing primes upto n 
  
    // Calling SieveOfEratosthenes to store prime 
    // factors of n and to store square of prime 
    // factors of n 
    SieveOfEratosthenes(n, prime, primesquare, a); 
  
    // ans will contain total number of distinct 
    // divisors 
    int ans = 1; 
  
    // Loop for counting factors of n 
    for (int i = 0;; i++) { 
        // a[i] is not less than cube root n 
        if (a[i] * a[i] * a[i] > n) 
            break; 
  
        // Calculating power of a[i] in n. 
        int cnt = 1; // cnt is power of prime a[i] in n. 
        while (n % a[i] == 0) // if a[i] is a factor of n 
        { 
            n = n / a[i]; 
            cnt = cnt + 1; // incrementing power 
        } 
  
        // Calculating number of divisors 
        // If n = a^p * b^q then total divisors of n 
        // are (p+1)*(q+1) 
        ans = ans * cnt; 
    } 
  
    // if a[i] is greater than cube root of n 
  
    // First case 
    if (prime[n]) 
        ans = ans * 2; 
  
    // Second case 
    else if (primesquare[n]) 
        ans = ans * 3; 
  
    // Third casse 
    else if (n != 1) 
        ans = ans * 4; 
  
    return ans; // Total divisors 
} 

  

int32_t main() 
{ 
  #ifndef ONLINE_JUDGE
  freopen("input.txt" , "r" , stdin);
  freopen("output.txt" , "w" , stdout);
  #endif
  int n,s=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    s=s+(i*countDivisors(i));
  }
  cout<<s<<endl;
 
  return 0;   
}
      
    