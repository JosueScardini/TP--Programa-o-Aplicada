#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;
struct tCircuito {
  int Res1;
  int Res2;
  int Vt1;
  tCircuito* proximo;
};

tCircuito* criaNo (int R1, int R2,int V1) {
  tCircuito* no = new tCircuito;
  no -> Res1 = R1;
  no -> Res2 = R2;
  no -> Vt1 = V1;
  no -> proximo = NULL;


  return no;

};

struct tLista {
  tCircuito* primeiro;
  tCircuito* ultimo;
  tCircuito* marcador;
  int tamanho;

};
void inicializaLista(tLista* pLista){
  pLista -> primeiro = NULL;
  pLista -> ultimo = NULL;
  pLista -> marcador = NULL;
  pLista -> tamanho = 0;
}

int obterTamanho (tLista* pLista){
  return pLista -> tamanho;
}

bool finalizaLista (tLista* pLista) {
    return pLista -> marcador == NULL;
    }

bool listaVazia (tLista* pLista){
  return pLista -> tamanho == 0;
}
bool finalLista (tLista* pLista){
  return (pLista -> marcador == NULL);
}

void incluirNoFim (tLista* pLista, int R1, int R2, int V1){
  tCircuito* no;
  no = criaNo(R1, R2, V1);

  if (listaVazia(pLista)){
    pLista -> primeiro = no;
  }else{
  pLista -> ultimo -> proximo = no;
  }

  pLista -> ultimo = no;
  pLista -> marcador = no;
  pLista -> tamanho ++;
  }

 void imprimirLista(tLista* pLista){
   pLista -> marcador = pLista -> primeiro;

   while (!finalLista(pLista)){
    int informacao = pLista -> marcador->Res1;
    cout<< "A informação é: "<<informacao<<endl;
    pLista -> marcador = pLista -> marcador -> proximo;
   }
 }
int main() {

setlocale(LC_ALL, "Portuguese");

ofstream parte1;
ifstream parte2;
string resposta;
int numero = 0, R1,R2, V1;

tCircuito circuito1;
tLista* pLista;

cout<<"Digite 1 para gravar ou 2 para ler um banco de dados"<<endl;
cin>>resposta;

if (resposta == "2"){

}else{

cout<<"Digite o numero de elementos que deseja armazenar"<<endl;
cin>>numero;

tLista* circuito2 = new tLista;
inicializaLista(circuito2);


for (int i = 0; i < numero; i++){
   cout<<"Informe o valor de R1"<<endl;
  cin>> circuito1.Res1;

  cout<< "-------------------------"<<endl;

  cout<<"Informe o valor de R2"<<endl;
  cin>>circuito1.Res2;

  cout<< "-------------------------"<<endl;

  cout<<"Informe o valor de V1"<<endl;
  cin>>circuito1.Vt1;

  incluirNoFim(circuito2, circuito1.Res1, circuito1.Res2, circuito1.Vt1);
}
}

parte1.open("Arquivo.txt",ios::out);
parte1<<R1<< endl;
parte1<<R2<< endl;
parte1<<V1<< endl;

pLista -> marcador = pLista -> primeiro;

while (!finalizaLista(pLista)) {
int R1 = pLista ->marcador ->Res1;
int R2 = pLista ->marcador ->Res2;
int V1= pLista ->marcador ->Vt1;

pLista -> marcador = pLista -> marcador -> proximo;
}
}