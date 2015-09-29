package fxy.oop.tcp.socket;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * 1.创建客户端   必须指定服务器+端口  此时就在连接
 * Socket(String host, int port) 
 * @author ASD
 *
 */
public class Client {
	
	public static void main(String[] args) throws UnknownHostException, IOException
	{
		Socket client = new Socket("127.0.0.1", 8010);
		
		DataInputStream dis = new DataInputStream(client.getInputStream());
		String echo = dis.readUTF();
		System.out.println(echo);
	}

}
