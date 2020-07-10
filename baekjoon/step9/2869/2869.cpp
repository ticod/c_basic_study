#include <iostream>
using namespace std;

int main()
{
    int A, B, V;
    cin >> A >> B >> V;

    cout << (V - B - 1) / (A - B) + 1;
    // 마지막 날에는 올라간 상태로 끝나고, 미끄러지지 않음
    // 따라서 올라가야 하는 높이는 V-B임

    // V-B-1 : 나눠 떨어지는 경우 몫이 횟수인데, 이 경우 +1을 해주면 안되므로
    // -1을 해주면 나눠 떨어질 때 (몫 - 0.xxxx)의 값이 나옴
    // 여기서 정수형 자료이므로 소수점이 잘리면서 (몫-1)이 됨

    // (A-B)+1 중 +1은 나눴을 때 예를 들어 2.xxx가 나온다면 3번을 올라가야 하므로
    // +1해줌

    return 0;
}