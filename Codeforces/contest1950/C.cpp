#include <bits/stdc++.h>
using namespace std;

void solve(char *time) {
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    int minute = (time[3] - '0') * 10 + (time[4] - '0');

    string period;

    if (hour >= 12) {
        period = "PM";
        if (hour > 12) {
            hour -= 12;
        }
    } else {
        period = "AM";
        if (hour == 0) {
            hour = 12;
        }
    }

    cout << setw(2) << setfill('0') << hour << ":" << time[3] << time[4] << " " << period << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char time[6];
        cin >> time;
        solve(time);
    }

    return 0;
}
