package fxy.oop.thread;


/**
 * 使用Runnable创建线程
 * 1.类 实现Runnable接口 + 重写run()
 * 2.启动多线程 使用静态代理
 * 		1)创建真实角色
 * 		2)创建代理角色 + 真实角色引用
 * 		3)调用start()方法，启动线程
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
