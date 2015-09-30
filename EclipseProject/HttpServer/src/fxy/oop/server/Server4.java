package fxy.oop.server;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class Server4 {



	private ServerSocket server;
	public static void main(String[] args)
	{
		
		Server4 server = new Server4();
		server.start();
		
		
	}
	
	public void start()
	{
		try {
			this.server = new ServerSocket(1234);
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

			byte[] msg = new byte[20480];
			int len = client.getInputStream().read(msg);

			String requestInfo = new String(msg, 0, len).trim();
			System.out.println(requestInfo);
			
			Response response = new Response(client);
			response.println("<html><head><title>HTTP ResponseExample</title>");
			response.println("</head><body>Hello World!</body></html>");
			response.pushToClient(200);
			
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void stop()
	{
		
	}
}
