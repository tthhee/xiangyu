package fxy.oop.tcp.socket;

import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * 1.创建服务器 指定端口 ServerSocket(int port)
 * 2.接受客户端连接
 * 3.发送数据和接受数据
 * @author ASD
 *
 */
public class Server {
	
	public static void main(String[] args) throws IOException
	{
		ServerSocket server = new ServerSocket(8888); //1024以下不使用，系统预留
		
		Socket socket = server.accept();
		String msg = "欢迎使用！";
		DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
		dos.writeUTF(msg);
		dos.flush();
		
		System.out.println("一个客户端建立连接！");
	}

}
