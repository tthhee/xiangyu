package fxy.oop.httpserver.demo4;

public class LoginServelet extends Servelet {

	@Override
	public void doGet(Response res, Request req) throws Exception {
		// TODO Auto-generated method stub
		String name = req.getParameter("uname");
		String pwd = req.getParameter("pwd");
		if(login(name, pwd))
		{
			res.println("��¼�ɹ�\n");
		}
		else
		{
			res.println("��¼ʧ��\n");
		}
		res.println("<html><head><title>��ӭ����</title></head>");
		res.println("<body>");
		res.println("��ӭ��").println(req.getParameter("uname")).println("����");
		res.println("</body></html>");
	}
	
	boolean login(String name, String pwd)
	{
		return name.equals("tthhee") && pwd.equals("fxy123");
	}
	@Override
	public void doPost(Response res, Request req) throws Exception {
		// TODO Auto-generated method stub
		
	}

}
