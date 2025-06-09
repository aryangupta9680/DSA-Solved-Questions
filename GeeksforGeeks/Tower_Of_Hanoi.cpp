class Solution
{
public:
    void toh(int n, int source, int help, int destination)
    {
        // base condition
        if (n == 0)
        {
            return;
        }

        toh(n - 1, source, destination, help);
        toh(n - 1, help, source, destination);
    }

    long long towerOfHanoi(int n, int from, int to, int aux)
    {
        toh(n, from, aux, to);
        return pow(2, n) - 1;
    }
};