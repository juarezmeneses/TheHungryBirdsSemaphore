int inD = 0, afterD = 0, inF = 0, afterF = 0;
constant F = 100;

{PC:inD <= afterF ^ inF <= afterD}

void process_bird[i=0 to N](){
	while(true){
		//aguardam até que a condição await - contador de entradas para consumir 
		// deve ser menor ou igual ao contador de saidas de reposições
		<await (inD < afterF) inD = inD + 1;> 
		eat();
		<afterD = afterD + 1;>						
	}
	
}

void process_parent_bird(){
	while(true){
		//aguarda até que a condição await - contador de entradas para reposição 
		// deve ser menor ou igual ao contador de saidas de consumo
		<await (inF <= afterD) inF = inF + F;> 
		refils();
		<afterF = afterF + F>
	}	
	
}