#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int particionaParidade(vector<int>& vetor)
{
    int i = 0;
    int j = vetor.size() - 1;

    while (true) {
        while (i <= j && vetor[i] % 2 == 0) i++;   // avança enquanto for par
        while (i <= j && vetor[j] % 2 != 0) j--;   // recua enquanto for ímpar

        if (i >= j) {
            break;                                  // ponteiros se cruzaram
        }

        swap(vetor[i], vetor[j]);                   // i está num ímpar e j num par: troca
        i++;
        j--;
    }
    return i;
}

int main() {

    int n;
    cin >> n;
    vector<int> vetor(n);

    for (int& valor : vetor) {
        cin >> valor;
    }

    int fronteira = particionaParidade(vetor);

    // Pares (início até a fronteira): crescente
    sort(vetor.begin(), vetor.begin() + fronteira);
    // Ímpares (da fronteira até o fim): decrescente
    sort(vetor.begin() + fronteira, vetor.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        cout << vetor[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
