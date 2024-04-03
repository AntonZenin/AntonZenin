#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"

#define MAX_LENGTH 100


void readFilmData(FILE* file, Film* film) {
    film->title = (char*)malloc(MAX_LENGTH * sizeof(char));
    film->directorSurname = (char*)malloc(MAX_LENGTH * sizeof(char));
    film->directorName = (char*)malloc(MAX_LENGTH * sizeof(char));
    film->country = (char*)malloc(MAX_LENGTH * sizeof(char));

    fscanf(file, "%s", film->title);
    fscanf(file, "%s", film->directorSurname);
    fscanf(file, "%s", film->directorName);
    fscanf(file, "%s", film->country);
    fscanf(file, "%d", &(film->year));
    fscanf(file, "%lf", &(film->budget));
    fscanf(file, "%lf", &(film->gross));
}

void printFilmData(Film* film) {
    printf("\nTitle: %s\n", film->title);
    printf("Director: %s %s\n", film->directorName, film->directorSurname);
    printf("Country: %s\n", film->country);
    printf("Year: %d\n", film->year);
    printf("Budget: %.2lf\n", film->budget);
    printf("Gross: %.2lf\n", film->gross);

}

void findFilmByDirector(FILE* file, const char* directorName, const char* directorSurname) {
    Film film;
    int isFound = 0;

    while (!feof(file)) {
        readFilmData(file, &film);

        if (strcmp(film.directorName, directorName) == 0 && strcmp(film.directorSurname, directorSurname) == 0) {
            printFilmData(&film);
            isFound = 1;
        }
    }

    if (!isFound) {
        printf("Film not found for director: %s %s\n", directorName, directorSurname);
    }
}

void freeFilms(Film* film) {
    free(film->title);
    free(film->directorSurname);
    free(film->directorName);
    free(film->country); 

    free(film);
} 
