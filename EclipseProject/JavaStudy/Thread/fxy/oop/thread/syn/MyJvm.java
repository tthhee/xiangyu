package fxy.oop.thread.syn;

/**
 * 单例创建方式
 * 1、懒汉式
 * 1）、构造器私有化
 * 2）、声明私有的静态属性
 * 3）、对外提供访问属性的静态方法，确保该对象存在，如果不存在，创建对象
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
		if(null == instance)  //为了提高效率
		{
			synchronized(MyJvm.class)     //锁定class 锁定静态信息
			{
				if(null == instance)  //为了安全
				{
					instance = new MyJvm();
				}
			}
		}
		return instance;
	}
}

/**
 * 单例创建方式
 * 1、饿汉式
 * 1）、构造器私有化
 * 2）、声明私有的静态属性并初始化
 * 3）、对外提供访问属性的静态方法，确保该对象存在，如果不存在，创建对象
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