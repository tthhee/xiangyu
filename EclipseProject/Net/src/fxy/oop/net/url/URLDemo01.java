package fxy.oop.net.url;

import java.net.MalformedURLException;
import java.net.URL;

public class URLDemo01 {
	
	public static void main(String[] args) throws MalformedURLException
	{
		URL url = new URL("http://www.baidu.com:80/index.html#aa?uname=fxy");
		System.out.println(url.getProtocol());
		System.out.println(url.getFile());
		System.out.println(url.getPath());
	}

}
