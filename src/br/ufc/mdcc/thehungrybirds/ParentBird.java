package br.ufc.mdcc.thehungrybirds;

import java.util.concurrent.Semaphore;

public class ParentBird extends Thread {
	
	private Food food;
	private int sleep;
	private Semaphore semaphore2;
	
	public ParentBird (Food food, int sleep, Semaphore semaphore2) {
		super();
		this.food = food;
		this.sleep = sleep;
		this.semaphore2= semaphore2;
	}
	
	@Override
	public void run() {		
		while(true) {
			try {
				semaphore2.acquire();
				this.food.refills();
			} catch (InterruptedException e1) {				
				e1.printStackTrace();
			} 			
						
			try {
				Thread.sleep(this.sleep);
			} catch (InterruptedException e) {				
				e.printStackTrace();
			}
			
		}		
		//System.out.println("Pássaro Mãe finalizou. Agora temos: " + food.getNumPortions());		
	}
}
