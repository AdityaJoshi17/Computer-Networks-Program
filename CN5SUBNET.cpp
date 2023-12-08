#include <iostream>
#include <math.h>
#include <sstream>
#include <string>

using namespace std;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();

    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

int main()
{
    int pc, i = 0;

    cout << "Enter the number hosts : ";
    cin >> pc;

    string ip = "";
    cout << endl
         << "Enter the IP address : ";
    cin >> ip;

    int host_bits = 16;
    for (i = 0; i <= 16; i++)
    {
        if (pow(2, i) >= pc)
            break;
    }

    int net_bits = i;

    int total_ip_in_each_network = pow(2, i);

    int Network_bits = host_bits - net_bits;

    int size_of_network = pow(2, Network_bits);

    string mask = "", subnet = "", total_mask = "";

    int total_net_bits = 16 + Network_bits;
    cout << endl
         << "Number of SubNets : " << size_of_network << endl
         << "Number of subnet bits : " << Network_bits;
    cout << endl
         << "Total Network bits : " << total_net_bits<<endl;

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 8; j++)
        {

            if (total_mask.length() < total_net_bits)
            {
                mask = mask + "1";
                total_mask += "1";
            }
            else
            {
                mask = mask + "0";
                total_mask += "0";
            }
        }
        subnet += to_string(binaryToDecimal(mask)) + ".";
        mask = "";
    }
    cout << "Subnet Mask = : " << subnet;
    cout << endl;

    return 0;
}
