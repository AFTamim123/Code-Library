#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
int mark[10000002];
void siv() {
    long long n = 10000000;
    for (int i = 2; i <= n; i++)
    {
        if(mark[i]) continue;
        prime.push_back(i);
        for (int j = 2*i; j <= n; j+=i)
        {
            mark[j]=1; //0->prime,  1->not prime
        }
    }
}


int main() {

    siv();
    
    return 0;
}