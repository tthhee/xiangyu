package fxy.oop.io.chario;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

/**
 * 字符流：处理纯文本
 * @author ASD
 *
 */
public class Demo01 {
	
	public static void main(String[] args)
	{
		File src = new File("F:/FileCopyTest/fxy.txt");
		Reader reader = null;
		
		try {
			reader = new FileReader(src);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("关联IO流失败");
		}
		char[] ch = new char[1024];
		int len;
		try {
			while(-1 != (len = reader.read(ch)))
				{
					String str = new String(ch, 0, len);
					System.out.println(str);
				}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("文件读取失败");
		}finally{
			if(null != src)
			{
				try {
					reader.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		
	}
}
