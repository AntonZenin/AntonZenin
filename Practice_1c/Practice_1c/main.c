#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"

#define MAX_LENGTH 100


int main() {

    char directorName[MAX_LENGTH];
    char directorSurname[MAX_LENGTH];
    int choice;

    do {
        FILE* file = fopen("films.txt", "r");


        if (file == NULL) {
            printf("Failed to open the file.\n");
            return 1;
        }
        printf("\nInput choice for operatinos: 1 - search for films, 2 - close the program\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter director's name: ");
            scanf("%s", directorName);

            printf("Enter director's surname: ");
            scanf("%s", directorSurname);

            findFilmByDirector(file, directorName, directorSurname);
            fclose(file);

            break;
        case 2:
            break;
        default:
            printf("Wrong choice\n");
        }

    } while (choice != 2);

    freeFilms; 


    return 0;
}