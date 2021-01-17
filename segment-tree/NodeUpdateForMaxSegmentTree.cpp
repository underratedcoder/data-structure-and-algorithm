#include <bits/stdc++.h>
using namespace std;

void createMaxSegmentTree(long int arr[], long int l_index, long int r_index, long int pos, long int max_seg[])
{
    if (l_index == r_index)
    {
        max_seg[pos] = arr[l_index];
        return;
    }
    long int mid = (l_index + r_index) / 2;
    createMaxSegmentTree(arr, l_index, mid, 2 * pos + 1, max_seg);
    createMaxSegmentTree(arr, mid + 1, r_index, 2 * pos + 2, max_seg);
    max_seg[pos] = max(max_seg[2 * pos + 1], max_seg[2 * pos + 2]);
}

long int maxQuery(long int l_index, long int r_index, long int pos, long int max_seg[], long int l, long int r)
{
    if (l_index > r || r_index < l)
        return INT_MIN;
    if (l_index >= l && r_index <= r)
        return max_seg[pos];
    long int mid = (l_index + r_index) / 2;
    long int left_max = maxQuery(l_index, mid, 2 * pos + 1, max_seg, l, r);
    long int right_max = maxQuery(mid + 1, r_index, 2 * pos + 2, max_seg, l, r);
    return max(left_max, right_max);
}

void updateNode(long int arr[], long int l_index, long int r_index, long int pos, long int max_seg[], long int index, long int value)
{
    if (l_index == r_index)
    {
        if (l_index == index)
        {
            arr[index] = value;
            max_seg[pos] = value;
        }
        return;
    }
    long int mid = (l_index + r_index) / 2;
    if (index >= l_index && index <= mid)
        updateNode(arr, l_index, mid, 2 * pos + 1, max_seg, index, value);
    if (index >= mid + 1 && index <= r_index)
        updateNode(arr, mid + 1, r_index, 2 * pos + 2, max_seg, index, value);
    max_seg[pos] = max(max_seg[2 * pos + 1], max_seg[2 * pos + 2]);
}

int main()
{
    long int n, q, l, r, index, value;
    cin >> n;
    long int arr[n], max_seg[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    createMaxSegmentTree(arr, 0, n - 1, 0, max_seg);
    cin >> index >> value;
    updateNode(arr, 0, n - 1, 0, max_seg, index, value);
}