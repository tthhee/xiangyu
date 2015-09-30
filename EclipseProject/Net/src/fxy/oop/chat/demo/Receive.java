package fxy.oop.chat.demo;

import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class Receive implements Runnable{
	//������
	private DataInputStream dis;
	//�̱߳�ʶ
	private boolean isRunning = true;
	
	public Receive()
	{
		
	}
	public Receive(Socket client)
	{
		try {
			dis = new DataInputStream(client.getInputStream());
		} catch (IOException e) {
			isRunning = false;
			CloseUtil.closeAll(dis);
		}
	}
	public String receive()
	{
		String str = "";
		try {
			str = dis.readUTF();
		} catch (IOException e) {
			isRunning = false;
			CloseUtil.closeAll(dis);
		}
		
		return str;
	}
	@Override
	public void run() {
		while(isRunning)
		{
			System.out.println(receive());
		}

	}

}
