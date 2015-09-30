package fxy.oop.thread.schedule;


import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

public class TimerSchedule {
	
	public static void main(String[] args)
	{
		Timer time = new Timer();
		
		time.schedule(new TimerTask(){
			@Override
			public void run()
			{
				System.out.println("schedule!!!");	
			}
		}, new Date(System.currentTimeMillis()+5000), 1000);
	}

}
