/*
 * Autor: Maria Luiza Fernandes Prestes Cesar
 * RA: 832374
 * Data: 11/11/24
 */
#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    Student(const int ra, const string& name) {
      if (isValidRA(ra)) {
        this->ra = ra;
      } else {
        throw out_of_range("Invalid RA with value: " + std::to_string(ra) + " and name: " + name);
      }
      this-> name = name;
    }

    int getRA() const {
      return ra;
    }

    string getName() const {
      return name;
    }

    // override no cout
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
      os << "Estudante: " << student.getName() << ", RA: " << student.getRA();
      return os;
    }

  private:
    int ra;
    string name;
    static bool isValidRA(const int ra) {
      return ra >= 100000 && ra <= 999999;
    }
};

int main() {
  // Valid student, with RA within bounds
  const Student student(832374, "Luiza Prestes");
  cout << student << std::endl;

  // Invalid student, RA outside bounds
  const Student student2(231, "Giovanna Petinatti");
  cout << student2 << std::endl;

  return 0;
}
