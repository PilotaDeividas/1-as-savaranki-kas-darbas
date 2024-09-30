#include <iostream>
#include <vector>
#include "Student.h"

int main() {
    std::vector<Student> studentai;
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

    std::cout << "\nPavardė        Vardas         Galutinis (Vid.)    Galutinis (Med.)\n";
    std::cout << "---------------------------------------------------------------\n";

    for (const auto& studentas : studentai) {
        std::cout << studentas << std::endl;
    }

    return 0;
}

