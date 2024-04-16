#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Practice1c.h"

#define MAX_LENGTH 100 


FilmLib* createFilmLib(int size) {
    FilmLib* lib = (FilmLib*)malloc(sizeof(FilmLib));
    lib->films = (Film*)malloc(size * sizeof(Film));
    lib->numFilms = size;
    return lib;
}


void readFilmDataFromFile(char* fileName, FilmLib* lib) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    for (int i = 0; i < lib->numFilms; i++) {
        char buffer[MAX_LENGTH];
        fgets(buffer, sizeof(buffer), file);

        char* token = strtok(buffer, ";");
        lib->films[i].title = _strdup(token);

        token = strtok(NULL, ";");
        lib->films[i].director = (Director*)malloc(sizeof(Director));
        lib->films[i].director->directorFirstName = _strdup(token);

        token = strtok(NULL, ";");
        lib->films[i].director->directorLastName = _strdup(token);

        token = strtok(NULL, ";");
        lib->films[i].country = _strdup(token);

        token = strtok(NULL, ";");
        lib->films[i].year = atoi(token);

        token = strtok(NULL, ";");
        lib->films[i].budget = atof(token);

        token = strtok(NULL, ";");
        lib->films[i].boxOffice = atof(token);
    }

    fclose(file);
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

FilmLib* printFilmsByDirector(FilmLib* lib, char* firstName, char* lastName) { 
    int count = 0, index = 0;
    int isFound = 0;
    for (int i = 0; i < lib->numFilms; i++) {
        if (strcmp(lib->films[i].director->directorFirstName, firstName) == 0 && strcmp(lib->films[i].director->directorLastName, lastName) == 0) {
            isFound = 1;

        }
    }
    if (!isFound) { 
        printf("Films not found for director: %s %s\n", firstName, lastName); 
    } 
    
    for (int i = 0; i < lib->numFilms; i++) {                      //Подсчет фильмов у режиссера
        if (strcmp(lib->films[i].director->directorFirstName, firstName) == 0 && strcmp(lib->films[i].director->directorLastName, lastName) == 0) {
            count++;
            
        }
    }

    FilmLib* director_films = (FilmLib*)malloc(sizeof(FilmLib));  //Выделение памяти под массив фильмов режиссера
        if (director_films == NULL) { 
            printf("Memory allocation failed.\n"); 
            return NULL; 
        }; 
    director_films->films = (Film*)malloc(count * sizeof(Film));
    director_films->numFilms = count; 

                                                  //Заполнение массива фильмов режиссера
    for (int i = 0; i < lib->numFilms; i++) {
        if (strcmp(lib->films[i].director->directorFirstName, firstName) == 0 &&
            strcmp(lib->films[i].director->directorLastName, lastName) == 0) {
            director_films->films[index] = lib->films[i];
            index++;
        }
        
    }

    for (int i = 0; i < director_films->numFilms; i++) {   // Вывод информации о фильмах
        printFilmInfo(&director_films->films[i]);  

    }

    return director_films; 

}


void freeFilmLibrary(FilmLib* lib) {
    for (int i = 0; i < lib->numFilms; i++) {
        free(lib->films[i].title);
        free(lib->films[i].director->directorFirstName); 
        free(lib->films[i].director->directorLastName); 
        free(lib->films[i].director);  
        free(lib->films[i].country); 
    }
    free(lib->films);
}

