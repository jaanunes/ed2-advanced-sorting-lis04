#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ---------------------- MERGE SORT (estável) ----------------------

// Junta duas partes já ordenadas, em ordem DECRESCENTE de tamanho
void merge(vector<string>& vetor, int inicio, int meio, int fim)
{
    vector<string> aux;
    int i = inicio;
    int j = meio + 1;

    while (i <= meio && j <= fim)
    {
        if (vetor[i].size() >= vetor[j].size()) {
            aux.push_back(vetor[i]);
            i++;
        }
        else {
            aux.push_back(vetor[j]);
            j++;
        }
    }

    while (i <= meio) {
        aux.push_back(vetor[i]);
        i++;
    }

    while (j <= fim) {
        aux.push_back(vetor[j]);
        j++;
    }

    for (int k = 0; k < aux.size(); k++) {
        vetor[inicio + k] = aux[k];
    }
}

void mergeSort(vector<string>& vetor, int inicio, int fim)
{
    if (inicio >= fim) {
        return;
    }

    int meio = (inicio + fim) / 2;

    mergeSort(vetor, inicio, meio);
    mergeSort(vetor, meio + 1, fim);
    merge(vetor, inicio, meio, fim);
}

// ---------------------- QUICK SORT (instável) ----------------------

int particiona(vector<string>& vetor, int inicio, int fim)
{
    int pivo = vetor[fim].size();
    int i = inicio - 1;               // fim da zona da esquerda (começa vazia)

    for (int j = inicio; j < fim; j++) {
        if (vetor[j].size() >= pivo) {
            i++;
            swap(vetor[i], vetor[j]);
        }
    }

    swap(vetor[i + 1], vetor[fim]);   // pivô vai para o meio das duas zonas
    return i + 1;
}

void quickSort(vector<string>& vetor, int inicio, int fim)
{
    if (inicio >= fim) {
        return;
    }

    int p = particiona(vetor, inicio, fim);

    quickSort(vetor, inicio, p - 1);  // zona da esquerda do pivô
    quickSort(vetor, p + 1, fim);     // zona da direita do pivô
}

int main() {

    int n;
    cin >> n;
    vector<string> palavras(n);

    for (string& p : palavras) {
        cin >> p;
    }

    // Duas cópias da mesma entrada
    vector<string> copiaMerge = palavras;
    vector<string> copiaQuick = palavras;

    mergeSort(copiaMerge, 0, n - 1);
    quickSort(copiaQuick, 0, n - 1);

    cout << "[MergeSort]";
    for (string& p : copiaMerge) cout << " " << p;
    cout << "\n";

    cout << "[QuickSort]";
    for (string& p : copiaQuick) cout << " " << p;
    cout << "\n";

    return 0;
}
