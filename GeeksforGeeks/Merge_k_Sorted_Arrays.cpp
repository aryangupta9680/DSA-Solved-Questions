// First Method:
class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int n = arr.size();
        // data(value), row, col
        vector<pair<int, pair<int, int>>> temp;
        for (int i = 0; i < K; i++)
        {
            temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
        }

        // create min heap
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

        vector<int> ans; // vector which will stored the sorted data
        pair<int, pair<int, int>> element;
        int i, j;

        while (!p.empty())
        {
            element = p.top();
            p.pop();
            ans.push_back(element.first); // value
            i = element.second.first;     // row number
            j = element.second.second;    // column number
            if (j + 1 < K)
            {
                p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
            }
        }

        return ans;
    }
};







// second method:
class Solution
{
public:
    // Function to merge k sorted arrays.
    void merge(vector<int> &arr, int start, int mid, int end)
    {
        vector<int> temp(end - start + 1);
        int left = start, right = mid + 1, index = 0;

        while ((left <= mid) && (right <= end))
        {
            if (arr[left] <= arr[right])
            {
                temp[index] = arr[left];
                left++, index++;
            }

            else
            {
                temp[index] = arr[right];
                right++, index++;
            }
        }

        // left array is not empty yet
        while (left <= mid)
        {
            temp[index] = arr[left];
            left++, index++;
        }

        // right array is not empty yet
        while (right <= end)
        {
            temp[index] = arr[right];
            right++, index++;
        }

        index = 0;
        // put these value in arr
        while (start <= end)
        {
            arr[start] = temp[index];
            start++, index++;
        }
    }

    void mergesort(vector<int> &arr, int start, int end, int portion, int K)
    {
        if (portion < 2)
        {
            return;
        }

        int mid = start + (portion / 2) * K - 1;

        // left side
        mergesort(arr, start, mid, portion / 2, K);

        // right side
        mergesort(arr, mid + 1, end, portion - portion / 2, K);

        // merge
        merge(arr, start, mid, end);
    }

    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // merge sort
        vector<int> ans;
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < K; j++)
            {
                ans.push_back(arr[i][j]);
            }
        }

        mergesort(ans, 0, ans.size() - 1, K, K);
        return ans;
    }
};