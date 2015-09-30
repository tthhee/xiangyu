package fxy.oop.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
	
	private ServerSocket server;
	static public void main(String[] args)
	{
		Server server = new Server();
		server.start();
	}
	
	public void start()
	{
		try {
			 this.server = new ServerSocket(8888);
			 this.receive();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private void receive()
	{
		try {
			Socket client = this.server.accept();
			StringBuilder sb = new StringBuilder();
			String RequestInfo = null;
			String msg = null;
			BufferedReader rb = new BufferedReader(new InputStreamReader(client.getInputStream()));
			while((msg = rb.readLine()).length()>0)
			{
				sb.append(msg);
				sb.append("\r\n");
				if(null == msg)
					break;
			}
			//接收了客户端的请求信息
			RequestInfo = sb.toString().trim();
			System.out.println(RequestInfo);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	void stop()
	{
		
	}
}
