#include <stdio.h>

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