package fxy.oop.tcp.socket;

import java.io.BufferedWriter;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * 1.���������� ָ���˿� ServerSocket(int port)
 * 2.���ܿͻ�������
 * 3.�������ݺͽ�������
 * @author ASD
 *
 */
public class Server {
	
	public static void main(String[] args) throws IOException
	{
		ServerSocket server = new ServerSocket(8888); //1024���²�ʹ�ã�ϵͳԤ��
		
		Socket socket = server.accept();
		String msg = "��ӭʹ�ã�";
		DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
		dos.writeUTF(msg);
		dos.flush();
		
		System.out.println("һ���ͻ��˽������ӣ�");
	}

}
