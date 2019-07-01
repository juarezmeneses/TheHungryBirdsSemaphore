constant F = 100;

int contConsumoPassarosFilhos = 0;
int contReposicaoAveMae = 0;

{CS: contReposicaoAveMae - contConsumoPassarosFilhos <= F}
void process_bird[i=0 to N](){
	while(true){
	
		{contReposicaoAveMae - contConsumoPassarosFilhos == 0 <= F}//Fº consumo
		//aguardam enquanto a diferença entre o contador dos passaros filhos e da ave mãe for igual a 0
		while(contReposicaoAveMae - contConsumoPassarosFilhos == 0){skip;}
		
		//se a diferença entre o contador dos passaros filhos e da ave mãe for maior que 0, quer dizer que o passaro pode comer
		<if(contReposicaoAveMae - contConsumoPassarosFilhos > 0)
			eat();
			{contReposicaoAveMae - contConsumoPassarosFilhos == 100 <= F}//1º consumo
			contConsumoPassarosFilhos++;
			{contReposicaoAveMae - contConsumoPassarosFilhos == 99 <= F}//1º consumo
		}>
	}

}

{CS: contReposicaoAveMae - contConsumoPassarosFilhos <= F}
void process_parent_bird(){
	while(true){
	
		{contReposicaoAveMae - contConsumoPassarosFilhos == 100 <= F}//2ª reposição (acabou de fazer a 1ªreposição)
		//aguarda enquanto a diferença entre o contador dos passaros filhos e da ave mãe for maior que 0
		while(contReposicaoAveMae - contConsumoPassarosFilhos > 0){skip;}
		
		//quando o contador dos passaros filhos for igual ao contador de reposição quer dizer que a ave mae pode repor F porções
		refils();
		
		{contReposicaoAveMae - contConsumoPassarosFilhos == 0 <= F}//1ª reposição
		contReposicaoAveMae = contReposicaoAveMae + F;
		{contReposicaoAveMae - contConsumoPassarosFilhos == 100 <= F}//1ª reposição
	}	
	
}