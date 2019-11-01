/*************************************************************************
	> File Name: TCPclient.cpp
	> Author: ylongtian
	> mail: ylongtian@126.com
	> Created Time: 2019年10月31日 星期四 21时57分34秒
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
	int sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1)
	{
		perror("套接字创建失败！");
		exit(1);
	}

	//绑定IP、端口
	struct sockaddr_in serv_addr;
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(PORT);
	connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	//向服务器发送数据
	char buffersend[BUF_SIZE]={0};
	printf("输入发送信息：");
	gets(buffersend);   //不推荐使用，这里用来测试粘包问题
	//fgets(buffersend,10,stdin);
	for(int i=0;i<3;++i)
	{
		write(sock,buffersend,strlen(buffersend));
	}
	//读取服务器返回的数据
	char bufferrecv[BUF_SIZE]={0};
	read(sock,bufferrecv,sizeof(bufferrecv));

	printf("接收返回的消息：%s\n",bufferrecv);

	close(sock);
	return 0;


}
