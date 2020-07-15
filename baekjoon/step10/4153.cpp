#include <iostream>
using namespace std;

int main()
{
    int num[3];
    int max;

    cin >> num[0] >> num[1] >> num[2];
    while (num[0] || num[1] || num[2])
    {
        max = 0;
        for (int i = 1; i < 3; i++)
            if (num[max] < num[i])
                max = i;

        int notMax[2] = {(max + 1) % 3, (max + 2) % 3};

        if (num[max] * num[max] == num[notMax[0]] * num[notMax[0]] + num[notMax[1]] * num[notMax[1]])
            cout << "right" << '\n';
        else
            cout << "wrong" << '\n';

        cin >> num[0] >> num[1] >> num[2];
    }

    return 0;
}