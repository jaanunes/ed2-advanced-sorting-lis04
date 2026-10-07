#include <iostream>
#include <vector>
using namespace std;

long long trocas = 0;   // conta apenas trocas entre posições DIFERENTES

void trocar(vector<int>& vetor, int a, int b)
{
    if (a == b) {
        return;
    }
    swap(vetor[a], vetor[b]);
    trocas++;
}

// pivô é o último elemento
int particiona(vector<int>& vetor, int inicio, int fim)
{
    int pivo = vetor[fim];
    int i = inicio - 1;        // fim da zona da esquerda (começa vazia)

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(vetor, i, j);
        }
    }

    trocar(vetor, i + 1, fim);       // pivô vai para o meio das duas zonas
    return i + 1;
}

// Quickselect: procura o elemento que ficaria na posição 'alvo' se o vetor estivesse ordenado
int quickselect(vector<int>& vetor, int alvo)
{
    int inicio = 0;
    int fim = vetor.size() - 1;

    while (inicio <= fim) {
        int p = particiona(vetor, inicio, fim);

        if (p == alvo) {
            return vetor[p];          // achou
        }
        if (p < alvo) {
            inicio = p + 1;           // o que procuro está na direita
        }
        else {
            fim = p - 1;              // o que procuro está na esquerda
        }
    }
    return -1; // não acontece com entrada válida
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> vetor(n);

    for (int& valor : vetor) {
        cin >> valor;
    }

    // K-ésimo maior = posição (n - k) na ordem crescente
    int resultado = quickselect(vetor, n - k);

    cout << resultado << "\n";
    for (int i = 0; i < n; i++) {
        cout << vetor[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    cout << trocas << "\n";

    return 0;
}
