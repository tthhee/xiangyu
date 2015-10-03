package fxy.oop.server;

import java.io.IOException;
import java.net.Socket;

import fxy.oop.servelet.Servelet;
import fxy.oop.serverUtil.CloseUtil;


public class Dispatcher implements Runnable{

	private int code = 200;
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
			code = 500;
		}
		
	}
	
	@Override
	public void run() {
		// TODO Auto-generated method stub
			Servelet serv = null;
			try {
				serv = new WebApp().getServelet(req.getUrl());
			} catch (InstantiationException | IllegalAccessException | ClassNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
	
			if(null == serv)
			{
				this.code = 404;
			}
			else
			{
				try {
					serv.service(res, req);
				} catch (Exception e2) {
					// TODO Auto-generated catch block
					code = 500;
				}
			}
		try {
			res.PushToClient(code);
		} catch (IOException e) {
			CloseUtil.closeIO(client);
		}
		
	}

}
