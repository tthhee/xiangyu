package fxy.oop.server;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.util.Date;

import fxy.oop.serverUtil.CloseUtil;

public class Response {
	public static final String CRLF="\r\n";
	public static final String BLANK=" ";
	private StringBuilder Head;
	private int len;   //���ĳ���
	private StringBuilder contents;
	private Socket client;
	private BufferedWriter bw;
	
	Response()
	{
		
		Head = new StringBuilder();
		contents = new StringBuilder();
		len = 0;
	}
	Response(OutputStream os)
	{
		this();
		bw = new BufferedWriter(new OutputStreamWriter(os));
	}
	
	Response(Socket s) throws IOException
	{
		this(s.getOutputStream());
	}
	
	private void ResponseHead(int code)
	{
		
		//��Ӧͷ
		Head.append("HTTP/1.1").append(BLANK).append(code).append(BLANK);
		switch(code)
		{
		case 200:
			Head.append("OK");
			break;
		case 404:
			Head.append("NOT FOUND");
			break;
		case 500:
			Head.append("SERVER ERROR");
			break;
		default:
			break;
		}
		Head.append(CRLF);
		Head.append("Server:Xiangyu Server/0.0.1").append(CRLF);
		Head.append("Date:").append(new Date()).append(CRLF);
		Head.append("Content-type:text/html;charset=GBK").append(CRLF);
		//���ĳ��ȣ� �ֽڳ���
		Head.append("Content-Length:").append(len).append(CRLF);
		Head.append(CRLF);
	}
	
	public Response print(String msg)
	{
		contents.append(msg);
		len += msg.getBytes().length;
		return this;
	}
	public Response println(String msg)
	{
		contents.append(msg).append(CRLF);
		len += (msg+CRLF).getBytes().length;
		return this;
	}
	public void PushToClient(int code) throws IOException
	{
		ResponseHead(code);
		bw.append(Head);
		bw.append(contents);
		bw.flush();
		CloseUtil.closeIO(bw);
	}
	
//	public void OutputFile(Socket client, String filename) throws FileNotFoundException
//	{
//		File file = new File(filename);
//		FileOutputStream in = new FileOutputStream(file);
//	}

}
