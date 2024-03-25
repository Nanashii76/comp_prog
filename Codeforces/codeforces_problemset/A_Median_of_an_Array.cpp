#include <bits/stdc++.h>

typedef long long ll;

int partition(std::vector<int> v, int l, int r) {

    int piv = v[r]; int j = l;
    for(int i = l; i < r; ++i)
        if(v[i] < piv) {
            std::swap(v[j],v[i]);
            j++;
        }
    std::swap(v[j],v[r]);

    return j;

}

int quick_select(std::vector<int> v, int l, int r, int k) {

    // condição de parada
    if(l >= r)
        return 1;

    int count = 0;

    // retorna o valor do pivor
    int i = partition(v,l,r);

    // como o quick sort garante que todos os elementos anteriores e posteriores
    // do vetor são respectivamente menores e maiores que ele
    // então podemos utilizar a mesma lógica da busca binária
    if(i > k) {
        count += quick_select(v,l,i-1,k);
    } 
    
    if (i < k) {
        count += quick_select(v,l,i+1,k);
    }

    return count;

}

void solve(std::vector<int> vec){

    int mid = vec.size()/2;
    std::cout << quick_select(vec,0,vec.size(),mid) << std::endl;

}


int main(void) {

    int n; std::cin >> n;
    
    for(int i = 0; i < n; ++i) {
        int a; std::cin >> a;
        std::vector<int> vec(a);
        for(int j = 0; j < a; ++i) {
            int aux; std::cin >> aux;
            vec.emplace_back(aux);
        }
        solve(vec);
    }

    return EXIT_SUCCESS;
}

