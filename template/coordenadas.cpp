#include <iostream>

using namespace std;

template <class T>
class Coordenadas {
	private:
		T x;
    	T y;
	public:
		Coordenadas(const T coord_x, const T coord_y) {
			this -> x = coord_x;
			this -> y = coord_y;
		}
		void Set(const T x, const T y) {
			this -> x = x;
			this -> y = y;
		}
		void Get(const T &x, T &y) const {
			x = this -> x;
			y = this -> y;
		}
		T GetX(void) const {
			return(x);
		}
		T GetY(void) const {
			return(y);
		}
};


int main(int argc, char *argv[]) {
	int    X = 10, Y = 20;
	double Z = 11.1, W = 22.2;

	Coordenadas<int>    Posicao_inteira = Coordenadas<int>(X,Y);
	Coordenadas<double> Posicao_precisa(Z,W);

	cout << Posicao_inteira.GetX() << " " << Posicao_inteira.GetY() << endl;
	cout << Posicao_precisa.GetX() << " " << Posicao_precisa.GetY() << endl;

	system("pause");
	return 0;
}
