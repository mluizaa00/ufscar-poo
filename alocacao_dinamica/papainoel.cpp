#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Pedido {

public:
   Pedido(string vnome = "Anonimo", int vnmroItens = 0);
   ~Pedido();
   void setNome(string vnome);
   bool setItem(int pos, string val);
   int getID() const;
   string getNome() const;
   int getNmroItens() const;
   bool getItem(int pos, string& val) const;

   static int getTotalPedidos();
   static int getTotalItens();

   void imprime() const;

private:
   const int ID;
   string nome;
   int nmroItens;
   string *ptrItens;
   static int contPedidos;
   static int contItens;
   static int proxPedido;
};

int Pedido::contPedidos = 0;
int Pedido::proxPedido = 0;

int Pedido::contItens = 0;

int Pedido::getTotalPedidos(){
	return contPedidos;
}

int Pedido::getTotalItens(){
	return contItens;
}

int Pedido::getID() const{
	return ID;
}


string Pedido::getNome() const{
	return nome;
}

Pedido::~Pedido(){
   contPedidos--;
   contItens = contItens - getNmroItens();
   if (getNmroItens()>0)
   		delete [] ptrItens;
}

Pedido::Pedido(string vnome, int vnmroItens):ID(++proxPedido){
   setNome(vnome);
   if (vnmroItens > 0){
     nmroItens = vnmroItens;
   	 ptrItens = new string[nmroItens];
   }
   else{
     nmroItens = 0;
     ptrItens = NULL;
   }
	++contPedidos;
	contItens = contItens + nmroItens;
}

int Pedido::getNmroItens() const{
    return nmroItens;
}

bool Pedido::setItem(int pos, string val){
   if (pos >=0 && pos < nmroItens)
      {
      ptrItens[pos] = val;
      return true;
      }
   else
      return false;
}

bool Pedido::getItem(int pos, string& val) const
{
    if (pos >= 0 && pos < nmroItens){
         val = ptrItens[pos];
		 return true;
     }
    else
        return false;
}

void Pedido::setNome(string vnome){
	nome = vnome;

}

void Pedido::imprime() const
{
     string item;
	 cout << "Pedido #" << getID()<< " Nome: " << getNome()<<endl;
     if(getNmroItens()>0){
	 	cout<< "     Itens: ";
	 	for (int i=0;i<getNmroItens();i++)
        	if(getItem(i,item))
        		cout << item<< " ";
     	cout << endl;
     }
}


int main(){
	cout<< "Total de pedidos: " << Pedido::getTotalPedidos() << endl;
	cout<< "Total de itens  : " << Pedido::getTotalItens()<<endl;

	cout << "criando pedido de Francisco" << endl;
	Pedido a1("Francisco", 3);

	if(a1.setItem(0,"bicicleta"))
		cout << "1o Item definido como bicicleta"<< endl;
	else
		cout <<  "nao foi possivel definir 1o Item" << endl;

	if(a1.setItem(1,"carrinho"))
		cout << "2o Item definido como carrinho"<< endl;
	else
		cout <<  "nao foi possivel definir 2o Item"<< endl;

	if(a1.setItem(2,"cachorro"))
		cout << "3o Item definida como cachorro"<< endl;
	else
		cout <<  "nao foi possivel definir 3o Item"<< endl;

	if(a1.setItem(3,"celular"))
		cout << "4o Item definida como celular"<< endl;
	else
		cout <<  "nao foi possivel definir 4o Item"<< endl;


	a1.imprime();
	cout<< "Total de pedidos: " << Pedido::getTotalPedidos() << endl;
	cout<< "Total de itens  : " << Pedido::getTotalItens()<<endl;


	cout << "criando pedido de Maria" << endl;
	Pedido a2 ("Maria", 1);
	if(a2.setItem(0,"patins"))
		cout << "1o Item definido como patins"<< endl;
	else
		cout <<  "nao foi possivel definir 1o Item" << endl;


	a2.imprime();
	cout<< "Total de pedidos: " << Pedido::getTotalPedidos() << endl;
	cout<< "Total de itens  : " << Pedido::getTotalItens()<<endl;
}
