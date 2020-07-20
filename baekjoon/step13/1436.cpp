    #include <iostream>
    using namespace std;

    int solve(int movieNumber)
    {
        int temp[100];
        int i = 0;
        temp[i++] = movieNumber % 10;
        while ((movieNumber /= 10) > 10)
        {
            temp[i++] = movieNumber % 10;
        }
        temp[i] = movieNumber;

        int count = 0;
        for (int j = 0; j <= i; j++)
        {
            if (temp[j] == 6)
            {
                if (++count == 3)
                    return 1;
            }
            else
                count = 0;
        }
        return 0;
    }

    int main()
    {
        int N;
        cin >> N;

        int temp[100] = {
            0,
        };
        int movieNumber = 666;

        for (int i = 1; i < N; i++)
        {
            while (!solve(++movieNumber))
                ;
        }

        cout << movieNumber << '\n';

        return 0;
    }