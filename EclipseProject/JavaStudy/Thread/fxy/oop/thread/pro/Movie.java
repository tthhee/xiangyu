package fxy.oop.thread.pro;

/**
 * 一个场景，一份资源
 * 生产者消费者模式
 * wait() 可以释放锁  sleep() 不释放锁
 * 唤醒 notify() / notifyAll()
 * 与synchronized一起使用
 * @author ASD
 *
 */
public class Movie {
	
	private String pic;
	private boolean flag = true;
	//信号灯
	//flag-->true , 生产者生产，消费者等待，生产完成后通知消费
	//flag-->false , 消费者消费，生产者等待，消费完成后通知生产
	
	public Movie() {
	}

	public synchronized void player(String pic)
	{
		if(!flag) //生产者等待
		{
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//开始生产
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//生产完毕
		this.pic = pic;
		//通知消费
		this.notify();
		//生产者停下
		this.flag = false;
	}
	
	public synchronized void watch()
	{
		if(flag)  //消费者等待
		{
			try {
				this.wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		//开始消费
		try {
			Thread.sleep(500);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println(this.pic);
		//通知生产
		this.notify();
		//消费者等待
		this.flag = true;
	}

}
