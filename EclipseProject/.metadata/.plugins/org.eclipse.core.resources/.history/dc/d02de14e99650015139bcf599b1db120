package fxy.oop.httpserver;

import java.util.HashMap;
import java.util.Map;

/**
 * 上下文
 * @author xiangyu
 *
 */
public class ServeletContext {

	//为每一个servelet取一个别名
	//login --> LoginServelet
	private Map<String, Servelet> servelet;
	//url -->login
	//一个资源允许多个路径
	private Map<String, String> mapping;
	
	public ServeletContext()
	{
		servelet = new HashMap<String, Servelet>();
		mapping = new HashMap<String, String>();
	}
	
	public Map<String, Servelet> getServelet() {
		return servelet;
	}
	public void setServelet(Map<String, Servelet> servelet) {
		this.servelet = servelet;
	}
	public Map<String, String> getMapping() {
		return mapping;
	}
	public void setMapping(Map<String, String> mapping) {
		this.mapping = mapping;
	}
	
	
}
