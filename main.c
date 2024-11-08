#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "employees.txt"

struct Employee {
    int id;
    char name[32];
    double weight;
    int height;
    double salary;
    int age;
};

void createEmployee();
void readEmployee();
void updateEmployee();
void deleteEmployee();
void calculateIMC(struct Employee emp);
void displayMenu();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createEmployee();
                break;
            case 2:
                readEmployee();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\nSistema de Gestão de Funcionários\n");
    printf("1. Adicionar funcionário\n");
    printf("2. Visualizar funcionário\n");
    printf("3. Atualizar funcionário\n");
    printf("4. Excluir funcionário\n");
    printf("5. Sair\n");
}

void createEmployee() {
    struct Employee emp;
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Não foi possível abrir o arquivo com os dados.");
        return;
    }

    printf("\nID do funcionário: ");
    scanf("%d", &emp.id);
    printf("Nome do funcionário: ");
    scanf("%s", emp.name);
    printf("Peso do funcionário (kg): ");
    scanf("%lf", &emp.weight);
    printf("Altura do funcionário (cm): ");
    scanf("%d", &emp.height);
    printf("Salário do funcionário: ");
    scanf("%lf", &emp.salary);
    printf("Idade do funcionário: ");
    scanf("%d", &emp.age);

    fprintf(file, "%d %s %lf %d %lf %d\n", emp.id, emp.name, emp.weight, emp.height, emp.salary, emp.age);
    fclose(file);

    printf("\nFuncionário criado com sucesso!\n");
}

void readEmployee() {
    int id;
    struct Employee emp;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Não foi possível abrir o arquivo com os dados.");
        return;
    }

    printf("\nInforme o ID do funcionário para visualização: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %lf %d %lf %d", &emp.id, emp.name, &emp.weight, &emp.height, &emp.salary, &emp.age) != EOF) {
        if (emp.id == id) {
            printf("\nID: %d\n", emp.id);
            printf("Nome: %s\n", emp.name);
            printf("Peso: %.2lf kg\n", emp.weight);
            printf("Altura: %d cm\n", emp.height);
            printf("Salário: %.2lf\n", emp.salary);
            printf("Idade: %d\n", emp.age);
            calculateIMC(emp);
            fclose(file);
            return;
        }
    }

    printf("Funcionário com ID %d não foi encontrado.\n", id);
    fclose(file);
}

void updateEmployee() {
    int id, found = 0;
    struct Employee emp;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        perror("Não foi possível abrir o arquivo com os dados.");
        return;
    }

    printf("\nInforme o ID do funcionário para atualizar: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %lf %d %lf %d", &emp.id, emp.name, &emp.weight, &emp.height, &emp.salary, &emp.age) != EOF) {
        if (emp.id == id) {
            found = 1;
            printf("\nNovo nome: ");
            scanf("%s", emp.name);
            printf("Novo peso (kg): ");
            scanf("%lf", &emp.weight);
            printf("Nova altura (cm): ");
            scanf("%d", &emp.height);
            printf("Novo salário: ");
            scanf("%lf", &emp.salary);
            printf("Nova idade: ");
            scanf("%d", &emp.age);
        }
        fprintf(tempFile, "%d %s %lf %d %lf %d\n", emp.id, emp.name, emp.weight, emp.height, emp.salary, emp.age);
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Funcionário atualizado com sucesso.\n");
    } else {
        remove("temp.txt");
        printf("Funcionário com ID %d não foi encontrado.\n", id);
    }
}

void deleteEmployee() {
    int id, found = 0;
    struct Employee emp;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        perror("Não foi possível abrir o arquivo com os dados.");
        return;
    }

    printf("\nInforme o ID do funcionário para excluir:  ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %lf %d %lf %d", &emp.id, emp.name, &emp.weight, &emp.height, &emp.salary, &emp.age) != EOF) {
        if (emp.id != id) {
            fprintf(tempFile, "%d %s %lf %d %lf %d\n", emp.id, emp.name, emp.weight, emp.height, emp.salary, emp.age);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Funcionário excluído com sucesso.\n");
    } else {
        remove("temp.txt");
        printf("Funcionário com ID %d não foi encontrado.\n", id);
    }
}

void calculateIMC(struct Employee emp) {
    double heightInMeters = emp.height / 100.0;
    double imc = emp.weight / (heightInMeters * heightInMeters);
    printf("IMC: %.2lf\n", imc);
}