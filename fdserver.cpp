/*************************************************************************
	> File Name: fdserver.cpp
	> Author: ylongtian
	> mail: ylongtian@126.com
	> Created Time: 2019年11月01日 星期五 22时30分08秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define IP 127.0.0.1
#define PORT 9000
#define BUF_SIZE 1024

int main()
{
	//先检查文件是否存在
	const char *filename="send.mp3";
	FILE *fp=fopen(filename,"rb");//以二进制方式打开文件
	if(fp==NULL)
	{
		perror("文件打开失败！\n");
		exit(1);
	}
	
	//创建套接字
	int serv_sock=socket(AF_INET,SOCK_STREAM,0);
	if(serv_sock==-1)
	{
		perror("创建套接字失败！\n");
		exit(1);
	}

	//绑定IP、端口
	struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("IP");
	serv_addr.sin_port=htons(PORT);
	if(bind(serv_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
	{
		perror("绑定失败！ \n");
		exit(1);
	}

	listen(serv_sock,10);

	//接收客户端请求
	struct sockaddr_in clnt_addr;
	socklen_t clnt_size=sizeof(clnt_addr);
	int clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_size);
	if(clnt_sock==-1)
	{
		perror("接收请求失败 \n");
		exit(1);
	}
	
	//	循环发送数据，直到文件结束
	char buffer[BUF_SIZE]={0};
	int count;
	while((count=fread(buffer,1,BUF_SIZE,fp))>0)
	{
		send(clnt_sock,buffer,count,0);
	}
	shutdown(clnt_sock,SHUT_WR);//文件读取完毕，断开输出流，向客户端发送FIN包
	recv(clnt_sock,buffer,BUF_SIZE,0); //阻塞，等待客户端接收完毕
	fclose(fp);
	close(clnt_sock);
	close(serv_sock);
	return 0;
}
