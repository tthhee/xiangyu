package fxy.oop.thread;

public class RabbitApp {
	public static void main(String[] args)
	{
		Rabbit rab = new Rabbit();
		Tortose tor = new Tortose();
		
		rab.start();
		tor.start();
		
		for(int i = 0; i<100; i++)
		{
			System.out.println("main: " + i);
		}
	}
}
