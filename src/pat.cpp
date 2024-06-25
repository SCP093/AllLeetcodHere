#include "pat.h"
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <utility>

int pat_b_1001(int n)
{
    int cnt = 0;

    while (n != 1)
    {
        ++cnt;
        if (n % 2)
            n = (3 * n + 1) / 2;
        else
            n /= 2;
    }

    return cnt;
}

int pat_b_1011(long long A, long long B, long long C)
{
    if (A + B > C)
        return 1;
    return 0;
}

int pat_b_1016(int A, int DA, int B, int DB)
{
    int PA = 0;
    int PB = 0;
    while (A)
    {
        if (A % 10 == DA)
            PA = PA * 10 + DA;
        A /= 10;
    }
    while (B)
    {
        if (B % 10 == DB)
            PB = PB * 10 + DB;
        B /= 10;
    }
    return PA + PB;
}

void pat_b_1026(int C1, int C2)
{
    int duration = C2 - C1;
    int h = 0, m = 0, s = 0;
    const int BASE = 60;
    const int CLK_TCK = 100;

    s = duration % (BASE * CLK_TCK);
    duration /= (BASE * CLK_TCK);
    m = duration % BASE;
    duration /= BASE;
    h = duration % BASE;

    printf("%02d:%02d:%02d\n", h, m, (s + (CLK_TCK / 2))/ CLK_TCK);
}

int pat_b_1046(int a, int b, int c, int d)
{
    int total = a + c;
    if (b == total && d != total)
        return 2;
    if (b != total && d == total)
        return 1;
    return 0;
}

static int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void pat_b_1008(int arr[], int n, int m)
{
    int g = gcd(n, m);
    for (int i = 0; i < g; ++i)
    {
        int b = i;
        int e = (b + m) % n;
        int t = arr[b];
        while (e != b)
        {
            std::swap(arr[e], t);
            e = (e + m) % n;
        }
        arr[e] = t;
    }
}

void pat_b_1032(int arr[])
{
    int n, index, score;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &index, &score);
        arr[index] += score;
    }
    int* p = std::max_element(arr + 1, arr + n + 1);
    printf("%d %d\n", static_cast<int>(p - arr), *p);
}

void pat_b_1012(int arr[])
{
    int cnt[5] = {0};
    int a[5] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", arr + i);

        int num = arr[i];
        int remainder = num % 5;
        if (remainder == 0)
        {
            if (num % 2 == 0)
            {
                ++cnt[0];
                a[0] += num;
            }
        }
        else if (remainder == 1)
        {
            if (cnt[1] % 2 == 0)
                a[1] += num;
            else
                a[1] -= num;
            ++cnt[1];
        }
        else if (remainder == 2)
        {
            ++cnt[2];
            ++a[2];
        }
        else if (remainder == 3)
        {
            ++cnt[3];
            a[3] += num;
        }
        else // remainder == 4
        {
            cnt[4] = 1;
            if (num > a[4])
                a[4] = num;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (i)
            printf(" ");
        if (cnt[i])
        {
            if (i == 3)
                printf("%.1f", static_cast<double>(a[i]) / cnt[i]);
            else
                printf("%d", a[i]);
        }
        else
            printf("N");
    }
}

static int win_1018(char a, char b)
{
    if (a == b)
        return 0;
    if (a == 'C' && b == 'J' || a == 'J' && b == 'B' || a == 'B' && b == 'C')
        return 1;
    return -1;
}

void pat_b_1018()
{
    const char arr[] = {'B', 'C', 'J'};

    int n;
    scanf("%d", &n);

    char a, b;
    int resultA[3] = {0};
    std::unordered_map<char, int> numA = {{'C', 0}, {'J', 0}, {'B', 0}};
    std::unordered_map<char, int> numB = {{'C', 0}, {'J', 0}, {'B', 0}};

    for (int i = 0; i < n; ++i)
    {
        getchar();
        scanf("%c %c", &a, &b);
        int result = win_1018(a, b);
        if (result == 1)
        {
            ++resultA[0];
            ++numA[a];
        }
        else if (result == 0)
            ++resultA[1];
        else
        {
            ++resultA[2];
            ++numB[b];
        }
    }

    printf("%d %d %d\n", resultA[0], resultA[1], resultA[2]);
    printf("%d %d %d\n", resultA[2], resultA[1], resultA[0]);

    int cA = 0, cB = 0;
    for (int i = 1; i < 3; ++i)
    {
        if (numA[arr[i]] > numA[arr[cA]])
            cA = i;
        if (numB[arr[i]] > numB[arr[cB]])
            cB = i;
    }

    printf("%c %c\n", arr[cA], arr[cB]);
}
