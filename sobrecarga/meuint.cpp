#include <iostream>
using namespace std;

class MeuInt{
	private:
		int numero;
    public:
        MeuInt(int numero=0);

        void setNumero(int numero);
        int getNumero() const;

        // pre
    	MeuInt& operator++();
        // pos
    	const MeuInt operator++(int);
		MeuInt& operator--();
    	const MeuInt operator--(int);

        const MeuInt operator+(const MeuInt& o2) const;
		bool operator>(const MeuInt& o2) const;

    	const MeuInt operator+(int o2) const;
		bool operator>(int o2) const;

        friend const MeuInt operator+(int o1, const MeuInt& o2);
		friend bool operator>(int o1, const MeuInt& o2);

		friend ostream &operator<<(ostream &saida, const MeuInt &num);
        friend istream &operator>>(istream &entrada, MeuInt &num);
};

MeuInt::MeuInt(int numero){
	setNumero(numero);
}

void MeuInt::setNumero(int numero) {
    this -> numero = numero;
}

int MeuInt::getNumero() const {
    return this -> numero;
}

//================================Operadores membros da classe===============
//Un�rios
MeuInt& MeuInt::operator++(){	//pr�
	++numero;
	return (*this);
}

const MeuInt MeuInt::operator++(int){ 	//p�s
	MeuInt copia(*this);
	++numero;
	return copia;
}

MeuInt& MeuInt::operator--(){	//pr�
	--numero;
	return (*this);
}

const MeuInt MeuInt::operator--(int){ 	//p�s
	MeuInt copia(*this);
	--numero;
	return copia;
}

const MeuInt MeuInt::operator+(const MeuInt& o2) const {
      return MeuInt(numero + o2.numero);
}

bool MeuInt::operator>(const MeuInt& o2) const {
    if (numero > o2.numero)
        return true;
    else
        return false;
}

const MeuInt MeuInt::operator+(int o2) const{
	return MeuInt(this->numero + o2);
}

bool MeuInt::operator>(int o2) const{
    if (numero > o2)
        return true;
    else
        return false;
}


//================================Operadores N?O membros da classe (friend)====

const MeuInt operator+(int o1, const MeuInt& o2){
      return MeuInt(o1 + o2.numero);
}

bool operator>(int o1, const MeuInt& o2){
    if (o1 > o2.numero)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &saida, const MeuInt &num){
        saida << num.numero;
        return saida;
}

istream &operator>>(istream &entrada, MeuInt &num){
        entrada >> num.numero;
        return entrada;
}



