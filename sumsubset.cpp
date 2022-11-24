#include <bits/stdc++.h>

using namespace std;
bool incl[20];
// tsum ==total array sum
// maxs==sum of required subset
void sumSubset(int i, int currs, int tsum, vector<int> set, int maxs)
{
    if ((currs + set[i + 1] <= maxs) || ((currs + tsum) >= maxs) && (currs == maxs))
    {
        if (currs == maxs)
        {
            cout << "\nRequired set is : ";
            for (int j = 0; j <= i; j++)
            {
                if (incl[j])
                {
                    cout << set[j] << " ";
                }
            }
            cout << endl;
        }
        else
        {
            // cout<<"*\n";
            incl[i + 1] = true;
            sumSubset(i + 1, currs + set[i + 1], tsum - set[i + 1], set, maxs);
            incl[i + 1] = false;
            sumSubset(i + 1, currs, tsum - set[i + 1], set, maxs);
        }
    }
}

int main()
{
    vector<int> set;

    int n, maxs, tsum = 0;
    cout << "Enter the size of array :";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        set.push_back(a);
        tsum += set[i];
    }

    sort(set.begin(), set.end());

    cout << "Enter the max sum :";
    cin >> maxs;
    if (tsum < maxs)
    {
        cout << "Max sum is greater than the array sum";
    }
    else
    {
        for (int h = 0; h < n; h++)
        {
            incl[h] = false;
        }

        sumSubset(-1, 0, tsum, set, maxs);
        cout << endl;
    }
    return 0;
}
