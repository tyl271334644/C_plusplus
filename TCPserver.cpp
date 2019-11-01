/*************************************************************************
	> File Name: TCPserver.cpp
	> Author: ylongtian
	> mail: ylongtian@126.com
	> Created Time: 2019年10月31日 星期四 21时11分11秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define BUF_SIZE 100

int main()
{
	int res;
	//创建套接字
	int serv_sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(serv_sock==-1)
	{
		perror("创建套接字失败！");
		exit(1);
	}

	//绑定IP、端口
	struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(PORT);

	//绑定
	if(bind(serv_sock,(struct sockaddr*)
				&serv_addr,sizeof(serv_addr))==-1)
	{
		perror("绑定失败！");
		exit(1);
	}	

	//监听
	res=listen(serv_sock,10);
	if(res==-1)
	{
		perror("设置监听模式失败！");
		exit(1);
	}
	

	//接收客户端请求
	struct sockaddr_in clnt_addr;
	socklen_t clnt_size=sizeof(clnt_addr);
	int clnt_sock=accept(serv_sock,(struct sockaddr*)&clnt_addr,&clnt_size);
	if(clnt_sock==-1)
	{
		perror("接收请求失败！");
		exit(1);
	}

	sleep(10);
	
	//接收客户端消息原样返回
	char buffer[BUF_SIZE]={0};
	read(clnt_sock,buffer,sizeof(buffer));
	printf("服务端接收到的消息：%s\n",buffer);
	write(clnt_sock,buffer,sizeof(buffer));

	close(clnt_sock);
	close(serv_sock);
	return 0;
}
