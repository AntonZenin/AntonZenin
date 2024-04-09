#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"

#define MAX_LENGTH 100  




int main() {
    int choice;
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    FilmLib* lib = createFilmLib(11);//Assume we have 11 films in the file
    do {
        printf("\nInput choice for operations: 0 - show full library, 1 - start searching the Director, 2 - close the program\n");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            readFilmDataFromFile("films.txt", lib);
            for (int i = 0; i < lib->numFilms; i++) {
                printFilmInfo(&lib->films[i]);
            }
            break;
        case 1:
            readFilmDataFromFile("films.txt", lib);


            printf("Enter director's first name: ");
            scanf("%s", firstName);
            printf("Enter director's last name: ");
            scanf("%s", lastName);

            printf("\nFilms by %s %s:\n", firstName, lastName);
            printFilmsByDirector(lib, firstName, lastName);

            break;
        case 2:
            break;
        default:
            printf("Wrong choice\n");
        }

    } while (choice != 2);

    freeFilmLibrary(&lib);

    return 0;
}




