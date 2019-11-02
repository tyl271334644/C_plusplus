/*************************************************************************
	> File Name: fdclient.cpp
	> Author: ylongtian
	> mail: ylongtian@126.com
	> Created Time: 2019年11月01日 星期五 22时30分19秒
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
	//输入文件名，看文件是否能够创建成功
	char filename[100]={0};
	printf("输入文件名！\n");
	fgets(filename,100,stdin);
	FILE *fp=fopen(filename,"wb");
	if(fp==NULL)
	{
		printf("打开文件失败！\n");
		exit(1);
	}
	
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1)
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
   connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	//循环接收数据，直到文件传输完毕
	char buffer[BUF_SIZE]={0};
	int count;
	while((count=recv(sock,buffer,BUF_SIZE,0))>0)
	{
		fwrite(buffer,count,1,fp);
	}
	printf("文件接收成功！\n");

	fclose(fp);
	close(sock);

	return 0;
}
