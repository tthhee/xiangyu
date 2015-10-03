package fxy.oop.server;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Request {
	
	public static final String CRLF = "\r\n";
	//����ʽ
	private String method;
	//������Դ
	private String url;
	//�������
	private Map<String, List<String>> parameterMapValues;
	
	private InputStream is;
	//������Ϣ
	private String RequestInfo;
	
	private Request()
	{
		method = "";
		url = "";
		parameterMapValues = new HashMap<String, List<String>>();
		RequestInfo = "";
	}
	public Request(InputStream is)
	{
		this();
		this.is = is;
		
		try {
			byte[] data = new byte[20480];
			int len;
			len = is.read(data);
			RequestInfo = new String(data, 0, len);
		} catch (IOException e) {
			return;
		}
		//����������Ϣ
		parseRequestInfo();
	}
	/*
	 * ===================================
	 * ����������Ϣ
	 * 
	 */
	public void parseRequestInfo()
	{
		if(null == RequestInfo || (RequestInfo.trim().equals("")))
		{
			return;
		}
		 /* ================================
		 * ����Ϣ�����зֽ��������ʽ�� ����·���� ���������get���ܴ��ڣ�
		 * �磺GET /index.html?name=123&pwd=5456 HTTP/1.1
		 * =================================
		 */
		String parameter = "";
		String firstline = RequestInfo.substring(0, RequestInfo.indexOf(CRLF));
		int index = firstline.indexOf("/");
		this.method = firstline.substring(0, index).trim();
		String urlStr = firstline.substring(index, firstline.indexOf("HTTP/")).trim();
		if(this.method.equalsIgnoreCase("post"))
		{
			this.url = urlStr;
			parameter = RequestInfo.substring(RequestInfo.lastIndexOf(CRLF));
		}else if(this.method.equalsIgnoreCase("get"))
		{
			if(urlStr.contains("?"))
			{
				String[] urlArray = urlStr.split("\\?");
				this.url = urlArray[0];
				parameter = urlArray[1];
				
			}
			else
			{
				this.url = urlStr;
			}
		}
		
		if(parameter.equals(""))
		{
			return;
		}
		
		//�����������װ��Map��
	//	this.parameterMapValues
		parseParams(parameter);	
	}
	
	private void parseParams(String paramString)
	{
		//�ָ��ַ���
		StringTokenizer token = new StringTokenizer(paramString, "&");
		while(token.hasMoreTokens())
		{
			String keyValue = token.nextToken();
			String[] keyValues = keyValue.split("=");
			if(keyValues.length == 1)
			{
				keyValues = Arrays.copyOf(keyValues, 2);
				keyValues[1] = null;
			}
			String key = keyValues[0].trim();
			String value = null==keyValues[1]?null:decode(keyValues[1].trim(),"gbk");
			if(!parameterMapValues.containsKey(key))
			{
				parameterMapValues.put(key, new ArrayList<String>());
			}
			List<String> values = parameterMapValues.get(key);
			values.add(value);
		}
	}
	
	private String decode(String value, String code)
	{
		try {
			return java.net.URLDecoder.decode(value, code);
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	/*
	 * ����ҳ���name��ȡ��Ӧ�Ķ��ֵ
	 */
	public String[] getParameterValues(String name)
	{
		List<String> values = null;
		if((values = parameterMapValues.get(name))==null)
		{
			return null;
		}else
		{
			return values.toArray(new String[0]);
		}
	}
	
	/*
	 * ����ҳ���name��ȡ��Ӧ��1��ֵ
	 */
	public String getParameter(String name)
	{
		String[] value = getParameterValues(name);
		if(null == value)
		{
			return null;
		}else
		{
			return value[0];
		}
	}
	public String getUrl() {
		return url;
	}
	public void setUrl(String url) {
		this.url = url;
	}
}
