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

long int query(long int l_index, long int r_index, long int pos, long int min_seg[], long int l, long int r)
{
    if (l_index > r || r_index < l)
        return INT_MAX;
    if (l_index >= l && r_index <= r)
        return min_seg[pos];
    int mid = (l_index + r_index) / 2;
    long int left_min = query(l_index, mid, 2 * pos + 1, min_seg, l, r);
    long int right_min = query(mid + 1, r_index, 2 * pos + 2, min_seg, l, r);
    return min(left_min, right_min);
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
    createMinSegmentTree(arr, 0, n - 1, 0, min_seg);
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << query(0, n - 1, 0, min_seg, l, r) << endl;
    }
}