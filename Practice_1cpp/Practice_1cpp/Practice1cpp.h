#ifndef FUNC

#define FUNC

#include <string>

struct Director {
    std::string directorfirstname;
    std::string directorlastname;
};

struct Film {
    std::string title;
    Director* director;
    std::string country;
    int year;
    double budget;
    double boxOffice;
};

struct FilmLib {
    Film* films;
    int count;
};

FilmLib* readFilmDataFromFile(const char* filename, FilmLib* Lib);
void printFilmsByDirector(FilmLib* Lib, std::string firstname, std::string lastname);
void printFilmInfo(Film* film);
void freefilmlibrary(FilmLib* Lib);

#endif