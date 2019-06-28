constant F = 100;
portions = 0; //é incrementada em F por refils() e decrementada em 1 por eat()

sem empty = 1;
sem full = 0;

void process_bird[i=0 to N](){
	while(true){
		//aguardam permissões que são concedidas pelo processo parent_bird após realizar a reposição
		P(full); 
		eat();
		if(portions == 0){
			V(empty);
		}
		V(full);
	}

}

void process_parent_bird(){
	while(true){
		//aguarda até que algum processo bird[] conceda permissão ao semaforo empty alertando 
		//a ave mãe que estão sem comida no ninho
		P(empty)
		refils();
		V(full);
	}	
	
}