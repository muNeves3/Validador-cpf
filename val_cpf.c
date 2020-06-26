#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_cpf(char cpf_s[]){ 
	
	int x = 0, i = 0;
	
	char acpf_s[62];
	
	strcpy(acpf_s, cpf_s);
	
	while(i < strlen(acpf_s)){
	
		if(acpf_s[i] - 48 >= 0 && acpf_s[i] - 48 <= 9){	
			cpf_s[x] = acpf_s[i];
			++x;
		}
		++i;
	}
}
int digito_verificador(char v[], int x, int y){

	int v1 = 0, i;
	
	for(i = 0; i<=x; i++){
		v1 += (v[i] - 48) * (i + y);
	}
	
	v1 = (v1%11)%10;
	
	return v1;
	
}
int verificar_igualdade(char cpf_s[]){
	
	int aux = 0, i;
	
	for(i = 0; i<=11; i++){
		if((cpf_s[i]) == (cpf_s[i + 1]))
			++aux;
	}

	if(aux==11)
		return 1;
	else
		return 0;
	
}
int validador(char cpf_s[]){
	
	if(verificar_igualdade(cpf_s))
	   return 0;
   	else{
   		
	   if(digito_verificador(cpf_s, 8, 1) == cpf_s[9]-48){
		   	
		   	if(digito_verificador(cpf_s, 9, 0) == cpf_s[10]-48){
		   		
				   return 1;
			   }else{

					return 0;
			   }
	   }else{
	   	 
			return 0;
	   }
	}
}
int main(){
   
   int x=0;
   
   char cpf_s[620];
   
   printf("Digite seu CPF:\n");
   
   gets(cpf_s);
   
   if(strlen(cpf_s) < 15){
   
		if(strlen(cpf_s) > 11){
			
			limpar_cpf(cpf_s);
			x = validador(cpf_s);
	
		}else
		if(strlen(cpf_s) == 11)
			x = validador(cpf_s);
		
		else
			x = 0;
	}else
		x = 0;
	if(x)
		printf("\n-----CPF Valido!-----");
	else
		printf("\n-----CPF Invalido!-----");
	
	return 0;

}
