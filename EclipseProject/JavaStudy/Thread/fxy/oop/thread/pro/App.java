package fxy.oop.thread.pro;

public class App {
	public static void main(String[] args)
	{
		Movie m = new Movie();
		Player p = new Player(m);
		Watch w = new Watch(m);
		
		new Thread(p).start();
		new Thread(w).start();
	}


}
