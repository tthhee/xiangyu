package fxy.oop.server;

/**
 * <servelet>
		<servelet-name>login</servelet-name>
		<servelet-class>fxy.oop.httpserver.demo4.LoginServelet</servelet-class>
	</servelet>
 * @author xiangyu
 *
 */
public class Entity {
	private String name;
	private String clz;
	
	public Entity()
	{
		name = null;
		clz = null;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getClz() {
		return clz;
	}
	public void setClz(String clz) {
		this.clz = clz;
	}
	
}
