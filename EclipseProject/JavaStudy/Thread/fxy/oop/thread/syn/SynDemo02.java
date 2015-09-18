package fxy.oop.thread.syn;

/**
 * 单例设计模式：外部使用时确保一个类只有一个对象
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
 * 单例设计模式
 * 确保一个类只有一个对象
 * 懒汉式  double checking
 * 1、构造器私有化，避免外部直接创建对象
 * 2、声明一个私有的静态变量
 * 3、创建一个对外的公共的静态方法访问该变量，如果变量没有对象，创建该对象
 * @author ASD
 *
 */
class Jvm{
	private static Jvm instance = null;
	//构造器私有化，避免外部直接创建对象
	private Jvm()
	{
		
	}
	
	public static Jvm getinstance1(long time)
	{
		if(null == instance)    //提高效率
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
		System.out.println(Thread.currentThread().getName() + "创建" + jvmthread);
		
	}
}