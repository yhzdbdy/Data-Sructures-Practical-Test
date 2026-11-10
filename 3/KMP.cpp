#include<bits/stdc++.h>
using namespace std;

void buildNext(vector<int>& next, string& p) {
    int m = p.size();
    int k = -1; next[0] = -1;
    for(int i = 0; i < m - 1; i++) {
        while(k >= 0 && p[i] != p[k]) {
            k = next[k];
        }
        next[i + 1] = ++k;
    }
}

int KMP(string& p, string& t) {
    int m = p.size();
    int n = t.size();

    vector<int> next(m);
    buildNext(next, p);
    int i = 0; int j = 0;
    while(i < m && j < n) {
        if(i == -1 || t[j] == p[i]) {
            i++; j++;
        } else {
            //改变j
            i = next[i];
        }
    }
    cout << next[m / 4] << " " << next[2 * m / 4] << " " << next[3 * m / 4] << " " <<endl; 
    return i == m ? j - m : -1;
}
int main() {
    string t;
    string p;
    cin >> t;
    cin >> p;
    cout << KMP(p, t);
}