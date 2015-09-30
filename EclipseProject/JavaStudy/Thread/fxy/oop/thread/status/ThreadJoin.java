package fxy.oop.thread.status;

public class ThreadJoin implements Runnable{

	@Override
	public void run() {
		for(int i = 0; i < 1000; i++)
		{
			System.out.println("JoinThread--->" + i);
		}	
	}
	
	public static void main(String[] args) throws InterruptedException
	{
		ThreadJoin s = new ThreadJoin();
		Thread t = new Thread(s);
		t.start();
		for(int i = 0; i< 1000; i++)
		{
			if(i == 500)
			{
				t.join(); //main×èÈû
			}
			System.out.println("main--->" + i);
		}
	}
}

