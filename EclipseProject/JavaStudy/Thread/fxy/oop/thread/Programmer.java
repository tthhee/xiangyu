package fxy.oop.thread;


/**
 * ʹ��Runnable�����߳�
 * 1.�� ʵ��Runnable�ӿ� + ��дrun()
 * 2.�������߳� ʹ�þ�̬����
 * 		1)������ʵ��ɫ
 * 		2)���������ɫ + ��ʵ��ɫ����
 * 		3)����start()�����������߳�
 * @author ASD
 *
 */
public class Programmer implements Runnable{
	@Override
	public void run()
	{
		for(int i=0; i<1000; i++)
		{
			System.out.println("hello world");
		}
	}
}
