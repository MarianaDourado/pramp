#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

void flip(int k){
    reverse(v.begin(), v.begin()+k);
}

int ret_max_index(int ate){
    int max_idx;
    int maxx = v[0];
    for(int i=0; i<ate;i++){
        if(v[i] >= maxx){
            maxx = v[i];
            max_idx = i;
        }
    }
    
    return max_idx;
}

void dxeuv(){
    for(int i=0; i<n;i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main()
{
    cin >> n;
    v.resize(n);
    
    for(int i=0; i<n;i++){
        cin >> v[i];
    }
    int k = n;
    while(k){
        flip(ret_max_index(k)+1);
        dxeuv();
        flip(k);
        dxeuv();
        k--;
    }

    return 0;
}
