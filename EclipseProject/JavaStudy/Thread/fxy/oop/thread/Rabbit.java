package fxy.oop.thread;

/**
 * 模拟龟兔赛跑
 * 1.创建多线程 继承Thread + 重写run(线程题)方法
 * 2.使用线程：创建子类对象 + 调用 对象start()方法
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
