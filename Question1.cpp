#include <iostream>
using namespace std;

struct Factor {
    int prime;
    int exp;
};

int main() {
    int n;
    cin >> n;

    Factor f[100];
    int cnt = 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f[cnt].prime = i;
            f[cnt].exp = 0;
            while (n % i == 0) {
                f[cnt].exp++;
                n = n / i;
            }
            cnt++;
        }
    }

    if (n > 1) {
        f[cnt].prime = n;
        f[cnt].exp = 1;
        cnt++;
    }

    for (int i = 0; i < cnt; i++) {
        if (i > 0) cout << " * ";
        cout << f[i].prime << "^" << f[i].exp;
    }
    cout << endl;

    return 0;
}

/*
Time Complexity: O(sqrt(n))
   - The outer for loop runs from i=2 to sqrt(n)
   - For each i, the while loop divides n by i
   - Total divisions across all iterations is at most log(n)
   - Overall: O(sqrt(n) + log(n)) = O(sqrt(n))
*/
