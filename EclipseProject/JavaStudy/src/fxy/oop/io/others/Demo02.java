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
	 * java.io.EOFException :��ʾ�ļ�����  ����+���� ���ļ�
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
		String data3 = "���Ƕ���һ����";
		
		DataOutputStream dos = new DataOutputStream(
					new BufferedOutputStream(
							new FileOutputStream(dest)));
		
		//��ס����˳��Ϊ��ȡ����
		dos.writeDouble(data1);
		dos.writeLong(data2);
		dos.writeUTF(data3);	
		dos.flush();
		dos.close();
	}
}
