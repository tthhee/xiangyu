package fxy.oop.servelet;

import fxy.oop.server.Request;
import fxy.oop.server.Response;

public class RegisterServelet extends Servelet{

	@Override
	public void doGet(Response res, Request req) throws Exception {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void doPost(Response res, Request req) throws Exception {
		// TODO Auto-generated method stub
		res.println("<html><head><title>����ע��</title></head>");
		res.println("<body>");
		res.println("��ӭ��").println(req.getParameter("uname")).println("����");
		res.println("</body></html>");
	}


}
