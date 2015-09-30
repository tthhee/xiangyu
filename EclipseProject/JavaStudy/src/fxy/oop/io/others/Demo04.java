package fxy.oop.io.others;

import java.io.InputStream;
import java.util.Scanner;

/**
 * 
 * @author ASD
 *
 */


public class Demo04 {
	public static void main(String[] args)
	{
		InputStream is = System.in;
		
		Scanner sc = new Scanner(is);
		
		System.out.println(sc.nextLine());
	}
}
