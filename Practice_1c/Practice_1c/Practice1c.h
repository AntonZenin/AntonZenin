#ifndef FUNC

#define FUNC

typedef struct {
    char* directorFirstName;
    char* directorLastName;
} Director;

typedef struct {
    char* title;
    Director* director;
    char* country;
    int year;
    double budget;
    double boxOffice;
} Film;

typedef struct {
    Film* films;
    int numFilms;
} FilmLib;

FilmLib* createFilmLib(int size);
void readFilmDataFromFile(char* fileName, FilmLib* lib);
void printFilmInfo(Film* film);
void printFilmsByDirector(FilmLib* lib, char* firstName, char* lastName);
void freeFilmLibrary(FilmLib* lib);  

#endif 

