constant F = 100;

int contConsumoPassaroFilho[i=0 to N] = 0;
int contReposicaoAveMae = 0;

void process_bird[i=0 to N](){
	while(true){
		//aguardam até que a condição await - somatorio dos contadores dos passaros filhos for menor que o contador de reposicao da ave mãe
		<await (contConsumoPassaroFilho[0] + contConsumoPassaroFilho[1] + ... contConsumoPassaroFilho[N] < contReposicaoAveMae) 
			eat();
			contConsumoPassaroFilho[i]++;>						
	}

}

void process_parent_bird(){
	while(true){
		//aguarda até que a condição await - somatório dos contadores dos passaros filhos for igual o contador de reposição da ave mãe
		<await (contConsumoPassaroFilho[0] + contConsumoPassaroFilho[1] + ... contConsumoPassaroFilho[N] == contReposicaoAveMae) 
			refils();
			contReposicaoAveMae = contReposicaoAveMae + F;>
	}	
	
}
