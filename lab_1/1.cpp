#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

bool linear(int *a, int N, int x)
{
    for (int i = 0; i < N; ++i)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}

bool binary(int *a, int N, int x)
{
    int l = 0;
    int r = N - 1;
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (a[m] == x)
        {
            return true;
        }
        else if (a[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
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
        for (unsigned cnt = 100000; cnt != 0; --cnt)
        {
            linear(a, N, x);
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
        for (unsigned cnt = 20000000; cnt != 0; --cnt)
        {
            binary(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }
    
    for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int x;

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt != 0; --cnt)
        {
            x = rand() % 1000;
            linear(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }

    
    for (int N = 100; N <= 1000000; N = 3 *N/2)
    {
        int *a = new int[N];
        int x;

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 20000000; cnt != 0; --cnt)
        {
            x = rand() % 1000;
            binary(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }
    
    return 0;
}