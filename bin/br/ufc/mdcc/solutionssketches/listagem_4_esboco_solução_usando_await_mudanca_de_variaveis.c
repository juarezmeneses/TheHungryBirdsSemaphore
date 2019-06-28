int inD = 0, afterD = 0, inF = 0, afterF = 0;
constant F = 100;

{PC:inD <= afterF ^ inF <= afterD}

void process_bird[i=0 to N](){
	while(true){
		//aguardam até que a condição await - somatorio dos contadores dos passaros filhos for menor que o contador de reposicao da ave mãe
		<await (inD <= afterF) inD = inD + 1;> 
		eat();
		<afterD = afterD + 1;>						
	}
	
}

void process_parent_bird(){
	while(true){
		//aguarda até que a condição await - somatório dos contadores dos passaros filhos for igual o contador de reposição da ave mãe
		<await (inF <= afterD) inF = inF + 1;> 
		refils();
		<afterF = afterF + 1>
	}	
	
}