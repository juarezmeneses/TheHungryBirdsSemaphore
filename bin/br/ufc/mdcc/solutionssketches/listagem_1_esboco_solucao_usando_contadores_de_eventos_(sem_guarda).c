constant F = 100;

int contConsumoPassaroFilho[i=0 to N] = 0;
int contReposicaoAveMae = 0;

void process_bird[i=0 to N](){
	while(true){
		//aguardam enquanto o somatorio dos contadores dos passaros filhos for igual ao contador de reposicao da ave mãe
		while(contConsumoPassaroFilho[0] + contConsumoPassaroFilho[1] + ... contConsumoPassaroFilho[N] == contReposicaoAveMae){skip;}
		
		//se o somatorio dos contadores dos passaros filhos for menor que o contador de reposição da ave mãe quer dizer que o passaro pode comer
		<if(contConsumoPassaroFilho[0] + contConsumoPassaroFilho[1] + ... contConsumoPassaroFilho[N] < contReposicaoAveMae)
			eat();
			contConsumoPassaroFilho[i]++;
		}>
	}

}

void process_parent_bird(){
	while(true){
		//aguarda enquanto o somatório dos contadores dos passaros filhos for menor que o contador de reposição da ave mãe
		while(contConsumoPassaroFilho[0] + contConsumoPassaroFilho[1] + ... contConsumoPassaroFilho[N] < contReposicaoAveMae){skip;}
		
		//quando o somatorio dos contadores dos passaros filhos for igual ao contador de reposição quer dizer que a ave mae pode repor F porções
		refils();
		contReposicaoAveMae = contReposicaoAveMae + F;
	}	
	
}


