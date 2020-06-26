#include <iostream>
#include <string.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Validador{
	private:
		char cpf[62];
		
		void limpa();
		int digitoVerificador(int x, int y);
		bool verificarIgualdade();
	public:
		//bool validar(char cpf[]);
		//char[] gerar();
		Validador(char cpf[]);
		bool validar();
};

Validador::Validador(char cpf[]){
	strcpy(this->cpf, cpf);
}

void Validador::limpa(){
	
	int x = 0, i = 0;
	
	char acpfS[62];
	
	strcpy(acpfS, cpf);
	
	while(i < strlen(acpfS)){
		if(acpfS[i] - 48 >= 0 && acpfS[i] - 48 <= 9){	
			cpf[x] = acpfS[i];
			++x;
		}
		++i;
	}
}

int Validador::digitoVerificador(int x, int y){

	int v1 = 0, i;
	
	for(i = 0; i<=x; i++){
		v1 += (cpf[i] - 48) * (i + y);
	}
	
	return (v1%11)%10;
}

bool Validador::verificarIgualdade(){

	int aux = 0, i;
	
	for(i = 0; i<10; i++){
		aux = (cpf[i] == cpf[i + 1]) ? ++aux : aux;
	}
		
	return (aux==10) ? false : true;
}

bool Validador::validar(){
	
	limpa();
	
	return (strlen(cpf) < 15 && 
			verificarIgualdade() && 
			digitoVerificador(8, 1) == cpf[9]-48 && 
			digitoVerificador(9, 0) == cpf[10]-48) ? true : false;
	
}

int main(int argc, char** argv) {
	char cpfStr[620];
   
	cout<<"Digite seu CPF:\n";
   
	cin>>cpfStr;
	Validador v(cpfStr);
	
	if(v.validar())
		printf("\n-----CPF Valido!-----");
	else
		printf("\n-----CPF Invalido!-----");
	

	return 0;
}
