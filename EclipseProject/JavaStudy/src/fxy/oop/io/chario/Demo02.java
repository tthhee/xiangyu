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
			writer = new FileWriter(dest, true);  //true表示在文件后追加
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("文件不存在");
		}
		
		//char[] ch = str.toCharArray();
		try {
			writer.write(str);
			writer.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("文件写入失败");
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
