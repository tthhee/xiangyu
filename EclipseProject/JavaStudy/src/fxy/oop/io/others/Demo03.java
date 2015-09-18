package fxy.oop.io.others;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;

import org.omg.CORBA.portable.OutputStream;

public class Demo03 {
	public static void main(String[] args) throws FileNotFoundException
	{
		File src = new File("F:/FileCopyTest/fxy.txt");
	//	PrintStream ps = new PrintStream(src);
		PrintStream ps = new PrintStream(new BufferedOutputStream(
				new FileOutputStream(src)));
		
		ps.println("java is so easy...!!!..");
		ps.flush();
		
		ps.close();
	}
}
