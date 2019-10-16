#include <iostream>

using namespace std;

int Primes[11] = {2,3,5,7,11,13,17,19,23,29,31};

bool isPrim(int n,int s,int f){
    if(f>=s){
        int middle=(f+s+1)/2;
        if(Primes[middle]==n) return true;
        else if(Primes[middle]>n) return isPrim(n,s,middle-1);
        else return isPrim(n,middle+1,f);
    }
    return false;
}
void primRing(int* num,bool* visit,int p,int n)
{
    if (p == n) {
        if (isPrim(num[n-1] + 1,0,10)) {
            cout << 1;
            for (int i = 1; i < n; ++i) cout << ' ' << num[i];
            cout << '\n';
        }
    } else {
        for (int i = 1; i < n; ++i) {
            if (!visit[i]) {
                if (isPrim(i+1+num[p - 1], 0, 10)) {
                    visit[i] = 1;
                    num[p] = i+1;
                    primRing(num, visit, p + 1, n);
                    visit[i] = 0;
                }
            }
        }
    }
}
int main()
{
    int *num;
    bool *visit;
    int  n,c = 0;
    while (cin >> n) {
        num = new int[n]; num[0] = 1;
        visit = new bool[n]; *visit = {0};
        if (c) cout << '\n';
        cout << "Case " << ++c << ':' << '\n';
        primRing(num,visit,1,n);
    }
}