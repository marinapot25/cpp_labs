#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

bool A(int *a, int N, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] == x)
        {
            if (i != 0)
            {
                std::swap(a[i], a[0]);
            }
            return true;
        }
    }
    return false;
}

bool B(int *a, int N, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] == x)
        {
            if (i != 0)
            {
                std::swap(a[i], a[i-1]);
            }
            return true;
        }
    }
    return false;
}

bool C(int *a, int N, int x, int *c)
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] == x)
        {
            c[i]++;
            if (i != 0 && c[i] > c[i-1])
            {
                std::swap(a[i], a[i-1]);
                std::swap(c[i], c[i-1]);
            }
            return true;
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

    /*for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int x;

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt != 0; --cnt)
        {
            x = rand() % 1001;
            A(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }*/

    /*for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int x;

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt != 0; --cnt)
        {
            x = rand() % 1001;
            B(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }*/

    /*for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int *c = new int[N];
        int x;

        for (int i = 0; i < N; ++i)
        {
            c[i] = 0;
        }

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt != 0; --cnt)
        {
            x = rand() % 1001;
            C(a, N, x, c);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }*/

    /*for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int x;

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt != 0; --cnt)
        {
            x = rand() % 1000;
            if (x % 2 == 0)
            {
                x = rand() % 1000;
            }
            A(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }*/

    /*for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int x;

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt != 0; --cnt)
        {
            x = rand() % 1000;
            if (x % 2 == 0)
            {
                x = rand() % 1000;
            }
            B(a, N, x);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }*/

    for (int N = 100; N <= 1000000; N = 3 * N/2)
    {
        int *a = new int[N];
        int *c = new int[N];
        int x;

        for (int i = 0; i < N; ++i)
        {
            c[i] = 0;
        }

        gen(a, N);

        auto begin = std::chrono::steady_clock::now();
        for (unsigned cnt = 1000000; cnt != 0; --cnt)
        {
            x = rand() % 1000;
            if (x % 2 == 0)
            {
                x = rand() % 1000;
            }
            C(a, N, x, c);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        std::cout << N << " " << time_span.count() << std::endl;

        delete[] a;
    }

    return 0;
}