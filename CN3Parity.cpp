#include <iostream>
#include <string>
using namespace std;

string calculateParity(string data)
{
    int onesCount = 0;
    for (char bit : data)
    {
        if (bit == '1')
        {
            onesCount++;
        }
    }

    if (onesCount % 2 == 0)
    {
        cout << "Even Parity" << endl;
        return data + '0'; // Even parity
    }
    else
    {
        cout << "Odd Parity" << endl;
        return data + '1'; // Odd parity
    }
}

int main()
{
    string data;
    cout << "Enter the data bits to be sent : ";
    cin >> data;
    string transmittedData = calculateParity(data);
    cout << "Transmitted Data: " << transmittedData << endl;
    return 0;
}

