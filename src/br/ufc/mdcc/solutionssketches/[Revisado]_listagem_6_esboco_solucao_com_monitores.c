constant F = 100;
portions = 0; //é incrementada em F por refils() e decrementada em 1 por eat()

void process_bird[i=0 to N](){
	while(true){		
		eat();		
	}
}

void process_parent_bird(){
	while(true){		
		refils();		
	}		
}

void monitor_food(){
	
	cond full, empty;
	int portions = 0
	
	procedure eat() {		
		while(portions == 0){
			signal(empty);
			await(full);
		} 
		if(portions > 0)
			portions--;
			signal(full);
		}
	}

	procedure refils() {
		await(empty);
		portions=F;
		signal_all(full);	
	}		
}
