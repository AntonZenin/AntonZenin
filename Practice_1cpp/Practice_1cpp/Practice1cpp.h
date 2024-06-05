#ifndef FUNC

#define FUNC

#include <iostream>

struct director {
    std::string directorfirstname;
    std::string directorlastname;
};

struct film {
    std::string title;
    director director;
    std::string country;
    int year;
    double budget;
    double boxoffice;
};

struct filmlib {
    film* films;
    int count;
}; 

void copyfilm(film* dest, film* src);
filmlib* readfilmdatafromfile(const char* filename, filmlib* lib);
filmlib* printfilmsbydirector(filmlib* lib, director director);
void printfilmlibrary(filmlib* lib);
void printfilminfo(film* film);
void freefilmlibrary(filmlib* lib);



#endif