# ED2 - Lista 04: Merge Sort e Quick Sort (C++)

Exercícios de fixação da disciplina **Estrutura de Dados II**, do curso de **Tecnologia em Análise e Desenvolvimento de Sistemas**


## Exercícios

| # | Arquivo | Problema | Técnica | Complexidade |
|---|---------|----------|---------|--------------|
| 1 | `Exer01_MergeSortCountInversions.cpp` | Contagem de inversões | Merge Sort | O(N log N) |
| 2 | `Exer02_StabilityMergeSortVsQuickSort.cpp` | Estabilidade: Merge Sort vs. Quick Sort | Merge Sort e Quick Sort (Lomuto) | O(N log N) |
| 3 | `Exer03_QuickselectLomutoKthLargest.cpp` | K-ésimo maior elemento | Quickselect com Lomuto | O(N) médio |
| 4 | `Exer04_HoarePartitionParitySort.cpp` | Ordenação par-ímpar | Particionamento de Hoare | O(N) na partição |

### Resumo da solução

1. **Contagem de inversões:** durante a intercalação do Merge Sort, sempre que um elemento da metade direita é posicionado antes dos que restam na metade esquerda, somam-se esses restantes (`meio - i + 1`) ao contador. O contador usa `long long`, pois o total pode ultrapassar o limite de um `int`.
2. **Estabilidade:** o Merge Sort usa `>=` na intercalação, de modo que, no empate de tamanho, a palavra da esquerda (que veio antes) sai primeiro. O Quick Sort com Lomuto faz trocas entre posições distantes, o que embaralha a ordem relativa de palavras com o mesmo tamanho.
3. **Quickselect:** o particionamento de Lomuto (pivô no último elemento) é repetido apenas na metade que contém a posição `n - k`. Só são contadas as trocas entre índices diferentes (`i != j`).
4. **Par-ímpar:** dois ponteiros convergentes (Hoare) separam pares e ímpares em O(N). Em seguida, os pares são ordenados em ordem crescente e os ímpares em ordem decrescente.


## Como compilar e executar

Requisitos: compilador C++ com suporte a C++20 e CMake.

```bash
cmake -S . -B build
cmake --build build
```

Cada exercício gera um executável próprio. A entrada é lida pela entrada padrão (`stdin`):

```bash
./build/Exer01_MergeSortCountInversions
./build/Exer02_StabilityMergeSortVsQuickSort
./build/Exer03_QuickselectLomutoKthLargest
./build/Exer04_HoarePartitionParitySort
```

No **CLion**, basta escolher o alvo do exercício desejado ao lado do botão de executar.

