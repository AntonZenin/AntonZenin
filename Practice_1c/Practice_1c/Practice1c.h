#ifndef FUNC

#define FUNC

typedef struct {
    char* directorFirstName;
    char* directorLastName;
} Director;

typedef struct {
    char* title;
    Director director;
    char* country;
    int year;
    double budget;
    double boxOffice;
} Film;

typedef struct {
    Film* films;
    int count;
} FilmLib;


void copyfilm(Film* dest, Film* src);
FilmLib* readFilmDataFromFile(const char* filename, FilmLib* Lib);
FilmLib* printFilmsByDirector(FilmLib* Lib, Director director);
void printFilmLibrary(FilmLib* Lib);
void printFilmInfo(Film* film);
void freeFilmLibrary(FilmLib* Lib);

#endif 

