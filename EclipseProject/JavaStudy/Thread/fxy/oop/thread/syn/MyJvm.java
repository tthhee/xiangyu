package fxy.oop.thread.syn;

/**
 * ����������ʽ
 * 1������ʽ
 * 1����������˽�л�
 * 2��������˽�еľ�̬����
 * 3���������ṩ�������Եľ�̬������ȷ���ö�����ڣ���������ڣ���������
 * @author ASD
 *
 */
public class MyJvm {
	private static MyJvm instance = null;
	private MyJvm()
	{
		
	}
	
	public static MyJvm getinstance()
	{
		if(null == instance)  //Ϊ�����Ч��
		{
			synchronized(MyJvm.class)     //����class ������̬��Ϣ
			{
				if(null == instance)  //Ϊ�˰�ȫ
				{
					instance = new MyJvm();
				}
			}
		}
		return instance;
	}
}

/**
 * ����������ʽ
 * 1������ʽ
 * 1����������˽�л�
 * 2��������˽�еľ�̬���Բ���ʼ��
 * 3���������ṩ�������Եľ�̬������ȷ���ö�����ڣ���������ڣ���������
 * @author ASD
 *
 */
class MyJvm2 {
	private static MyJvm2 instance = new MyJvm2();
	private MyJvm2()
	{
		
	}
	
	public static MyJvm2 getinstance()
	{
		
		return instance;
	}
}

class MyJvm3 {
	private static class JVMHolder{
	private static MyJvm3 instance = new MyJvm3();
	}
	private MyJvm3()
	{
		
	}
	
	public static MyJvm3 getinstance()
	{
		
		return JVMHolder.instance;
	}
}