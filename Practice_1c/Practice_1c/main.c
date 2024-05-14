#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"

#define L 255  


int main(int argc, char** argv)
{
    int choice = 0;
    char firstName[L];
    char lastName[L];
    FilmLib Lib;
    FilmLib* newlib;
    char* infilename;
    if (argc < 2)
    {
        printf("Incorrect arguments!");
        return 0;
    }
    infilename = argv[1];

    readFilmDataFromFile(infilename, &Lib);

    do {
        printf("\nInput choice: 0 - show full library, 1 - search director, 2 - exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 0:
            printFilmLibrary(&Lib);
            break;
        case 1:
            printf("Enter director's first name: ");
            scanf("%s", firstName);
            printf("Enter director's last name: ");
            scanf("%s", lastName);
            newlib = printFilmsByDirector(&Lib, firstName, lastName);
            printFilmLibrary(newlib);
            break;
        case 2:
            break;


        default:
            printf("Wrong choice\n");
        }
    } while (choice != 2);

    freeFilmLibrary(&Lib);

    return 0;
}



