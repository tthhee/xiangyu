package fxy.oop.httpserver.demo3;

import java.util.Map;

public class WebApp {
	
	public static ServeletContext context;
	
	static{
		context = new ServeletContext();
		Map<String, String> mapping = context.getMapping();
		mapping.put("/login", "login");
		mapping.put("/log", "login");
		mapping.put("/reg", "register");
		
		Map<String, String> servelet = context.getServelet();
		servelet.put("login", "fxy.oop.httpserver.demo3.LoginServelet");
		servelet.put("register", "fxy.oop.httpserver.demo3.RegisterServelet");
	}
	
	public static Servelet getServelet(String url) throws InstantiationException, IllegalAccessException, ClassNotFoundException
	{
		if(null==url || url.trim().equals(""))
		{
			return null;
		}
		
		String name = context.getServelet().get(context.getMapping().get(url));
		return (Servelet)Class.forName(name).newInstance();	  //ȷ���չ���������
	}

}