package fxy.oop.thread.syn;

public class SynDemo01 {
	public static void main(String[] args)
	{
		Web12306 web = new Web12306();
		Thread th1 = new Thread(web, "��");
		Thread th2 = new Thread(web, "��");
		Thread th3 = new Thread(web, "��");
		
		th1.start();
		th2.start();
		th3.start();
	}

}


class Web12306 implements Runnable{
	
	int num = 50;
	private boolean flag = true;
	@Override
	public void run()
	{
		while(flag)
		{
			test1();
		}
	}	

	public synchronized void test1()
	{
		if(num<=0)
		{
			flag = false;
			return;
		}
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(Thread.currentThread().getName() + "����Ʊ��" + num--);
	}
	public void test2()
	{
		synchronized(this)   //ͬ����
		{
			if(num<=0)
			{
				flag = false;
				return;
			}
			try {
				Thread.sleep(500);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName() + "����Ʊ��" + num--);
		}
	}
}