#include <iostream>
#include <vector>
#include <valarray>
using namespace std;

int bin_search(int t, const vector<int> &arr, int l)
{
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < t)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left;
}

int main()
{
    int l;
    cout << "Введите длину массива: ";
    cin >> l;
    vector<int> nums(l);
    cout << "Введите массив: ";
    for (int i = 0; i < l; i++)
    {
        cin >> nums[i];
    }
    vector<int> counts(l);
    for (int i = 0; i < l; i++)
    {
        vector<int> a = vector<int>(nums.begin() + i, nums.end());
        sort(begin(a), end(a));
        counts[i] = bin_search(nums[i], a, l - i - 1);
    }
    for (int i = 0; i < l; i++)
    {
        cout << counts[i] << " ";
    }
    return 0;
}