#include <bits/stdc++.h>
using namespace std;

void createSumSegmentTree(long int arr[], long int l_index, long int r_index, long int pos, long int sum_seg[])
{
    if (l_index == r_index)
    {
        sum_seg[pos] = arr[l_index];
        return;
    }
    long int mid = (l_index + r_index) / 2;
    createSumSegmentTree(arr, l_index, mid, 2 * pos + 1, sum_seg);
    createSumSegmentTree(arr, mid + 1, r_index, 2 * pos + 2, sum_seg);
    sum_seg[pos] = sum_seg[2 * pos + 1] + sum_seg[2 * pos + 2];
}

long int sumQuery(long int l_index, long int r_index, long int pos, long int sum_seg[], long int l, long int r)
{
    if (l_index > r || r_index < l)
        return 0;
    if (l_index >= l && r_index <= r)
        return sum_seg[pos];
    int mid = (l_index + r_index) / 2;
    return sumQuery(l_index, mid, 2 * pos + 1, sum_seg, l, r) + sumQuery(mid + 1, r_index, 2 * pos + 2, sum_seg, l, r);
}

int main()
{
    long int n, q, l, r;
    cin >> n;
    long int arr[n], min_seg[4 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    createSumSegmentTree(arr, 0, n - 1, 0, min_seg);
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << sumQuery(0, n - 1, 0, min_seg, l, r) << endl;
    }
}