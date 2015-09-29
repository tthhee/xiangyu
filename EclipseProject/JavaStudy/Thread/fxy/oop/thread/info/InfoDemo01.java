package fxy.oop.thread.info;

/**
 * Thread.currentThread()   当前线程
 * setName()    设置名称
 * getName()    获取名称
 * isAlive      状态
 * @author ASD
 *
 */
public class InfoDemo01 {
	public static void main(String[] args) throws InterruptedException
	{
		MyThread it = new MyThread();
		Thread poxy = new Thread(it);
		poxy.setName("IT");
		System.out.println(poxy.getName());
		System.out.println(Thread.currentThread().getName());
		poxy.start();
		
		System.out.println("isAlive:" + poxy.isAlive());
		Thread.sleep(20);
		System.out.println("isAlive:" + poxy.isAlive());
		it.stop();
		Thread.sleep(100);
		System.out.println("isAlive:" + poxy.isAlive());
	}
	
}
