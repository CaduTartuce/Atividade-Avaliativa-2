#include <stdio.h>

int validarSexo(char sexo) {
    return sexo == 'M' || sexo == 'F';
}

int validarSalario(float salario) {
    return salario > 1.00;
}

char classificarSalario(float salario) {
    if (salario > 1421.00) {
        return 'A';
    } else if (salario == 1421.00) {
        return 'I';
    } else {
        return 'B';
    }
}

void mostraClassificacao(char nome[], char sexo, float salario) {
    char classificacao = classificarSalario(salario);
    char sexoPorExtenso = (sexo == 'M') ? 'Masculino' : 'Feminino';

    printf("Nome: %s\n", nome);
    printf("Sexo: %s\n", (sexo == 'M') ? "Masculino" : "Feminino");
    printf("Salario: R$ %.2f\n", salario);
    printf("Classificação em relacao ao salario minimo: ");

    switch (classificacao) {
        case 'A':
            printf("Acima\n");
            break;
        case 'I':
            printf("Igual\n");
            break;
        case 'B':
            printf("Abaixo\n");
            break;
    }

    printf("-------------------------------\n");
}

int main() {
    int quantidadeAssalariados, totalAbaixo = 0, totalAcima = 0;
    char nome[100], sexo;
    float salario;

    printf("Informe a quantidade de assalariados: ");
    scanf("%d", &quantidadeAssalariados);

    for (int i = 1; i <= quantidadeAssalariados; i++) {
        do {
            printf("Informe o nome do assalariado %d: ", i);
            scanf("%s", nome);
        } while (nome[0] == '\0');

        do {
            printf("Informe o sexo do assalariado %d (M/F): ", i);
            scanf(" %c", &sexo);
        } while (!validarSexo(sexo));

        do {
            printf("Informe o salario do assalariado %d: ", i);
            scanf("%f", &salario);
        } while (!validarSalario(salario));

        mostraClassificacao(nome, sexo, salario);

        if (classificarSalario(salario) == 'B') {
            totalAbaixo++;
        } else if (classificarSalario(salario) == 'A') {
            totalAcima++;
        }
    }

    printf("Assalariados com salario abaixo do minimo: %d\n", totalAbaixo);
    printf("Assalariados com salario acima do minimo: %d\n", totalAcima);
}
