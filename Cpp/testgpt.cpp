#include <bits/stdc++.h>
 
#define x first
#define y second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
 
ll a, b, c;
 
ii extended_gcd(ll a, ll b) {
    if (b == 0) return ii(1, 0);
 
    ii qr = ii(a / b, a % b);
    ii st = extended_gcd(b, qr.y);
 
    return ii(st.y, st.x - qr.x*st.y);
}

long long gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

 
int main() {
    int a = 5,b = 12, c = 45;
    long long d = gcd(a, b);
    ii ex = extended_gcd(a, b);
    printf("%lld %lldn", c/d*ex.x, c/d*ex.y);
    return 0;
}