package fxy.oop.io.convert;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;

/**
 * ת�������ֽ���תΪ�ַ�
 * 1������� OutputStreamWriter ����
 * 2��������InputStreamReader  ����
 * @author ASD
 *
 */
public class ConverDemo01 {
	
	public static void main(String[] args) throws IOException
	{ 
		//ָ�������ַ���
		BufferedReader br = new BufferedReader(
				new InputStreamReader(
						new FileInputStream(new File("F:/FileCopyTest/fxy1.txt")), "UTF-8"));
		
		//д���ļ�
		BufferedWriter wr = new BufferedWriter(
				new OutputStreamWriter(
						new FileOutputStream(new File("F:/FileCopyTest/fxy4.txt")), "UTF-8"));
		String info = null;
		while(null != (info = br.readLine()))
		{
			System.out.println(info);
		}
		wr.write("�Ҷ���һ���ң�");
		wr.flush();
		
		wr.close();
		br.close();
	}
}
