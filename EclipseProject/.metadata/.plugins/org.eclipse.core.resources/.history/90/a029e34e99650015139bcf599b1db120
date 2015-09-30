package fxy.oop.httpserver;

public abstract class Servelet {
	public  void service(Response res, Request req) throws Exception
	{
//		res.println("<html><head><title>HTTP响应示例</title></head>");
//		res.println("<body>");
//		res.println("欢迎：").println(req.getParameter("uname")).println("回来");
//		res.println("</body></html>");
		this.doGet(res,req);
		this.doPost(res,req);
	}
	
	public abstract void doGet(Response res, Request req) throws Exception;
	public abstract void doPost(Response res, Request req) throws Exception;

}
