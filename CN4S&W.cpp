#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main()
{
    cout << "Stop and Wait ARQ Simulation:" << endl;
    int n, p;
    cout << "Enter the number of frames which you want to send: " << endl;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        cnt++;
        cout << "Sending the data frame " << cnt << "..." << endl;
        cout.flush();
        sleep(3);
        cout << "Recieved Acknowledgement?(Yes=1/No=0)" << endl;
        cin >> p;
        if (p == 0)
        {
            cout << "Retransmitting frame " << cnt << " ..." << endl;
            n++;
            cnt--;
        }
    }
    cout << "Data frames shared successfully." << endl;
    return 0;
}
