class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int total = 0;
        // Atleast(k) - Atleast(k+1)
        unordered_map<int, int> freq;

        int start = 0, end = 0, n = nums.size(), count = 0;
        // count = count of different integers in that window

        while (end < n)
        {
            freq[nums[end]]++; // add the frequency of that number

            if (freq[nums[end]] == 1)
            {
                count++;
            }

            while (count == k)
            {
                total += n - end;
                freq[nums[start]]--;
                if (freq[nums[start]] == 0)
                {
                    count--;
                }

                start++;
            }

            end++;
        }

        start = 0, end = 0, count = 0;
        freq.clear();
        k++;

        while (end < n)
        {
            freq[nums[end]]++; // add the frequency of that number

            if (freq[nums[end]] == 1)
            {
                count++;
            }

            while (count == k)
            {
                total -= n - end;
                freq[nums[start]]--;
                if (freq[nums[start]] == 0)
                {
                    count--;
                }

                start++;
            }

            end++;
        }

        return total;
    }
};