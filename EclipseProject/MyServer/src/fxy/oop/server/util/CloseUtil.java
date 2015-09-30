package fxy.oop.server.util;

import java.io.Closeable;
import java.io.IOException;

public class CloseUtil {

	public static void closeIO(Closeable... io)
	{
		for(Closeable temp:io)
		{
			if(null != temp)
			{
				try {
					temp.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
				}
			}
		}
	}
}
