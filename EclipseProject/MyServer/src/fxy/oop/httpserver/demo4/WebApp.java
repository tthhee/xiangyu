package fxy.oop.httpserver.demo4;

import java.io.IOException;
import java.util.Map;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.SAXException;

public class WebApp {
	
	public static ServeletContext context;
	
	static{
		WebHandler web = null;
			try {
				//��ȡ��������
				SAXParserFactory factory = SAXParserFactory.newInstance();
				//��ȡ������
				SAXParser sax = factory.newSAXParser();
				//ָ��xml��
				web = new WebHandler();
				sax.parse(Thread.currentThread().getContextClassLoader()
						.getResourceAsStream("fxy/oop/httpserver/demo4/web.xml"), web);
				
				
			} catch (ParserConfigurationException | SAXException | IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		context = new ServeletContext();
		Map<String, String> mapping = context.getMapping();
		for(Mapping m:web.getMappingList())
		{
			for(String s:m.getPattern())
			{
				mapping.put(s, m.getName());
			}
		}
		Map<String, String> servelet = context.getServelet();
		for(Entity p:web.getEntityList())
		{
			//mapping.put(p.getName(),p.getPattern());
			servelet.put(p.getName(), p.getClz());
		}
		
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