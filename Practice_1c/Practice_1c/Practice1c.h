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
    int count;
} FilmLib;



FilmLib* readFilmDataFromFile(const char* filename, FilmLib* Lib);
FilmLib* printFilmsByDirector(FilmLib* Lib, char* firstName, char* lastName); 
void printFilmInfo(Film* film);
void freeFilmLibrary(FilmLib* Lib);  

#endif 

