#include <stdio.h>

int validaQuantidade();
float calculaSalario(int quantidadePecas);
void mostraFinal(float salario);

int main() {
    int quantidadePecas, numFuncionarios;

    printf("Quantos funcionarios tem na empresa? ");
    scanf("%d", &numFuncionarios);

    for (int i = 1; i <= numFuncionarios; i++) {
        printf("\nFuncionario %d:\n", i);
        quantidadePecas = validaQuantidade();

        float salario = calculaSalario(quantidadePecas);

        mostraFinal(salario);
    }

    return 0;
}

int validaQuantidade() {
    int quantidadePecas;

    do {
        printf("Quantas pecas foram fabricadas? ");
        scanf("%d", &quantidadePecas);

        if (quantidadePecas < 0) {
            printf("Digite um numero Positivo.\n");
        }

    } while (quantidadePecas < 0);

    return quantidadePecas;
}

float calculaSalario(int quantidadePecas) {
    const float salarioBase = 600.0;
    const int limite50 = 50;
    const int limite80 = 80;
    const float adicional50 = 0.5;
    const float adicional80 = 0.75;

    float salarioTotal = salarioBase;

    if (quantidadePecas > limite50) {
        salarioTotal += (quantidadePecas - limite50) * adicional50;

        if (quantidadePecas > limite80) {
            salarioTotal += (quantidadePecas - limite80) * (adicional80 - adicional50);
        }
    }

    return salarioTotal;
}


void mostraFinal(float salario) {
    printf("O salario total e: R$ %.2f\n", salario);
}
