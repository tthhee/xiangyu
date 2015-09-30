package fxy.oop.thread.status;

public class Demo01 {

	public static void main(String[] args) throws InterruptedException
	{
		Study st = new Study();
		new Thread(st).start();
		
		for(int i = 0; i < 100; i++)
		{
			if(80 == i)
			{
				st.stop();
			}
			Thread.sleep(2);
			System.out.println("main...>" + i);
		}
		
	}
}


class Study implements Runnable{

	private boolean flag = true;
	@Override
	public void run() {
		
		while(flag)
		{
			System.out.println("study thread......");
		}
	}
	
	public void stop()
	{
		this.flag = false;
	}
	
	
}