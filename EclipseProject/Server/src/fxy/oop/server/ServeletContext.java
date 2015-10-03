package fxy.oop.server;

import java.util.HashMap;
import java.util.Map;

/**
 * ������
 * @author xiangyu
 *
 */
public class ServeletContext {

	//Ϊÿһ��serveletȡһ������
	//login --> LoginServelet
	private Map<String, String> servelet;
	//url -->login
	//һ����Դ������·��
	private Map<String, String> mapping;
	
	public ServeletContext()
	{
		servelet = new HashMap<String, String>();
		mapping = new HashMap<String, String>();
	}
	
	public Map<String, String> getServelet() {
		return servelet;
	}
	public void setServelet(Map<String, String> servelet) {
		this.servelet = servelet;
	}
	public Map<String, String> getMapping() {
		return mapping;
	}
	public void setMapping(Map<String, String> mapping) {
		this.mapping = mapping;
	}
	
	
}
