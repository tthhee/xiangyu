package fxy.oop.chat.demo;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerThread implements Runnable{

	private DataInputStream dis;
	private DataOutputStream dos;
	private Socket client;
	private boolean isRunning = true;
	
	public ServerThread(Socket server)
	{
		client = server; 
		 try {
			dis = new DataInputStream(client.getInputStream());
			dos = new DataOutputStream(client.getOutputStream());
		} catch (IOException e) {
			isRunning = false;
			CloseUtil.closeAll(dis, dos);
		}
	}
	@Override
	public void run() {
		
		while(true)
		{
			try {
				String info = dis.readUTF();
				dos.writeUTF( Thread.currentThread().getName() + "·þÎñ¶Ë->" + info);
				dos.flush();
			} catch (IOException e) {
				isRunning = false;
				CloseUtil.closeAll(dis,dos);
			}
			
		}

	}
	

}
