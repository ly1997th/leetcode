//564. Find the Closest Palindrome
class Solution 
{
public:
    string nearestPalindromic(string n) 
    {
        int l = n.size();
        set<long> candidates;
        // biggest, one more digit, 10...01
        candidates.insert(long(pow(10, l)) + 1);
        // smallest, one less digit, 9...9 or 0
        candidates.insert(long(pow(10, l - 1)) - 1);
        // the closest must be in middle digit +1, 0, -1, then flip left to right
        long prefix = stol(n.substr(0, (l + 1) / 2));
        for ( long i = -1; i <= 1; ++i ) 
        {
            string p = to_string(prefix + i);
        // jump the last number when n is odd by (l & 1)
            string pp = p + string(p.rbegin() + (l & 1), p.rend());
            candidates.insert(stol(pp));
        }
        long num = stol(n), minDiff = LONG_MAX, diff, minVal;
        candidates.erase(num);
        for ( long val : candidates ) 
        {
            diff = abs(val - num);
            if ( diff < minDiff ) 
            {
                minDiff = diff;
                minVal = val;
            }
        }
        return to_string(minVal);
    }
};