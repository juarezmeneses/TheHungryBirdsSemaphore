package br.ufc.mdcc.thehungrybirds;

import java.util.concurrent.Semaphore;

public class Bird extends Thread {
		
	private int id;
	private Food food;
	private int sleep;
	private Semaphore semaphore;
	private Semaphore semaphore2;
		
	
	public Bird (int id, Food food, int sleep, Semaphore semaphore, Semaphore semaphore2) {
		super();
		this.id=id;
		this.food = food;
		this.sleep = sleep;
		this.semaphore=semaphore;
		this.semaphore2=semaphore2;
	}
			
	
	@Override
	public void run() {		
		while(true) {
			try {
				semaphore.acquire();
				this.food.eat(id, semaphore2);
								
			} catch (InterruptedException e1) {				
				e1.printStackTrace();
			} finally {
				semaphore.release();
			}
				
			try {
				Thread.sleep(this.sleep);
			} catch (InterruptedException e) {				
				e.printStackTrace();
			}
		
	}	
	//System.out.println("O Passaro "+id+" finalizou. Ainda resta: " + food.getNumPortions());		
	}
	

}
