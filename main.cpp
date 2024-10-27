#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"

void skaitytiIsFailo(const std::string& failoVardas, std::vector<Student>& studentai) {
    std::ifstream inFile(failoVardas);
    if (!inFile) {
        throw std::runtime_error("Nepavyko atidaryti failo");
    }

    std::string vardas, pavarde;
    int egzaminas;
    while (inFile >> vardas >> pavarde >> egzaminas) {
        Student s;
        s.generuotiAtsitiktiniusDuomenis();  // Generuojami duomenys
        s.skaiciuotiGalutiniVidurki();
        s.skaiciuotiGalutiniMediana();
        studentai.push_back(s);
    }
    inFile.close();
}

int main() {
    std::vector<Student> studentai;
    int pasirinkimas;

    std::cout << "Pasirinkite duomenų įvedimą (1 - rankiniu būdu, 2 - generuoti atsitiktinai, 3 - skaityti iš failo): ";
    std::cin >> pasirinkimas;

    if (pasirinkimas == 1) {
        int n;
        std::cout << "Įveskite studentų skaičių: ";
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            Student s;
            s.ivestiDuomenis();
            s.skaiciuotiGalutiniVidurki();
            s.skaiciuotiGalutiniMediana();
            studentai.push_back(s);
        }
    } else if (pasirinkimas == 2) {
        int n;
        std::cout << "Įveskite atsitiktinių studentų skaičių: ";
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            Student s;
            s.generuotiAtsitiktiniusDuomenis();
            s.skaiciuotiGalutiniVidurki();
            s.skaiciuotiGalutiniMediana();
            studentai.push_back(s);
        }
    } else if (pasirinkimas == 3) {
        try {
            skaitytiIsFailo("kursiokai.txt", studentai);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }

    std::cout << "\nPavardė        Vardas         Galutinis (Vid.)    Galutinis (Med.)\n";
    std::cout << "---------------------------------------------------------------\n";
    for (const auto& studentas : studentai) {
        std::cout << studentas << std::endl;
    }

    return 0;
}
