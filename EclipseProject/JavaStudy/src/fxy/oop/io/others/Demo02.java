package fxy.oop.io.others;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class Demo02 {
	public static void main(String[] args)
	{
		try {
			read("F:/FileCopyTest/fxy.txt");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	/**
	 * java.io.EOFException :表示文件不是  数据+类型 的文件
	 * @param srcpath
	 * @throws IOException
	 */
	public static void read(String srcpath) throws IOException
	{
		File src = new File(srcpath);
		DataInputStream dis = new DataInputStream(
				new BufferedInputStream(
						new FileInputStream(src)));
		
		double data1 = dis.readDouble();
		long data2 = dis.readLong();
		String data3 = dis.readUTF();
		
		dis.close();
		
		System.out.println(data1);
	}
	public static void write(String destpath) throws IOException
	{
		File dest = new File(destpath);
		
		double data1 = 2.5;
		long data2 = 100L;
		String data3 = "我们都有一个家";
		
		DataOutputStream dos = new DataOutputStream(
					new BufferedOutputStream(
							new FileOutputStream(dest)));
		
		//记住操作顺序，为读取而用
		dos.writeDouble(data1);
		dos.writeLong(data2);
		dos.writeUTF(data3);	
		dos.flush();
		dos.close();
	}
}
