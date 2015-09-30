package fxy.oop.thread.pro;

/**
 * һ��������һ����Դ
 * ������������ģʽ
 * wait() �����ͷ���  sleep() ���ͷ���
 * ���� notify() / notifyAll()
 * ��synchronizedһ��ʹ��
 * @author ASD
 *
 */
public class Movie {
	
	private String pic;
	private boolean flag = true;
	//�źŵ�
	//flag-->true , �����������������ߵȴ���������ɺ�֪ͨ����
	//flag-->false , ���������ѣ������ߵȴ���������ɺ�֪ͨ����
	
	public Movie() {
	}

	public synchronized void player(String pic)
	{
		if(!flag) //�����ߵȴ�
		{
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//��ʼ����
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//�������
		this.pic = pic;
		//֪ͨ����
		this.notify();
		//������ͣ��
		this.flag = false;
	}
	
	public synchronized void watch()
	{
		if(flag)  //�����ߵȴ�
		{
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//��ʼ����
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(this.pic);
		//֪ͨ����
		this.notify();
		//�����ߵȴ�
		this.flag = true;
	}

}
