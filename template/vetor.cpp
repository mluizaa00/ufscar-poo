#include <iostream>

class MinhaClasse {
	public:
		MinhaClasse(const int a = 5, char b = 'a'){
			this -> A = a;
			this -> B = b;
		}
	private:
		int A;
		char B;

	friend std::ostream & operator<<(std::ostream & saida, const MinhaClasse & obj){
		saida << "(" << obj.A << "," << obj.B << ")";
		return saida;
	}
};

template <typename T>
class vetor {

public:
   vetor(int=10);
   ~vetor();
   int get_tamanho() const;
	bool SetValor(int pos, T val) {
		if (pos >=0 && pos < tam) {
			ptrvalores[pos] = val;
			return true;
		} else {
			return false;
		}
	}
   bool GetValor(int pos, T& val) const;
   void imprime() const;

private:
   int tam;
   T *ptrvalores;


};

template <typename T>
vetor<T>::vetor(int tamanho) {
   if (tamanho > 0)
     tam = tamanho;
   else
     tam = 10;

   ptrvalores = new T[tam]();
}

template <typename T>
vetor<T>::~vetor() {
   delete [] ptrvalores;
}

template <typename T>
int vetor<T>::get_tamanho() const {
    return tam;
}

template <typename T>
bool vetor<T>::GetValor(int pos, T& val) const {
    if (pos >= 0 && pos < tam) {
        val = ptrvalores[pos];
        return true;
    } else {
    	return false;
    }
}

template <typename T>
void vetor<T>::imprime() const
{
     T valor;
     for (int i=0;i<get_tamanho();i++){
        GetValor(i, valor);
        std::cout << valor << " ";
        }
     std::cout << std::endl;
}


int main() {
	vetor<int> Par = vetor<int>(10);
	vetor<double> Impar = vetor<double>();

    std::cout << "Vetor Par" << std::endl;
    Par.imprime();

	std::cout << "Vetor Impar"<<std::endl;
    Impar.imprime();

	vetor<MinhaClasse> vetClasse = vetor<MinhaClasse>(10);
    std::cout << "Vetor vetClasse"<<std::endl;
    vetClasse.imprime();

    return 0;
}
