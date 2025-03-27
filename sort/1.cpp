#include<iostream>

void bubble(int *a, int n)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(a[j] > a[j+1])
            {
                std::swap(a[j], a[j+1]);
            }
        }
    }
    return;
}

int find_max_index(int *a, int n)
{
    int m = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] > a[m])
        {
            m = i;
        }
    }
    return m;
}

void selected(int *a, int n)
{
    int cm;
    for(int i = 0; i < n - 1; ++i)
    {
        cm = find_max_index(a, n - i);
        std::swap(a[cm], a[n - i - 1]);
    }
    return;
}

void insert(int *a, int n, int i_elem, int i_st)
{
    int j = 0;
    while(a[i_elem] > a[i_st + j])
    {
        std::swap(a[i_elem], a[i_st + j]);
        ++j;
    }
    return;
}

void insert_sort(int *a, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        insert(a, n, n - i - 2, n - i - 1);
    }
    insert(a, n, n - 2, n - 1);
    return;
}

void merge_arrays(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int *a = new int[n1], *b = new int[n2];
    for(int i = 0; i < n1; ++i)
    {
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n2; ++i)
    {
        b[i] = arr[m + 1 + i];
    }

    int i1 = 0, i2 = 0;
    int j;
    for(j = l; i1 < n1 && i2 < n2; ++j)
    {
        if(a[i1] < b[i2])
        {
            arr[j] = a[i1];
            ++i1;
        }
        else
        {
            arr[j] = b[i2];
            ++i2;
        }
    }
    while(i1 < n1)
    {
        arr[j] = a[i1];
        ++i1;
        ++j;
    }
    while(i2 < n2)
    {
        arr[j] = b[i2];
        ++i2;
        ++j;
    }

    delete[] a;
    delete[] b;
    return;
}

void merge_sort(int *a, int l, int r)
{
    if(l == r)
    {
        return;
    }

    int m = l + (r - l)/2;

    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);

    merge_arrays(a, l, m, r);
}

int main(void)
{
    int a[5];
    int n = 5;

    for(int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    //bubble(a, n);
    //selected(a, n);
    //insert_sort(a, n);
    merge_sort(a, 0, n - 1);

    for(int i = 0; i < n; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}