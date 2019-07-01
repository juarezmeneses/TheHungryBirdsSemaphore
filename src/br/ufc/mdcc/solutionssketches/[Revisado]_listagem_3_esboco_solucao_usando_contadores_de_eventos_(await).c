constant F = 100;

int contConsumoPassarosFilhos = 0;
int contReposicaoAveMae = 0;

void process_bird[i=0 to N](){
	while(true){
		//aguardam até que a condição await - diferença entre contReposicaoAveMae e contConsumoPassarosFilhos for maior que 0
		<await (contReposicaoAveMae - contConsumoPassarosFilhos > 0) 
			eat();
			contConsumoPassarosFilhos++;>						
	}

}

void process_parent_bird(){
	while(true){
		//aguarda até que a condição await - diferença entre contReposicaoAveMae e contConsumoPassarosFilhos for igual a 0
		<await (contReposicaoAveMae - contConsumoPassarosFilhos == 0) 
			refils();
			contReposicaoAveMae = contReposicaoAveMae + F;>
	}	
	
}
