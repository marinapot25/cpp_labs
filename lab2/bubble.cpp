#include <iostream>
#include <random>
#include <chrono>

void gen(int *arr, int N)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-10000, 10000);
    for(int i = 0; i < N; ++i) 
    {
        arr[i] = dist(gen);
    }
    return;
}

int bubble_sort(int *arr, int N)
{
    int swapcount = 0;
    for(int j = 0; j < N - 1; ++j)
    {
        for(int i = 0; i < N - j - 1; ++i)
        {
            if(arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                ++swapcount;
            }
        }
    }
    return swapcount;
}

bool check(int *arr, int N)
{
    for(int i = 0; i < N - 1; ++i)
    {
        if(arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int swapcount;
    for(int N = 100; N <= 70100; N += 1000)
    {
        int *arr = new int[N];
        gen(arr, N);

        auto begin = std::chrono::steady_clock::now();
        swapcount = bubble_sort(arr, N);
        auto end = std::chrono::steady_clock::now();

        if(check(arr, N) == false)
        {
            delete[] arr;
            break;
        }
        
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        std::cout << N << " " << time_span.count() << " " << swapcount << std::endl;

        delete[] arr;
    }
    return 0;
}