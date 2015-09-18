package fxy.oop.thread;

public class Web12306 implements Runnable{
	
	int num = 500;
	@Override
	public void run()
	{
		while(true)
		{
			if(num<=0)
			{
				break;
			}
			System.out.println(Thread.currentThread().getName() + "ÇÀµ½Æ±£º" + num--);
		}
	}
	
	public static void main(String[] args)
	{
		Web12306 web = new Web12306();
		Thread th1 = new Thread(web, "ÎÒ");
		Thread th2 = new Thread(web, "Äã");
		Thread th3 = new Thread(web, "Ëý");
		
		th1.start();
		th2.start();
		th3.start();
	}
}
