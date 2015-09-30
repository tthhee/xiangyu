package fxy.oop.io.others;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class Demo01 {
	@SuppressWarnings("resource")
	public static void main(String[] args) throws IOException
	{
		File src = new File("F:/FileCopyTest/pic2.jpg");
		File dest = new File("F:/FileCopyTest2/fxy.jpg");
		BufferedInputStream isfile = null;
		BufferedOutputStream outfile = null;
		
		isfile = new BufferedInputStream(new FileInputStream(src));
		outfile = new BufferedOutputStream(new FileOutputStream(dest));
		
		byte[] pipe = new byte[1024];
		int len;
		String temp;
		byte[] temparray = new byte[1024];
		while(-1 != (len = isfile.read(pipe, 0, 1024)))
		{
			 temp = read(write(pipe));
			 temparray = temp.getBytes();
			 outfile.write(temparray, 0, len);
			 outfile.flush();
		}
		
		outfile.close();
		isfile.close();
		
	}
	public static byte[] write(byte[] src) throws IOException
	{
	//	String str = "生活如此美好哈哈！";
	//	byte[] src = str.getBytes();
		byte[] dest;
		ByteArrayOutputStream os = new ByteArrayOutputStream();
		os.write(src);
		dest = os.toByteArray();
		os.close();
		return dest;
	}
	public static String read(byte[] src) throws IOException
	{
		InputStream is = new ByteArrayInputStream(src);
		
		
		String str = null;
		int len;
		byte[] dest = new byte[2014];
		while(-1 != (len = is.read(dest, 0, 1024)))
		{
			str = str + new String(dest, 0, len);
		}
		
		return str;
	}
}
