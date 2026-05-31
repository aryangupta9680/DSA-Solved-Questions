class Solution {
public:
    int digitFrequencyScore(int n) {
        int num = n;
        unordered_map<int, int>freq;
        while(num != 0)
        {
            int rem = num % 10;
            freq[rem]++;
            num /= 10;
        }

        int sum = 0;
        for(auto x: freq)
        {
            int val = x.first;
            int count = x.second;
            sum += val * count;
        }

        return sum;
    }
};