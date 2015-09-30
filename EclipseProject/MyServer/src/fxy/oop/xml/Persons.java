package fxy.oop.xml;

public class Persons {
	private String name;
	private int age;
	
	public Persons()
	{
		name = null;
		age = 0;
	}
	public Persons(String name, int age)
	{
		super();
		this.name = name;
		this.age = age;	
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	
	
}
