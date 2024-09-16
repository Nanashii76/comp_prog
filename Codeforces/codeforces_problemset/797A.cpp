#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> fact;

    if(k == 1) {
        cout << n << endl;
        return 0;
    }

    int count = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0 and count < k)
        {
            while (n % i == 0 and count < k)
            {
                n /= i;
                fact.push_back(i);
                count++;

                if (count == k - 1 and n != 1)
                {
                    fact.push_back(n);
                    n /= n;
                    count++;
                }
            }
        }
    }

    if (n != 1)
    {
        fact.push_back(n);
        count++;
    }

    if (count == k)
    {
        for (auto x : fact)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}