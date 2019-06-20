#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

int it = 0, n, m;
vector<vector<int> > jij;

void print(vector<vector<int> > a){
    cout << it << ":\n";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << "::::::::::::::::" << endl;
}

vector<vector<int> > solve(vector<vector<int> > a){
    it++;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int y = 0; y<n; y++){
                if(a[i][j]==0)
                    continue;
                if(a[i][j]==a[i][y]&&j!=y)
                    return jij;
                if(a[i][j]==a[y][j]&&i!=y)
                    return jij;
                int x = (i/m)*m+(y/m), h = (j/m)*m+y%m;
                if(a[i][j]==a[x][h]&&!(x==i&&h==j))
                    return jij;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j]!=0)
                continue;
            for(int y = 1; y<=n; y++){
                a[i][j] = y;
                vector<vector<int> > kek = solve(a);
                if(kek!=jij)
                    return kek;
            }
            return jij;
        }
    }
    return a;
}

string gensep(){
    string ans = "+ ";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans.push_back('-');
            ans.push_back(' ');
        }
        ans.push_back('+');
        ans.push_back(' ');
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string sep = gensep();
    m = n;
    n = n*n;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> a[i][j];
    a = solve(a);
    if(a==jij){
        cout << "No solution";
        return 0;
    }
    cout << "Solved in " << it << " iterations" << endl;
    for(int i = 0; i<n; i++){
        if(i%m==0)
            cout << sep << endl;
        for(int j = 0; j<n; j++){
            if(j%m==0)
                cout << "| ";
            cout << a[i][j] << ' ';
        }
        cout << '|' << endl;
    }
    cout << sep << endl;

    return 0;
}
