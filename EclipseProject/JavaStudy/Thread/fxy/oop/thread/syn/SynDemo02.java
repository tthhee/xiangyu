package fxy.oop.thread.syn;

/**
 * �������ģʽ���ⲿʹ��ʱȷ��һ����ֻ��һ������
 * @author ASD
 *
 */
public class SynDemo02 {
	public static void main(String[] args)
	{
		Jvmthread jvmthread1 = new Jvmthread(100);
		Jvmthread jvmthread2 = new Jvmthread(500);
		jvmthread1.start();
		jvmthread2.start();
	}

}

/**
 * �������ģʽ
 * ȷ��һ����ֻ��һ������
 * ����ʽ  double checking
 * 1��������˽�л��������ⲿֱ�Ӵ�������
 * 2������һ��˽�еľ�̬����
 * 3������һ������Ĺ����ľ�̬�������ʸñ������������û�ж��󣬴����ö���
 * @author ASD
 *
 */
class Jvm{
	private static Jvm instance = null;
	//������˽�л��������ⲿֱ�Ӵ�������
	private Jvm()
	{
		
	}
	
	public static Jvm getinstance1(long time)
	{
		if(null == instance)    //���Ч��
		{
			synchronized(Jvm.class){
				if(null == instance)
				{
					try {
						Thread.sleep(time);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
					instance = new Jvm();
				}
			}
		}
		return instance;
	}
	
	public static synchronized Jvm getinstance(long time)
	{
		if(null == instance)
		{
			try {
				Thread.sleep(time);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			instance = new Jvm();
		}
		return instance;
	}
}

class Jvmthread extends Thread{
	private long time;
	public Jvmthread(long time)
	{
		this.time = time;
	}
	@Override
	public void run()
	{
		Jvm jvmthread = Jvm.getinstance(time);
		System.out.println(Thread.currentThread().getName() + "����" + jvmthread);
		
	}
}