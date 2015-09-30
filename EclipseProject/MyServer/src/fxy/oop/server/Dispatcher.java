package fxy.oop.server;

import java.io.IOException;
import java.net.Socket;
import fxy.oop.server.util.*;

public class Dispatcher implements Runnable{

	private int code;
	private Socket client;
	private Request req;
	private Response res;
	private Servelet serv;
	
	public Dispatcher(Socket client)
	{
		this.client = client;
		try {
			req = new Request(client.getInputStream());
			res = new Response(client);
		} catch (IOException e) {
		}
		serv = new Servelet();
		code = 200;
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
		serv.service(res, req);	
		try {
			res.PushToClient(code);
		} catch (IOException e) {
			code = 500;
			try {
				res.PushToClient(code);
			} catch (IOException e1) {
				CloseUtil.closeIO(client);
			}
		}
		
	}

}
