#include <iostream>
#include <vector>

using namespace std;

// Função responsável por juntar duas partes já ordenadas e contar as inversões
long long merge(vector<int>& vetor, int inicio, int meio, int fim)
{
    vector<int> aux;
    long long inversoes = 0;   // inversões contadas NESSE merge

    int i = inicio;
    int j = meio + 1;

    // Compara os elementos das duas partes
    while (i <= meio && j <= fim)
    {
        if (vetor[i] <= vetor[j]) {
            aux.push_back(vetor[i]);
            i++;
        }
        else {
            aux.push_back(vetor[j]);
            j++;
            // Quem ainda sobrou na esquerda é maior que vetor[j]
            inversoes += meio - i + 1;
        }
    }

    // Caso ainda existam elementos na parte esquerda
    while (i <= meio) {
        aux.push_back(vetor[i]);
        i++;
    }

    // Caso ainda existam elementos na parte direita
    while (j <= fim) {
        aux.push_back(vetor[j]);
        j++;
    }

    // Copia os elementos ordenados de volta para o vetor original
    for (int k = 0; k < aux.size(); k++) {
        vetor[inicio + k] = aux[k];
    }

    return inversoes;
}

long long mergeSort(vector<int>& vetor, int inicio, int fim)
{
    // Caso base da recursão
    if (inicio >= fim) {
        return 0;
    }

    int meio = (inicio + fim) / 2;

    long long total = 0;
    total += mergeSort(vetor, inicio, meio);       // inversões da esquerda
    total += mergeSort(vetor, meio + 1, fim);      // inversões da direita
    total += merge(vetor, inicio, meio, fim);      // inversões entre as duas metades

    return total;
}

int main() {

    int n;
    cin >> n;
    vector<int> vetor(n);

    for (int& valor : vetor) {
        cin >> valor;
    }

    long long inversoes = mergeSort(vetor, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << vetor[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    cout << inversoes << "\n";

    return 0;
}
