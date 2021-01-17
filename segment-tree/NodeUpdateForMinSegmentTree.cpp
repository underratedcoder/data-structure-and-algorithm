#include <bits/stdc++.h>
using namespace std;

void createMinSegmentTree(long int arr[], long int l_index, long int r_index, long int pos, long int min_seg[])
{
    if (l_index == r_index)
    {
        min_seg[pos] = arr[l_index];
        return;
    }
    long int mid = (l_index + r_index) / 2;
    createMinSegmentTree(arr, l_index, mid, 2 * pos + 1, min_seg);
    createMinSegmentTree(arr, mid + 1, r_index, 2 * pos + 2, min_seg);
    min_seg[pos] = min(min_seg[2 * pos + 1], min_seg[2 * pos + 2]);
}

void updateNode(long int arr[], long int l_index, long int r_index, long int pos, long int min_seg[], long int index, long int value)
{
    if (l_index == r_index)
    {
        if (l_index == index)
        {
            arr[index] = value;
            min_seg[pos] = value;
        }
        return;
    }
    long int mid = (l_index + r_index) / 2;
    if (index >= l_index && index <= mid)
        updateNode(arr, l_index, mid, 2 * pos + 1, min_seg, index, value);
    if (index >= mid + 1 && index <= r_index)
        updateNode(arr, mid + 1, r_index, 2 * pos + 2, min_seg, index, value);
    min_seg[pos] = min(min_seg[2 * pos + 1], min_seg[2 * pos + 2]);
}

int main()
{
    long int n, q, l, r, index, value;
    cin >> n;
    long int arr[n], min_seg[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    createMinSegmentTree(arr, 0, n - 1, 0, min_seg);
    cin >> index >> value;
    updateNode(arr, 0, n - 1, 0, min_seg, index, value);
}