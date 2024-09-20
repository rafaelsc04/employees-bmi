#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

typedef struct sqlite3 sqlite3;

struct Employee {
	int id;
	char* name;
	double weight;
	int height;
};

double calcIMC(struct Employee employee) {
	double properHeight = employee.height / 100.0;
	return (employee.weight / (properHeight * properHeight));
}

void printEmployee(struct Employee emp) {
	printf("Employee[id=%d name=%s weight=%.2f height=%d imc=%.2f]\n", 
			emp.id, emp.name, emp.weight, emp.height, calcIMC(emp));
}

int queryCallback(void *employees, int rowCount, char** columnValues, char** columnName) {
	struct Employee emp = {
		atoi(columnValues[0]), 
		columnValues[1], 
		atof(columnValues[2]), 
		atoi(columnValues[3])
	};
	printEmployee(emp);

	return 0;
}

int main() {
	struct Employee emp;
	int opt;

	sqlite3* db;
	sqlite3_open("health.db", &db);

	printf("Digite uma opção:\n\n\t"
			"1. Consultar todos funcionários\n\t"
			"2. Inserir novo funcionário\n\t"
			"3. Deletar um funcionário\n\t"
			"4. Visualizar um funcionário\n\t"
			"0. Sair\n\n> ");

	scanf("%d", &opt);

	switch(opt) {
		case 1:
			printf("\nConsultando todos funcionários...\n\n");

			char *errorMsgs;
			void* vptr;

			sqlite3_exec(db, "SELECT * FROM employees;", (*queryCallback), vptr, &errorMsgs);
			break;
		case 2:
			printf("\nInserindo um novo funcionário...\n");
			break;
		case 3:
			printf("\nDeletando um funcionário...\n");
			break;
		case 4:
			printf("\nVisualizando um funcionário...\n");
			break;
		case 0:
			printf("\nSaindo...\n");
			return 0;
		default:
			printf("\nOpção inválida - saindo...\n");
			return 1;
	}
	printf("\nSaindo...\n");
	return 0;
}
