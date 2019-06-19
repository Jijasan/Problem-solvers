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
//#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

int it = 0, n;
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
    //print(a);
    it++;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int y = 0; y<n; y++){
                //cout << i << ':' << j << ' ' << y << endl;
                if(a[i][j]==0)
                    continue;
                if(a[i][j]==a[i][y]&&j!=y)
                    return jij;
                if(a[i][j]==a[y][j]&&i!=y)
                    return jij;
                int x = (i/3)*3+(y/3), h = (j/3)*3+y%3;
                //if(it==1)
                    //cout << i << ':' << j << ' ' << x << ':' << h << endl;
                if(a[i][j]==a[x][h]&&!(x==i&&h==j))
                    return jij;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j]!=0)
                continue;
            for(int y = 1; y<10; y++){
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
    n = n*n;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            cin >> a[i][j];
    a = solve(a);
    cout << "Solved in " << it << " iterations" << endl;
    for(int i = 0; i<n; i++){
        if(i%3==0)
            cout << "+ - - - + - - - + - - - +" << endl;
        for(int j = 0; j<n; j++){
            if(j%3==0)
                cout << "| ";
            cout << a[i][j] << ' ';
        }
        cout << '|' << endl;
    }
    cout << "+ - - - + - - - + - - - +" << endl;

    return 0;
}
/*
3
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0
*/
