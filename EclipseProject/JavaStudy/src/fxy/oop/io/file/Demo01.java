package fxy.oop.io.file;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class Demo01 {
	public static void main(String[] args)
	{
		File src1 = new File("F:/FileCopyTest");
		File src2 = new File("F:/FileCopyTest2");
		try {
			FileUtil.copy(src1, src2);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("拷贝失败");
		}
	}
	public static void ostream(String str, File src)
	{
		
	//	File src = new File("F:/fxy.txt");
		BufferedOutputStream os = null;
		if(!src.exists())
		{
			try {
				src.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.out.println("创建文件失败");
			}
		}
		try {
			os = new BufferedOutputStream(new FileOutputStream(src, false));  //true 表示在文件末尾追加，不覆盖原内容
		//	String str = "I love you!\r\n";
			byte[] car = str.getBytes();
			try {
				os.write(car);
				os.flush();
//				for(int i=0; i<10; i++)
//				{
//					os.write(car, 0, car.length);
//					os.flush();
//				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.out.println("写入文件失败");
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			System.out.println("创建输出流失败");
		}finally{
			try {
				os.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.out.println("关闭文件失败");
			}
		}
	}
	public static String istream(File src)
	{
	//	File src = new File("F:/fxy.txt");
		InputStream is = null;  //作用域提升，便于后面close的使用
		String temp = null;
		if(src.exists())
		{
			try {
				 is = new FileInputStream(src);
				 byte[] car = new byte[1024];
				 int len;
				 
				 try {
					while(-1 != (len = is.read(car)))
					{
						temp =temp + new String(car, 0, len);
						//System.out.println(new String(car,0,len));
					}
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.out.println("文件读取失败");
				}
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.out.println("关联输入流失败");
			}
			finally{
				try {
					is.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.out.println("文件流关闭失败");
				}
			}
		}
		else
		{
			System.out.println("文件不存在");
		}
		return temp;
	}
	

}
