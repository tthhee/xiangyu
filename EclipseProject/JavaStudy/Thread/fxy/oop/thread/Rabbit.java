package fxy.oop.thread;

/**
 * ģ���������
 * 1.�������߳� �̳�Thread + ��дrun(�߳���)����
 * 2.ʹ���̣߳������������ + ���� ����start()����
 * @author ASD
 *
 */
public class Rabbit extends Thread {

	@Override
	public void run() {
		for(int i=0; i< 100; i++)
		{
			System.out.println("Rabit: " + i);
		}
	}
		
}

class Tortose extends Thread{
	
	@Override
	public void run()
	{
		for(int i=0; i< 100; i++)
		{
			System.out.println("Tortose: " + i);
		}
	}
}
