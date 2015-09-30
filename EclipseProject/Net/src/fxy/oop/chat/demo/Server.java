package fxy.oop.chat.demo;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	
	public static void main(String[] args) throws IOException
	{
		ServerSocket server = new ServerSocket(9999);
		Socket client = null;
		while(true)
		{
			client = server.accept();
			new Thread(new ServerThread(client)).start();
		}

	}

}
