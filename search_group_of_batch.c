#teste

#include <stdio.h>
#include <stdlib.h>

// Função de comparação usada pelo qsort
int compare(const void *a, const void *b)
{
    double num1 = *(double *)a;
    double num2 = *(double *)b;
    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int main()
{
    // Array de números fornecidos
    double numbers[] = {
        47.85, 161.98, 93.86, 1418.23, 330.26, 45.02, 216.42, 20619.23,
        602.76, 466.71, 20088.75, 1137.44, 687.69, 18951.03, 37.74, 157.71,
        967.69, 749.04, 278.40, 334.41, 507.74, 773.22, 281.73, 281.40,
        77.62, 185.60};

    // Calculando o número de elementos no array
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Ordenando o array usando qsort
    qsort(numbers, size, sizeof(double), compare);

    // Imprimindo os números armazenados no array
    printf("Números armazenados na lista (ordenados do menor para o maior):\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.2f\n", numbers[i]);
    }
    printf("\n");
    printf("Lotes: 8521,06, 60978,47");
    printf("\n");

    // Solicitar ao usuário para informar a quantidade de lotes
    int numLotes;
    printf("Informe a quantidade de lotes: ");
    scanf("%d", &numLotes);

    // Alocar memória para armazenar os valores dos lotes
    double *lotes = (double *)malloc(numLotes * sizeof(double));
    if (lotes == NULL)
    {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Solicitar ao usuário para informar o valor de cada lote
    for (int i = 0; i < numLotes; i++)
    {
        printf("Informe o valor do lote %d: ", i + 1);
        scanf("%lf", &lotes[i]);
    }

    // Ordenar os valores dos lotes
    qsort(lotes, numLotes, sizeof(double), compare);

    // Dividir a lista de números em grupos com base nos valores dos lotes
    printf("\nDivisão dos números em grupos com base nos lotes:\n");
    int currentIndex = 0;
    for (int i = 0; i < numLotes; i++)
    {
        printf("Grupo %d (até %.2f):\n", i + 1, lotes[i]);
        double somaGrupo = 0.0;
        while (currentIndex < size && numbers[currentIndex] <= lotes[i])
        {
            printf("%.2f\n", numbers[currentIndex]);
            somaGrupo += numbers[currentIndex];
            currentIndex++;
        }
        printf("Soma do grupo %d: %.2f\n\n", i + 1, somaGrupo);
    }
    // Imprimir quaisquer números restantes no último grupo
    if (currentIndex < size)
    {
        printf("Grupo %d (acima de %.2f):\n", numLotes + 1, lotes[numLotes - 1]);
        double somaGrupo = 0.0;
        while (currentIndex < size)
        {
            printf("%.2f\n", numbers[currentIndex]);
            somaGrupo += numbers[currentIndex];
            currentIndex++;
        }
        printf("Soma do grupo %d: %.2f\n", numLotes + 1, somaGrupo);
    }

    // Liberar a memória alocada
    free(lotes);

    return 0;
}
