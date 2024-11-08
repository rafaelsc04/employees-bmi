#include <stdio.h>

/*

Correções:
    - [] Adicionar na Struct a quantidade de elementos mínima querida para a tarefa (6)
    - [] Adicionar o descritivo das variáveis e de seus tamanhos
    - [] Incluir aspas ao referenciar as variáveis no documento
    - [] Fazer um CRUD completo
    - [] Evidencias dos testes
    - [] Evidencias das funções desenvolvidas
    - [] Evidencias das escritas nos arquivos
    - [] Apresentar o código completo no PDF

*/

struct Employee {
    int id;
    char name[32];
    double weight;
    int height;
    double salary;
    int age;
};

int main() {
    int option;
    printf("Option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Option 1\n");
            break;
        case 2:
            printf("Option 2\n");
            break;
        default:
            printf("Quitting...");
            break;
    }

    
    return 0;
}