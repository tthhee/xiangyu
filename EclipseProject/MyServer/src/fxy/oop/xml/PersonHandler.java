package fxy.oop.xml;

import java.util.ArrayList;
import java.util.List;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class PersonHandler  extends DefaultHandler{

	List<Persons> persons;
	Persons person = null;
	String tag = null;
	
	@Override
	public void startDocument() throws SAXException {
		// TODO Auto-generated method stub
		//System.out.println("处理文档开始");
		persons = new ArrayList<Persons>();
	}
	
	@Override
	public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		// TODO Auto-generated method stub
	//	System.out.println("开始一个元素" + qName);
		if(qName != null)
		{
			tag = qName;
		}
		if(null != qName && qName.equals("person"))
		{
			person = new Persons();
		}
	}
	
	@Override
	public void characters(char[] ch, int start, int length) throws SAXException {
		// TODO Auto-generated method stub
	//	System.out.println(new String(ch, start, length));
		if(tag == "name")
		{
			person.setName(new String(ch, start, length));
		}
		else if(tag == "age")
		{
			Integer age = Integer.valueOf(new String(ch, start, length));
			person.setAge(age);
		}
	}
	
	@Override
	public void endElement(String uri, String localName, String qName) throws SAXException {
		// TODO Auto-generated method stub
	//	System.out.println("结束一个元素" + qName);
		if(qName.equals("person"))
		{
			this.persons.add(person);
			
		}
		tag = null;
	}
	@Override
	public void endDocument() throws SAXException {
		// TODO Auto-generated method stub
	//	System.out.println("处理文档结束");
	}

	public List<Persons> getPersons() {
		return persons;
	}

	public void setPersons(List<Persons> persons) {
		this.persons = persons;
	}





	
}
