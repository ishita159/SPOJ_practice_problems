#include <bits/stdc++.h>
int tree[4000000];
int arr[1000000];

int cons_util(int *arr, int lb, int ub, int si)
{
    if (lb == ub)
    {
        tree[si] = arr[lb];
        return (arr[lb]);
    }
    int mid = lb + (ub - lb) / 2;
    tree[si] = cons_util(arr, lb, mid, 2 * si + 1) + cons_util(arr, mid + 1, ub, 2 * si + 2);
    return tree[si];
}

int get_sum_util(int lb, int ub, int ss, int se, int index)
{
    if (se < lb || ss > ub)
        return 0;
    if (se >= ub && ss <= lb)
        return tree[index];
    int mid = lb + (ub - lb) / 2;
    return (get_sum_util(lb, mid, ss, se, 2 * index + 1) + get_sum_util(mid + 1, ub, ss, se, 2 * index + 2));
}

int get_sum(int ss, int se, int n)
{
    return (get_sum_util(0, n - 1, ss, se, 0));
}

void update_util(int lb, int ub, int i, int diff, int index)
{
    if (i < lb || i > ub)
        return;
    tree[index] = tree[index] + diff;
    if (lb != ub)
    {
        int mid = lb + (ub - lb) / 2;
        update_util(lb, mid, i, diff, 2 * index + 1);
        update_util(mid + 1, ub, i, diff, 2 * index + 2);
    }
}

void update(int *arr, int i, int new_val, int n)
{
    int diff = new_val - arr[i];
    update_util(0, n - 1, i, diff, 0);
}

int get_val(int n)
{
    int temp;
    temp = 1;
    while (temp < 2 * n)
        temp = temp * 2;
    return (temp - 1);
}

main()
{
    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++)
        arr[i] = 0;
    int max_size = 4 * n - 2;
    cons_util(arr, 0, n - 1, 0);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        char str[5];
        scanf("%s", str);
        if (str[0] == 'f')
        {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%d\n", get_sum(a - 1, b - 1, n));
        }
        else
        {
            int a, b;
            scanf("%d%d", &a, &b);
            update(arr, a - 1, arr[a - 1] + b, n);
        }
    }
}
