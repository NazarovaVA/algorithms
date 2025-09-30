#include <iostream>
#include <vector>
using namespace std;

int bin_search_neg(const vector<int> &arr, int l)
{
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < 0)
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

int bin_search_pos(const vector<int> &arr, int l)
{
    int left = 0;
    int right = l - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] > 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
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
    int neg = bin_search_neg(nums, l);
    int p = bin_search_pos(nums, l);
    int pos = l - p;
    int zero = l - neg - pos;
    cout << "Положительных: " << pos << " Отрицательных: " << neg << " Нулей: " << zero << endl;
    if (neg < pos)
    {
        cout << "Больше положительных,  " << pos;
    }
    else if (neg == pos)
    {
        cout << "Равное количество,  " << pos;
    }
    else
    {
        cout << "Больше отрицательных,  " << neg;
    }
}