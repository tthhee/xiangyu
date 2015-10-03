package fxy.oop.servelet;

import fxy.oop.server.Request;
import fxy.oop.server.Response;

public class TestServelet extends Servelet{

	@Override
	public void doGet(Response res, Request req) throws Exception {
		// TODO Auto-generated method stub
		res.println("success...");
		
	}

	@Override
	public void doPost(Response res, Request req) throws Exception {
		// TODO Auto-generated method stub
		
	}
	

}
