package fxy.oop.io.others;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.List;

public class SplitFile {
	private File file;
	//文件路径名
	private String filepath;
	//文件名
	private String filename;
	//块数
	int size;
	//每块的大小
	private long blocksize;
	private List<String> blockpath;
	
	public SplitFile()
	{
		blockpath = new ArrayList<String>();
	}
	public SplitFile(String filepath)
	{
		this(filepath, 1024);
	}
	public SplitFile(String filepath, long blocksize)
	{
		this();
		this.file = new File(filepath);
		this.filepath = filepath;
		this.blocksize = blocksize;
		init();  //创建对象的时候就进行初始化
		initblockpath();
	}
	/**
	 * 初始化过程，计算分割的块数
	 */
	public void init()
	{
	//	File src = null;
		if(this.file == null || !(this.file.exists()))
		{
			return;
		}
		if(this.file.isDirectory())  //如果是目录不能分割
		{
			return;
		}
		else
		{
			this.filename = this.file.getName();
			long length = this.file.length();
			if(this.blocksize > length)
			{
				this.blocksize = length;
			}
			
			//计算块数
			this.size = (int)Math.ceil(length*1.0/this.blocksize);
		}
		
	}
	
	public void initblockpath()
	{
		for(int i=0; i< this.size; i++)
		{
			this.blockpath.add(this.filename +  "part" + i + ".txt");
		}
	}
	
	public void split() throws IOException
	{
			split(this.file.getParent());
	}
	/**
	 * 文件分割
	 * destpath 为文件分割后的存储路径
	 * @throws IOException 
	 */
	public void split(String destpath) throws IOException
	{
		RandomAccessFile raf = new RandomAccessFile(this.file, "rw"); //可读写模式
		raf.seek(0);
		byte[] temp = new byte[1024]; 
		int len;
		for(int i=0; i< this.size; i++)
		{
			raf.seek(i*this.blocksize);
			File dest = new File(destpath + "/" + this.blockpath.get(i) + ".txt");
			BufferedOutputStream writefile = new BufferedOutputStream(new FileOutputStream(dest, true)); //append
			int n = 0;
			while(-1 != (len = raf.read(temp)))
			{
				if(i < this.size-1)
				{
					if(len >= this.blocksize)
					{
						writefile.write(temp, 0, (int)this.blocksize);
						writefile.flush();
						break;
					}
					else if(len < this.blocksize-n*1024)
					{
						writefile.write(temp, 0, len);
						writefile.flush();
						n++;
					}
					else
					{
						writefile.write(temp, 0, (int)(this.blocksize-n*1024));
						writefile.flush();
						break;
					}
				}
				else
				{
					writefile.write(temp, 0, len);
					writefile.flush();
				}
			}
			writefile.close();
		}
		raf.close();
	}
	public String getFilepath() {
		return filepath;
	}
	public void setFilepath(String filepath) {
		this.filepath = filepath;
	}
	public long getBlocksize() {
		return blocksize;
	}
	public void setBlocksize(long blocksize) {
		this.blocksize = blocksize;
	}
	public List<String> getBlockpath() {
		return blockpath;
	}
	public void setBlockpath(List<String> blockpath) {
		this.blockpath = blockpath;
	}
	
	public String getFilename() {
		return filename;
	}
	public void setFilename(String filename) {
		this.filename = filename;
	}
	public int getSize() {
		return size;
	}
	public void setSize(int size) {
		this.size = size;
	}
	public static void main(String[] args)
	{
		SplitFile sf = new SplitFile("F:/FileCopyTest/fxy.txt", 350);
		System.out.println(sf.filename);
		try {
			sf.split("F:/FileCopyTest/parts");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		System.out.println(sf.getSize());
		for(String temp : sf.getBlockpath())
		{
			System.out.println(temp);
		}
	}
}
