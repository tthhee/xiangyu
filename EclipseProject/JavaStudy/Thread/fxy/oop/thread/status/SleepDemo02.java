package fxy.oop.thread.status;

//import fxy.oop.thread.Web12306;

/**
 * sleep()ģ��������ʱ
 * @author ASD
 *
 */
public class SleepDemo02 {
	
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
	@Override
	public void run()
	{
		while(true)
		{
			if(num<=0)
			{
				break;
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