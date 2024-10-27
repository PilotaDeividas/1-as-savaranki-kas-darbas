#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

class Student {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisVidurkis;
    double galutinisMediana;

public:
  
    Student() : vardas(""), pavarde(""), egzaminas(0), galutinisVidurkis(0), galutinisMediana(0) {}
  
    Student(const Student& other)
        : vardas(other.vardas), pavarde(other.pavarde), namuDarbai(other.namuDarbai),
          egzaminas(other.egzaminas), galutinisVidurkis(other.galutinisVidurkis), galutinisMediana(other.galutinisMediana) {}

   
    Student& operator=(const Student& other) {
        if (this == &other) return *this;
        vardas = other.vardas;
        pavarde = other.pavarde;
        namuDarbai = other.namuDarbai;
        egzaminas = other.egzaminas;
        galutinisVidurkis = other.galutinisVidurkis;
        galutinisMediana = other.galutinisMediana;
        return *this;
    }
    ~Student() {}
    void ivestiDuomenis() {
        std::cout << "Įveskite studento vardą: ";
        std::cin >> vardas;
        std::cout << "Įveskite studento pavardę: ";
        std::cin >> pavarde;

        std::cout << "Įveskite namų darbų rezultatus (baigti su -1): ";
        int ivestis;
        while (true) {
            std::cin >> ivestis;
            if (ivestis == -1) break;
            namuDarbai.push_back(ivestis);
        }
        std::cout << "Įveskite egzamino rezultatą: ";
        std::cin >> egzaminas;
    }
    void skaiciuotiGalutiniVidurki() {
        double vidurkis = std::accumulate(namuDarbai.begin(), namuDarbai.end(), 0.0) / namuDarbai.size();
        galutinisVidurkis = 0.4 * vidurkis + 0.6 * egzaminas;
    }

    void skaiciuotiGalutiniMediana() {
        std::sort(namuDarbai.begin(), namuDarbai.end());
        size_t size = namuDarbai.size();
        if (size % 2 == 0) {
            galutinisMediana = (namuDarbai[size / 2 - 1] + namuDarbai[size / 2]) / 2.0;
        } else {
            galutinisMediana = namuDarbai[size / 2];
        }
        galutinisMediana = 0.4 * galutinisMediana + 0.6 * egzaminas;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& s) {
        out << std::setw(15) << std::left << s.pavarde << std::setw(15) << std::left << s.vardas
            << std::setw(20) << std::left << std::fixed << std::setprecision(2) << s.galutinisVidurkis
            << std::setw(20) << std::left << std::fixed << std::setprecision(2) << s.galutinisMediana;
        return out;
    }
};

#endif
