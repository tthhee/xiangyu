package fxy.oop.thread.status;

public class YieldDemo implements Runnable{

	@Override
	public void run() {
		for(int i = 0; i < 1000; i++)
		{
			System.out.println("JoinThread--->" + i);
		}	
	}
	
	public static void main(String[] args) throws InterruptedException
	{
		YieldDemo s = new YieldDemo();
		Thread t = new Thread(s);
		t.start();
		for(int i = 0; i< 1000; i++)
		{
			if(i >500)
			{
				//t.join(); //main×èÈû
				Thread.yield();
			}
			System.out.println("main--->" + i);
		}
	}
}
