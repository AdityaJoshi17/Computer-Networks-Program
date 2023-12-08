#include <iostream>
#include <cstdlib>

using namespace std;

int sendToReceiver(int data, int correctAck)
{
    cout << "Receiver: received data: " << data << ", ack: " << correctAck << endl;
    if (rand() % 3 == 0)
    {
        cout << "Receiver: sending negative acknowledgement" << endl;
        return -1; // negative
    }
    else
    {
        cout << "Receiver: sending positive Acknowledgement" << endl;
        return correctAck; // positive
    }
}

int main()
{
    // sender code
    int WS, N;
    cout << "Enter Window Size and Number of Frames:" << endl;
    cin >> WS >> N;
    int window[WS];
    int windowStart = 1;

    while (windowStart <= N)
    {
        cout << "Sender: window start at: " << windowStart << endl;

        int i;

        for (i = 0; i < WS; ++i)
            window[i] = windowStart + i;

        do
        {
            for (i = 0; i < WS && windowStart + i <= N; ++i)
            {
                if (window[i] != 0)
                {
                    cout << "Sender: Data Send: " << windowStart + i << endl;
                    int ack = sendToReceiver(windowStart + i, i);
                    cout << "Sender: Acknowledgement Received: " << ack + 1 << endl;
                    if (ack != -1)
                    {
                        window[ack] = 0;
                    }
                }
            }

            for (i = 0; i < WS; ++i)
                if (window[i] != 0)
                    break;
        } while (i != WS && windowStart + i != N + 1);

        windowStart += WS;
    }

    return 0;
}

