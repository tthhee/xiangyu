package fxy.oop.thread.pro;

public class Player implements Runnable{
	private Movie m;
	
	public Player(Movie m) {
		super();
		this.m = m;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0; i< 20; i++)
		{
			if(0==i%2)
			{
				m.player("×óÇàÁú");
			}
			else
			{
				m.player("ÓÒ°×»¢");
			}
		}
	}
	

}
