#include <bits/stdc++.h>
using namespace std ;

int n, k;
//long v[200010];
vector<int>v(200010);

multiset<int> up;
multiset<int> low;

void insrt(int val)           // insert val into sets
{
    int a = *low.rbegin();  // current median
    if (a < val)
    {
        up.insert(val);
        if (up.size() > k / 2)
        {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    }
    else
    {
        low.insert(val);
        if (low.size() > (k + 1) / 2)
        {
            up.insert(*low.rbegin());
            low.erase(--low.end());
        }
    }
}

void ers(int val)    // erase from sets
{
    if (up.find(val) != up.end()) up.erase(up.find(val));
    else low.erase(low.find(val));
    if (low.empty())
    {
        low.insert(*up.begin());
        up.erase(up.begin());
    }
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> v[i];

    low.insert(v[0]);

    for (int i = 1; i < k; i++) insrt(v[i]);

    cout << *low.rbegin() << " ";

    for (int i = k; i < n; i++)
    {
        if (k == 1)
        {
            insrt(v[i]);
            ers(v[i - k]);
        }
        else
        {
            ers(v[i - k]);
            insrt(v[i]);
        }
        cout << *low.rbegin() << " ";
    }
    cout << endl;
}


/*

#include <bits/stdc++.h>
using namespace std ;

long n, k;
//long v[200010];
vector<int>v(200010);

multiset<long> up;
multiset<long> low;

void insrt(long val)           // insert val into sets
{
    long a = *low.rbegin();  // current median
    if (a < val)
    {
        up.insert(val);
        if (up.size() > k / 2)
        {
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    }
    else
    {
        low.insert(val);
        if (low.size() > (k + 1) / 2)
        {
            up.insert(*low.rbegin());
            low.erase(--low.end());
        }
    }
}

void ers(long val)    // erase from sets
{
    if (up.find(val) != up.end()) up.erase(up.find(val));
    else low.erase(low.find(val));
    if (low.empty())
    {
        low.insert(*up.begin());
        up.erase(up.begin());
    }
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> v[i];

    low.insert(v[0]);

    for (int i = 1; i < k; i++) insrt(v[i]);

    cout << *low.rbegin() << " ";

    for (long i = k; i < n; i++)
    {
        if (k == 1)
        {
            insrt(v[i]);
            ers(v[i - k]);
        }
        else
        {
            ers(v[i - k]);
            insrt(v[i]);
        }
        cout << *low.rbegin() << " ";
    }
    cout << endl;
}



*/
