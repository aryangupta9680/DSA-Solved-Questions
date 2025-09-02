class Solution
{
public:
    bool isPossible(vector<int> &target)
    {
        // max heap
        priority_queue<long long> p;
        long long sum = 0;

        for (int i = 0; i < target.size(); i++)
        {
            p.push(target[i]);
            sum += target[i];
        }

        int MaxElement, RemSum, Element;

        while (p.top() != 1)
        {
            MaxElement = p.top();
            p.pop();
            RemSum = sum - MaxElement;

            // MaxElement = RemSum + Element
            // edges cases
            if (RemSum <= 0 || RemSum >= MaxElement)
            {
                return false;
            }

            Element = MaxElement % RemSum;
            if (Element == 0)
            {
                if (RemSum != 1)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            sum = RemSum + Element;
            p.push(Element);
        }

        return true;
    }
};