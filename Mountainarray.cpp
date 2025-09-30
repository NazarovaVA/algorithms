#include <iostream>
#include <vector>
using namespace std;

int f(const vector<int> &arr, int l)
{
    if (l < 3)
    {
        cout << "Массив не горный, так как длина меньше 3" << endl;
        return 0;
    }
    int left = 0;
    int right = l - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    int peak = left;
    if ((peak == 0) || (peak == l - 1))
    {
        cout << "Массив не горный, так как находится на границе" << endl;
        return 0;
    }
    for (int i = 1; i < (peak + 1); i++)
    {
        if (arr[i] <= arr[i - 1])
        {
            cout << "Массив не горный, так как не строго возрастает" << endl;
            return 0;
        }
    }
    for (int i = peak + 1; i < l; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            cout << "Массив не горный, так как не строго убывает" << endl;
            return 0;
        }
    }
    cout << "Массив горный, пик на позиции: " << peak << endl;
    return peak;
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
    f(nums, l);
}