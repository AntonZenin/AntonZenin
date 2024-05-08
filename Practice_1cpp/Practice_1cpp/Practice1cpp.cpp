#include <iostream>
#include <fstream>
#include <string>
#include "Practice1cpp.h"

#define l 255

FilmLib* readFilmDataFromFile(char* filename, FilmLib* lib) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "error opening file." << std::endl;
        exit(1);
    }

    file >> lib->count;
    lib->films = new Film[lib->count]; 

    for (int i = 0; i < lib->count; i++) {
        char buffer[l];
        file.getline(buffer, sizeof(buffer));

        char* token = strtok(buffer, ";");
        lib->films[i].title = _strdup(token);

        token = strtok(nullptr, ";");
        lib->films[i].director = new Director;
        lib->films[i].director->directorfirstname = _strdup(token);

        token = strtok(nullptr, ";");
        lib->films[i].director->directorlastname = _strdup(token);

        token = strtok(nullptr, ";");
        lib->films[i].country = _strdup(token);

        token = strtok(nullptr, ";");
        lib->films[i].year = atoi(token);

        token = strtok(nullptr, ";");
        lib->films[i].budget = atof(token);

        token = strtok(nullptr, ";");
        lib->films[i].boxOffice = atof(token); 
    }

    file.close();
}

void printFilmsByDirector(FilmLib* Lib, char* firstname, char* lastname) {
    int isfound = 0;
    for (int i = 0; i < Lib->count; i++) {
        if (strcmp(Lib->films[i].director->directorfirstname, firstname) == 0 && strcmp(Lib->films[i].director->directorlastname, lastname) == 0) {
            isfound = 1;
            printFilmInfo(&Lib->films[i]); 
        }
    }
    if (!isfound) {
        std::cout << "films not found for director: " << firstname << " " << lastname << std::endl;
    }
}

void printFilmInfo(Film* film) {   
    std::cout << "title: " << film->title << std::endl;
    std::cout << "director: " << film->director->directorfirstname << " " << film->director->directorlastname << std::endl;
    std::cout << "country: " << film->country << std::endl;
    std::cout << "year: " << film->year << std::endl;
    std::cout << "budget: " << std::fixed << std::setprecision(2) << film->budget << std::endl;
    std::cout << "box office: " << std::fixed << std::setprecision(2) << film->boxoffice << std::endl;
    std::cout << std::endl;
}

void freefilmlibrary(FilmLib* Lib) {
    for (int i = 0; i < Lib->count; i++) {
        free(Lib->films[i].title); 
        free(Lib->films[i].director->directorfirstname); 
        free(Lib->films[i].director->directorlastname); 
        free(Lib->films[i].director); 
        free(Lib->films[i].country); 
    }
    delete[] Lib->films; 
}