#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Practice1cpp.h"

#define l 255


filmlib* readfilmdatafromfile(char* filename, filmlib* lib) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "error opening file." << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(file, line);
    lib->count = std::stoi(line);
    lib->films = new film[lib->count];

    for (int i = 0; i < lib->count; i++) {
        std::string buffer;
        std::getline(file, buffer);

        std::string::size_type pos = 0;
        std::string token = buffer.substr(0, buffer.find(';'));
        lib->films[i].title = token;

        pos = buffer.find(';', pos) + 1;
        token = buffer.substr(pos, buffer.find(';', pos) - pos);
        lib->films[i].director.directorfirstname = token;

        pos = buffer.find(';', pos) + 1;
        token = buffer.substr(pos, buffer.find(';', pos) - pos);
        lib->films[i].director.directorlastname = token;

        pos = buffer.find(';', pos) + 1;
        token = buffer.substr(pos, buffer.find(';', pos) - pos);
        lib->films[i].country = token;

        pos = buffer.find(';', pos) + 1;
        token = buffer.substr(pos, buffer.find(';', pos) - pos);
        lib->films[i].year = std::atoi(token.c_str());

        pos = buffer.find(';', pos) + 1;
        token = buffer.substr(pos, buffer.find(';', pos) - pos);
        lib->films[i].budget = std::atof(token.c_str());

        pos = buffer.find(';', pos) + 1;
        token = buffer.substr(pos, buffer.find(';', pos) - pos);
        lib->films[i].boxoffice = std::atof(token.c_str());
    }

    file.close();
    return lib;
} 

filmlib* printfilmsbydirector(filmlib* lib, director director) {
    int count = 0;
    for (int i = 0; i < lib->count; i++) {
        if (lib->films[i].director.directorfirstname == director.directorfirstname && lib->films[i].director.directorlastname == director.directorlastname) {
            count++;
        }
    }

    if (count == 0) {
        std::cout << "\nfilms not found for director: " << director.directorfirstname << " " << director.directorlastname << "\n";
        return nullptr;
    }

    filmlib* newlib = new filmlib;
    newlib->films = new film[count];
    newlib->count = count;

    int index = 0;
    for (int i = 0; i < lib->count; i++) {
        if (lib->films[i].director.directorfirstname == director.directorfirstname && lib->films[i].director.directorlastname == director.directorlastname) {
            copyfilm(&newlib->films[index], &lib->films[i]);
            index++;
        }
    }

    return newlib;
}

void printfilmlibrary(filmlib* lib) {
    for (int i = 0; i < lib->count; i++) {
        printfilminfo(&lib->films[i]);
    }
}

void printfilminfo(film* film) {
    std::cout << "\nTitle: " << film->title << "\n";
    std::cout << "Director: " << film->director.directorfirstname << " " << film->director.directorlastname << "\n";
    std::cout << "Country: " << film->country << "\n";
    std::cout << "Year: " << film->year << "\n";
    std::cout << "Budget: " << std::fixed << std::setprecision(2) << film->budget << "\n";
    std::cout << "Box Office: " << std::fixed << std::setprecision(2) << film->boxoffice << "\n";
    std::cout << "\n";
}

void copyfilm(film* dest, film* src) {
    dest->title = src->title;
    dest->director.directorfirstname = src->director.directorfirstname;
    dest->director.directorlastname = src->director.directorlastname;
    dest->country = src->country;
    dest->year = src->year;
    dest->budget = src->budget;
    dest->boxoffice = src->boxoffice;
}

void freefilmlibrary(filmlib* lib) {
    for (int i = 0; i < lib->count; i++) {
        lib->films[i].title.clear();
        lib->films[i].director.directorfirstname.clear();
        lib->films[i].director.directorlastname.clear();
        lib->films[i].country.clear();
    }
    delete[] lib->films;
    lib->films = nullptr;
}