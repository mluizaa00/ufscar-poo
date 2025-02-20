#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal {
	public:
		Animal(const string Anome = "Animal Anonimo") {
        	this -> nome = Anome;
        };

	    string getNome() const {
	        return nome;
	    };

	    virtual void emitir_som() const = 0;

		void comer() const {
            cout << "comendo \"genericamente\"..." << endl;
        };

		virtual void andar() const {
            cout << "andando como um animal generico..." << endl;
        };

	    virtual ~Animal(){};

	private:
		string nome;
};

void Animal::emitir_som() const {
     cout << "Preparando para emitir som  e..." << endl;
};

class Cachorro : public Animal {
	public:
		Cachorro(
              string nome = "Cachorro Anonimo",
              string pedigree = "SRD"
        ) : Animal(nome) {
            this -> pedigree = pedigree;
        };

		void emitir_som() const {
             Animal::emitir_som();
             cout << "AU   AU   AU" << endl;
        };

		void comer() const {
             cout << "comendo como um cachorro" << endl;
        };

		void andar() const {
             cout << "andando como um cachorro" << endl;
        };

		void abanarRabo() const {
             cout << "abanando o rabo porque sou um cachorro e so cachorros abanam o rabo" << endl;
        };

	private:
		string pedigree;
	};

class Carneiro : public Animal {
	public:
		Carneiro(string Anome = "Carneiro Anonimo") : Animal(Anome) {};

		void emitir_som() const {
             Animal::emitir_som();
             cout << "Meeee   Meeee   Meeee" << endl;
        };
};


int main() {
      Animal *VetorAnimais[5] = {NULL};

      VetorAnimais[0] = new Cachorro("Ajudante de Papai Noel", "SRD");
      VetorAnimais[2] = new Carneiro;

      Cachorro* ptrCachorro;

      for (int i=0; i<5; i++) {
      	if (VetorAnimais[i]!= NULL) {
      		cout << endl << VetorAnimais[i] -> getNome() << endl;
      		VetorAnimais[i]->emitir_som();

      		ptrCachorro = dynamic_cast<Cachorro*>(VetorAnimais[i]);
      		if (ptrCachorro!=NULL)
      			ptrCachorro->abanarRabo();
      		else
      			cout << "N?o sou um cachorro para abanar o rabinho"<<endl;
      	}
      }
      system("pause");
      return 0;
}
