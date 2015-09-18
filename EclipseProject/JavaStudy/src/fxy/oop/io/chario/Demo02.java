package fxy.oop.io.chario;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Demo02 {
	
	public static void main(String[] args)
	{
		String str = "hello world!!!!";
		File dest = new File("F:/FileCopyTest/fxy.txt");
		Writer writer = null;
		
		try {
			writer = new FileWriter(dest, true);  //true��ʾ���ļ���׷��
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("�ļ�������");
		}
		
		//char[] ch = str.toCharArray();
		try {
			writer.write(str);
			writer.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("�ļ�д��ʧ��");
		}finally{
			try {
				if(null != writer)
					writer.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	

}
