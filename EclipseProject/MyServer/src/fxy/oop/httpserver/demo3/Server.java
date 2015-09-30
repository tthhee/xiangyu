package fxy.oop.httpserver.demo3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

import fxy.oop.server.util.CloseUtil;

public class Server {
	
	public static final String CRLF="\r\n";
	public static final String BLANK=" ";
	private ServerSocket server;
	private boolean isshutdown;
	static public void main(String[] args)
	{
		Server server = new Server();
		server.isshutdown = true;
		server.start();
	}
	
	public void start()
	{
		this.start(8888);
	}
	
	public void start(int port)
	{
		try {
			 this.server = new ServerSocket(port);
			 this.receive();
		} catch (IOException e) {
			stop();
		}
	}
	
	private void receive()
	{
		while(isshutdown)
		{
			try {
				new Thread(new Dispatcher(this.server.accept())).start();
			} catch (IOException e) {
				stop();
			}
		}
	}
	void stop()
	{
		isshutdown = false;
		CloseUtil.closeIO(server);
	}
}
