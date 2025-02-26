#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

bool square(int *a, int N, int x)
{
    for (int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            if((a[i] + a[j]) == x)
            {
                return true;
            }
        }
    }
    return false;
}

bool linear(int *a, int N, int x)
{
    int l = 0;
    int r = N - 1;
    while (l <= r)
    {
        int s = a[l] + a[r];
        if (s == x)
        {
            return true;
        }
        else if (s < x)
        {
            ++l;
        }
        else
        {
            --r;
        }
    }
    return false;
}

void gen(int *a, int N)
{
    for (int i = 0; i < N; ++i)
    {
        a[i] = rand() % 1000;
    }
    return;
}

int main()
{
    srand(time(0));

    for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int x = -1;

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000; cnt != 0; --cnt)
        {
            square(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }

    for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int x = -1;

        gen(a, N);

        std::sort(a, a + N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 100000; cnt != 0; --cnt)
        {
            linear(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }
    
    return 0;
}