#include <bits/stdc++.h>
#include <ctime>

#define ll long long int
using namespace std;
//i: Starting frame number in the current window.
//N: Window size.
//tf: Total number of frames to be transmitted.
//tt: Total number of frames transmitted and retransmitted.
void transmission(ll &i, ll &N, ll &tf, ll &tt)
{
    while (i <= tf)
    {
        int z = 0;//ack counter
        for (int k = i; k < i + N && k <= tf; k++)
        {
            cout << "Sending Frame " << k << "..." << endl;
            tt++;
        }
        for (int k = i; k < i + N && k <= tf; k++)
        {
            int f = rand() % 2;
            if (!f)
            {
                cout << "Acknowledgment for Frame " << k << "... RECIEVED" << endl;
                z++;
            }
            else
            {
                cout << "Timeout!! Frame Number : " << k << " Not Received" << endl;
                cout << "Retransmitting Window..." << endl;
                break;
            }
        }
        cout << "\n";
        i = i + z;
    }
}

int main()
{
    ll tf, N, tt = 0;
    srand(time(NULL));
    cout << "Enter the Total number of frames : ";
    cin >> tf;
    cout << "Enter the Window Size : ";
    cin >> N;
    ll i = 1;
    transmission(i, N, tf, tt);
    cout << "Total number of frames which were sent and resent are : " << tt << endl;
    return 0;
}
