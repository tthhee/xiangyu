package fxy.oop.server;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.util.Date;

/**
 * 封装响应信息
 * @author ASD
 *
 */
public class Response {

	
	public static final String CRLF = "\r\n";
	public static final String BLANK = " ";
	
	private BufferedWriter bw;
	//存储头信息
	private StringBuilder headInfo;
	//存储正文长度
	int len;
	private StringBuilder content;
	
	
	public Response()
	{
		headInfo = new StringBuilder();
		content = new StringBuilder();
		len = 0;
	}
	
	public Response(OutputStream os)
	{
		this();
		bw = new BufferedWriter(new OutputStreamWriter(os));
	}
	
	public Response(Socket client)
	{
		this();
		try {
			bw = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
		} catch (IOException e) {
			headInfo = null;
		}
	}
	
	public Response print(String info)
	{
		content.append(info);
		len += info.getBytes().length;
		return this;
	}
	
	public Response println(String info)
	{
		content.append(info).append(CRLF);
		len += (info + CRLF).getBytes().length;
		return this;
	}
	
	/**
	 * 构建信息头
	 * @param code
	 */
	private void createHeadInfo(int code)
	{
		headInfo.append("HTTP/1.1").append(BLANK).append(code).append(BLANK);
		switch(code)
		{
		case 200:
			headInfo.append("OK");
			break;
		case 404:
			headInfo.append("NOT FOUND");
			break;
		case 500:
			headInfo.append("SERVER ERROR");
			break;
		}
		headInfo.append(CRLF);
		//响应头
		headInfo.append("Server: fxy Server/0.0.1").append(CRLF);
	//	headInfo.append("Date:").append(new Date()).append(CRLF);
		headInfo.append("Content-type: text/html;charset=GBK").append(CRLF);
		//正文长度
		headInfo.append("Content-Length: ").append(len).append(CRLF);
		//正文
		headInfo.append(CRLF);
	}
	
	public void pushToClient(int code) throws IOException
	{
		if(null == headInfo)
		{
			code = 500;
		}
		createHeadInfo(code);
		//头信息加分隔符
		bw.append(headInfo.toString());
		bw.append(content.toString());
		bw.flush();
	}
	
	public void close() throws IOException
	{
		bw.close();
	}
}
