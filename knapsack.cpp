#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> W;
std::vector<int> V;


struct WI
{
    int w;
    int i;
};

bool operator<(const WI& A, const WI& B)
{
    if (A.w != B.w)
        return A.w < B.w;
    return A.i < B.i;
}

std::map<WI, int> M;

int knapsack(int w, int i)
{
    if (w == 0 || i == 0)
        return 0;
    
    WI wi = {w,i};
    auto it = M.find(wi);
    
    if (it != M.end())
    {
        return it->second;
    }
    
    int respuesta;
    if (W[i-1] <= w)
        respuesta =  std::max(knapsack(w,i-1), knapsack(w-W[i-1],i-1)+V[i-1]);
    else
        respuesta = knapsack(w,i-1);
    
    M[wi] = respuesta;
    return respuesta;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N;
        std::cin >> N;
        
        int w;
        std::cin >> w;
        
        W.clear();
        V.clear();
        M.clear();
        
        W.resize(N);
        V.resize(N);
        
        for (auto& v : V)
            std::cin >> v;
        
        for (auto& w : W)
            std::cin >> w;
        
        std::cout << knapsack(w, N) << std::endl;
    }
    
    return 0;
}


