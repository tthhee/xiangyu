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
 * 转换流：字节流转为字符
 * 1、输出流 OutputStreamWriter 编码
 * 2、输入流InputStreamReader  解码
 * @author ASD
 *
 */
public class ConverDemo01 {
	
	public static void main(String[] args) throws IOException
	{ 
		//指定解码字符集
		BufferedReader br = new BufferedReader(
				new InputStreamReader(
						new FileInputStream(new File("F:/FileCopyTest/fxy1.txt")), "UTF-8"));
		
		//写出文件
		BufferedWriter wr = new BufferedWriter(
				new OutputStreamWriter(
						new FileOutputStream(new File("F:/FileCopyTest/fxy4.txt")), "UTF-8"));
		String info = null;
		while(null != (info = br.readLine()))
		{
			System.out.println(info);
		}
		wr.write("我都有一个家！");
		wr.flush();
		
		wr.close();
		br.close();
	}
}
