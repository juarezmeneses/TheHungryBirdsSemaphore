constant F = 100;

int contConsumoPassarosFilhos = 0;
int contReposicaoAveMae = 0;

void process_bird[i=0 to N](){
	while(true){				
		//se o contador dos passaros filhos for menor que o contador de reposição
		// quer dizer que o passaro pode comer
		<if(contConsumoPassarosFilhos < contReposicaoAveMae)
			eat();
			contConsumoPassarosFilhos++;>
	}

}

void process_parent_bird(){
	while(true){		
		//quando o contador dos passaros filhos for igual ao contador de reposição
		// quer dizer que a ave mae pode repor F porções
		<if(contConsumoPassarosFilhos == contReposicaoAveMae)
			refils();
			contReposicaoAveMae = contReposicaoAveMae + F;>
	}	
	
}
