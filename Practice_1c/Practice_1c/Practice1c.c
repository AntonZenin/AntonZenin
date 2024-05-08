#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"

#define L 255 


FilmLib* readFilmDataFromFile(char* filename, FilmLib* Lib) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    fscanf(file, "%d ", &(Lib->count));
    Lib->films = (Film*)malloc(Lib->count * sizeof(Film));

    for (int i = 0; i < Lib->count; i++) {
        char buffer[L];
        fgets(buffer, sizeof(buffer), file);

        char* token = strtok(buffer, ";");
        Lib->films[i].title = _strdup(token);

        token = strtok(NULL, ";");
        Lib->films[i].director = (Director*)malloc(sizeof(Director));
        Lib->films[i].director->directorFirstName = _strdup(token);

        token = strtok(NULL, ";");
        Lib->films[i].director->directorLastName = _strdup(token);

        token = strtok(NULL, ";");
        Lib->films[i].country = _strdup(token);

        token = strtok(NULL, ";");
        Lib->films[i].year = atoi(token);

        token = strtok(NULL, ";");
        Lib->films[i].budget = atof(token);

        token = strtok(NULL, ";");
        Lib->films[i].boxOffice = atof(token); 
    }

    fclose(file);
}

void printFilmsByDirector(FilmLib* Lib, char* firstName, char* lastName) { 
    int isFound = 0;
    for (int i = 0; i < Lib->count; i++) {
        if (strcmp(Lib->films[i].director->directorFirstName, firstName) == 0 && strcmp(Lib->films[i].director->directorLastName, lastName) == 0) {  
            isFound = 1;
            printFilmInfo(&Lib->films[i]); 
        }
    }
    if (!isFound) {
        printf("Films not found for director: %s %s\n", firstName, lastName); 
    }
}

void printFilmInfo(Film* film) { 
    printf("Title: %s\n", film->title);
    printf("Director: %s %s\n", film->director->directorFirstName, film->director->directorLastName);
    printf("Country: %s\n", film->country);
    printf("Year: %d\n", film->year);
    printf("Budget:  %.2f\n", film->budget);
    printf("Box Office: %.2f\n", film->boxOffice);
    printf("\n");
} 


void freeFilmLibrary(FilmLib* Lib) {
    for (int i = 0; i < Lib->count; i++) {
        free(Lib->films[i].title);
        free(Lib->films[i].director->directorFirstName); 
        free(Lib->films[i].director->directorLastName); 
        free(Lib->films[i].director);  
        free(Lib->films[i].country); 
    }
    free(Lib->films);
}

