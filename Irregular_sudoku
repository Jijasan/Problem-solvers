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
vector<vector<int> > jij, c, comp;

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
                int coord = comp[c[i][j]][y];
                int x = coord/n, h = coord%n;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    m = n;
    n = n*n;
    c.resize(n, vector<int>(n));
    comp.resize(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int a;
            cin >> a;
            a--;
            c[i][j] = a;
            comp[a].push_back(i*n+j);
        }
    }
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
        if(i==0||c[i][0]!=c[i-1][0])
            cout << '+';
        else
            cout << '|';
        for(int j = 0; j<n; j++){
            if(i==0||c[i][j]!=c[i-1][j])
                cout << '-';
            else
                cout << ' ';
            if(j<n-1){
                if((i==0&&c[i][j]!=c[i][j+1])||((c[i][j]!=c[i][j+1]||(i&&c[i-1][j]!=c[i-1][j+1]))&&(i&&(c[i][j]!=c[i-1][j]||c[i][j+1]!=c[i-1][j+1]))))
                    cout << '+';
                else if(i&&c[i][j]==c[i][j+1]&&c[i][j]==c[i-1][j]&&c[i][j]==c[i-1][j+1])
                    cout << ' ';
                else if(c[i][j]!=c[i][j+1])
                    cout << '|';
                else
                    cout << '-';
            }
        }
        if(i==0||c[i][n-1]!=c[i-1][n-1])
            cout << '+';
        else
            cout << '|';
        cout << endl;
        cout << '|';
        for(int j = 0; j<n; j++){
            cout << a[i][j];
            if(j<n-1){
                if(c[i][j]!=c[i][j+1])
                    cout << '|';
                else
                    cout << ' ';
            }
        }
        cout << '|' << endl;
    }
    cout << '+';
    for(int i = 0; i<n; i++){
        cout << '-';
        if(i<n-1){
            if(c[n-1][i]!=c[n-1][i+1])
                cout << '+';
            else
                cout << '-';
        }
    }
    cout << '+';

    return 0;
}
