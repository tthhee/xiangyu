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
	 * �����ļ������ļ���
	 * @param source  Դ�ļ��� File����
	 * @param dest    Ŀ���ļ���File����
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
	 * �����ļ���Ŀ¼
	 * @param source  ԴĿ¼��Դ�ļ�
	 * @param dest    Ŀ���ļ���Ŀ��Ŀ¼
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
					System.out.println("���ܴ������ļ���ͬ�����ļ�");
					throw new IOException();
				}
				else
				{
					System.out.println("����ͬ���ļ����Ѹ��ǣ�");
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
				System.out.println("���ܽ���Ŀ¼��������Ŀ¼�У�����");
				return;
			}
			copydirectory(source, dest);
		}
	}
	
	/**
	 * ������ر���
	 * �ɱ������ ...  ֻ�ܷ����β����һ��λ�ã� ����ʽ������һ��
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
	 * ʹ�÷���
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
