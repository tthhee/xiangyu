package fxy.oop.thread.info;

/**
 * ���ȼ������ʣ����Ǿ��Ե����ȼ�
 * MAX_PRIORITY   10
 * NORM_PRIORITY   5 ��Ĭ�ϣ�
 * MIN_PRIORITY    1
 * @author ASD
 *
 */
public class InfoDeom02 {
	
	public static void main(String[] args) throws InterruptedException
	{
		MyThread it1 = new MyThread();
		MyThread it2 = new MyThread();
		Thread p1 = new Thread(it1, "IT01");
		Thread p2 = new Thread(it2, "IT02");
		
		p1.setPriority(Thread.MAX_PRIORITY);
		p2.setPriority(Thread.MIN_PRIORITY);
		
		p1.start();
		p2.start();
		
		Thread.sleep(100);
		it1.stop();
		it2.stop();
	}

}
