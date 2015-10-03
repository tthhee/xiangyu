package fxy.oop.server;

import java.util.ArrayList;
import java.util.List;

/**
 * 	<servelet-mapping>
		<servelet-name>login</servelet-name>
		<url-pattern>/login</url-pattern>
	</servelet-mapping>
	<servelet-mapping>
		<servelet-name>login</servelet-name>
		<url-pattern>/log</url-pattern>
	</servelet-mapping>
 * @author xiangyu
 *
 */
public class Mapping {
	private String name;
	private List<String> pattern;
	
	public Mapping()
	{
		name = null;
		pattern = new ArrayList<String>();
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public List<String> getPattern() {
		return pattern;
	}
	public void setPattern(List<String> pattern) {
		this.pattern = pattern;
	}
	

}
