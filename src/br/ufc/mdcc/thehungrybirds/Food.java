package br.ufc.mdcc.thehungrybirds;

import java.util.concurrent.Semaphore;

public class Food {
	
	private int portions = 0;
	private final int maxPortions = 100;
	
	public int getNumPortions(){
		return portions;
		
	}
	
	public boolean eat(int id, Semaphore semaphore2) {
				
		while(portions==0) {
			try {
				System.out.println("P�ssaro "+id+" Acordou o P�ssaro M�e, portions: "+portions);
				semaphore2.release();				
				Thread.sleep(200);
			} catch (InterruptedException e) {				
				e.printStackTrace();
			}
		}
		
		portions=getNumPortions() - 1;
		System.out.println("P�ssaro "+id+" Comeu 1 Por��o, portions: "+portions);
		//notifyAll();
		return true;
	}

	public boolean refills() {		
		portions=maxPortions; 
		System.out.println("P�ssaro M�e Trouxe +100 Por��es, portions: "+portions);
		return true;
	}

	public static void main(String[] args) {
		int numBirds = 5;
		
		Food food = new Food();
		Semaphore semaphore = new Semaphore(1);
		Semaphore semaphore2 = new Semaphore(0);
		ParentBird p = new ParentBird(food, 200, semaphore2);
		
		/*// Setup for 5 Birds
		Bird c1 = new Bird(1, food, 200, semaphore, semaphore2);
		Bird c2 = new Bird(2, food, 200, semaphore, semaphore2);
		Bird c3 = new Bird(3, food, 200, semaphore, semaphore2);
		Bird c4 = new Bird(4, food, 200, semaphore, semaphore2);
		Bird c5 = new Bird(5, food, 200, semaphore, semaphore2);

		//Start Birds and Bird Parent
		//...
		p.start();
		c1.start();
		c2.start();
		c3.start();
		c4.start();
		c5.start();*/
		
		// Start Bird Parent
		p.start();
		
		// Setup for N Birds
		Bird[] birds = new Bird[numBirds+1];
	    for (int i = 1; i <= numBirds; i++) {
	        birds[i] = new Bird(i, food, 200, semaphore, semaphore2);
	        birds[i].start();
	    }
				
		
		System.out.println("Execucao da main da classe Food terminada");
		}

}
