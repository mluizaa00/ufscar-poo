/*
 * Autor: Maria Luiza Fernandes Prestes Cesar
 * RA: 832374
 * Data: 11/11/24
 */
#include <iostream>
#include <string>

using namespace std;

class Figura {
  private:
    int x;
    int y;
  public:
    Figura(int x = 0, int y = 0) : x(x), y(y) {}

    void SetPosicao(const int x, const int y) {
      this -> x = x;
      this -> y = y;
    }

    int getX() const {
      return x;
    }

    int getY() const {
      return y;
    }
};

class Quadrado : public Figura {
  private:
    int lado;
  public:
    Quadrado(const int x = 0, const int y = 0) {
      this -> x = x;
      this -> y = y;
    }

    int getX() const {
      return x;
    }

    int getY() const {
      return y;
    }
};

int main() {
  const NumeroComplexo c1 = NumeroComplexo(1, 2, 3);
  return 0;
}
