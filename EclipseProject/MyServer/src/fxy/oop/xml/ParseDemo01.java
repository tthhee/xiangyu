package fxy.oop.xml;

import java.io.IOException;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.SAXException;

public class ParseDemo01 {
	
	public static void main(String[] args) throws ParserConfigurationException, SAXException, IOException
	{
		//1获取解析工厂
		SAXParserFactory factory = SAXParserFactory.newInstance();
		//2从解析工厂获取解析器
		SAXParser parse = factory.newSAXParser();
		//3加载文档，指定处理器
		//4编写处理器
		PersonHandler handler = new PersonHandler();
		parse.parse(Thread.currentThread().getContextClassLoader()
				.getResourceAsStream("fxy/oop/xml/persons.xml")
				, handler);
		List<Persons> persons = handler.getPersons();
		for(Persons p:persons)
		{
			System.out.println(p.getName() + "-->" + p.getAge());
		}
	}

}
