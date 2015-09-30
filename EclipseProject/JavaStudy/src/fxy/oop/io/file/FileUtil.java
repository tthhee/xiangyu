package fxy.oop.io.file;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class FileUtil {
	public static void copyfile(File source, File dest) throws IOException 
	{
		BufferedInputStream is = null;
		BufferedOutputStream os = null;

//		 is = new FileInputStream(source);	
//		 os = new FileOutputStream(dest);
		 is = new BufferedInputStream(new FileInputStream(source));	
		 os = new BufferedOutputStream(new FileOutputStream(dest));
		int len;
		byte[] str = new byte[1024];
			while(-1 != (len =is.read(str)))
			{
				os.write(str, 0, len);
				os.flush();
			}		
				os.close();		
				is.close();	
	}
	
	public static void copyfile(String sourcepath, String destpath) throws IOException 
	{
		File source = new File(sourcepath);
		File dest = new File(destpath);
		copyfile(source, dest);
	}
	
	/**
	 * 拷贝文件或者文件夹
	 * @param source  源文件夹 File对象
	 * @param dest    目标文件夹File对象
	 * @throws IOException
	 */
	private static void copydirectory(File source, File dest) throws IOException
	{
		if(!source.isDirectory())
		{
			copyfile(source.getPath(), dest.getPath() + "/" + source.getName());
		}
		else
		{
			File tempfile = new File(dest.getPath() ,source.getName());
			tempfile.mkdirs();
			dest = new File(dest.getPath() , tempfile.getName());
			File[] listfiles = source.listFiles();
			for(File temp:listfiles)
			{
				copydirectory( temp, dest);
			}
		}
	}
	/**
	 * 拷贝文件或目录
	 * @param source  源目录或源文件
	 * @param dest    目标文件或目标目录
	 * @throws IOException
	 */
	public static void copy(File source, File dest) throws IOException
	{
		if(source.isFile())
		{
			if(dest.exists())
			{
				if(dest.isDirectory())
				{
					System.out.println("不能创建与文件夹同名的文件");
					throw new IOException();
				}
				else
				{
					System.out.println("存在同名文件，已覆盖！");
					copyfile(source, dest);
				}
			}
			else
				copyfile(source, dest);
		}
		else
		{
			if(dest.getAbsolutePath().contains(source.getAbsolutePath()))
			{
				System.out.println("不能将父目录拷贝到子目录中！！！");
				return;
			}
			copydirectory(source, dest);
		}
	}
	
	/**
	 * 工具类关闭流
	 * 可变参数： ...  只能放在形参最后一个位置， 处理方式与数组一致
	 * @param io
	 */
	public static void close(Closeable ... io)
	{
		for(Closeable temp : io)
		{
			if(null != temp)
			{
				try {
					temp.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	/**
	 * 使用泛型
	 * @param io
	 */
	public static <T extends Closeable> void closeAll(T ... io)
	{
		for(T temp : io)
		{
			if(null != temp)
			{
				try {
					temp.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}
