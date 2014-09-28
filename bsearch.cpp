#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
T* binarySearch(T* t_low, T* t_high, const T &target);

template<class T, class S>
T* binarySearch(T* t_data, const S &s_size, const T &target);

template<class T, class S>
T* binarySearch(T* t_data, const S &s_size, const T &target)
{
    T* t_low = t_data;
    T* t_high = t_data + s_size - 1;
    return binarySearch(t_low, t_high, target);
}

template<class T>
bool greaterThan(const T *lhs, const T *rhs)
{
    return lhs > rhs;
}

template<class T>
bool lessThan(const T *lhs, const T *rhs)
{
    return lhs < rhs;
}

template<class T>
T* roundDown(T* a, T* b)
{
    if(a > b)
        return b + (a - b) / 2;
    else
        return a + (b - a) / 2;
}

template<class T>
T* roundUp(T* a, T* b)
{
    if(a > b)
        return b + (a - b + 1) / 2;
    else
        return a + (b - a + 1) / 2;
}


template<class T>
T* increment(T* a)
{
    return a+1;
}

template<class T>
T* decrement(T* a)
{
    return a-1;
}


template<class T>
T* binarySearch(T* t_low, T* t_high, const T &target)
{
    if (t_low == NULL || t_high == NULL)
        return NULL;
    //Normal binary search operations. Ascending list
    T* (*calcLow)(T*) = increment;
    bool (*compare)(const T*, const T*) = lessThan;
    T* (*midpoint)(T*, T*) = roundDown;

    if(*t_low > *t_high)
    {
        //Operations for decending list
        swap(t_low, t_high);
        compare = greaterThan;
        calcLow = decrement;
        midpoint = roundUp;
    }

    while (compare(t_low, t_high))
    {
        T* t_mid = midpoint(t_low, t_high);
        if (*t_mid < target)
            t_low = calcLow(t_mid);
        else
            t_high = t_mid;
    }

    if (t_low == t_high && *t_high == target)
        return t_high;
    else
        return NULL;
}

int main()
{
    //const unsigned long long NUMBERS = 100000;
    int nums[] = {10, 9, 8, 7, 6, 5, 4, 3, 3, 3, 3, 3, 3, 2, 1};//{1, 1, 2, 3, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 11, 11, 22, 45, 56};
    int length = sizeof(nums) / sizeof(int);
    //unsigned long long length = 100000000;
//    int* nums = new int[length];
/*
    for(unsigned long long i = 0; i < length/NUMBERS;i++)
        for(unsigned long long j = 0; j < NUMBERS; j++)
            nums[i* NUMBERS + j] = i;
*/
//    for(unsigned long long i = 0; i < length;i++)
//        nums[i] = i;


    int* start = nums;
    int* n_end = &nums[length-1];

    //int* num = binarySearch(nums, length, 3);
//    for(unsigned long long i = 0; i < 1; i++)
//    {
        int* num = binarySearch(start, n_end, 3);

        int* num2 = lower_bound(start, n_end, 3);
        if(num != num2)
            cout << "Mismatch!" << endl;

 //   }

    //cout << "Match!" << endl;

    for(int i = 0; i < length; i++)
        cout << nums[i] << ':';
    cout << endl;
    if(num != NULL)
    {
        *num = -1;
    }
    else
        cout << "We have NULL!" << endl;

    for(int i = 0; i < length; i++)
        cout << nums[i] << ':';
    cout << endl;

    //delete [] nums;
}
