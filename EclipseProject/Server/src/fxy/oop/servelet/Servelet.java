package fxy.oop.servelet;

import fxy.oop.server.Request;
import fxy.oop.server.Response;

public abstract class Servelet {
	public  void service(Response res, Request req) throws Exception
	{

		this.doGet(res,req);
		this.doPost(res,req);
	}
	
	protected abstract void doGet(Response res, Request req) throws Exception;
	protected abstract void doPost(Response res, Request req) throws Exception;

}
