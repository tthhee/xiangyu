package fxy.oop.thread.status;

import java.text.SimpleDateFormat;
import java.util.Date;

public class SleepDemo {

	public static void main(String[] args) throws InterruptedException
	{
		Date endtime = new Date(System.currentTimeMillis()+10000);
		long end = endtime.getTime();
		
		while(true)
		{
			System.out.println(new SimpleDateFormat("mm:ss").format(endtime));
			endtime = new Date(endtime.getTime()-1000);
			Thread.sleep(1000);
			if(endtime.getTime() < end-10000)
				break;
		}
	}
}
