/**
 * mini http web server 实现
 * 
 * 用到的技术：
 * 阶段一：
 * 1）使用 TCP  Socket监听端口
 * 2）能响应浏览器请求并返回固定内容： hello world
 * 
 * 阶段二：
 * 1）解析 GET请求 URL
 * 2）根据请求返回对应 HTML文件（如：index.html）
 * 
 * 阶段三：
 *  1）使用fork()或（pthread)处理多个连接
 * 
 * 阶段四：
 *  1）文件不存在时返回404
 *  2）根据扩展名设置Content-Type
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <netinet/in.h>

 #define PORT 8080

 int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[4096];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(1);
    } 

    // 2. 设置地址信息
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // 3. 绑定端口
    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // 4. 监听端口
    if (listen(server_fd, 10) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Mini HTTP Server running on port %d...\n", PORT);

    while (1) {
        // 5. 等待连接
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // 6. 读取请求
        read(client_fd, buffer, sizeof(buffer) - 1);
        printf("Received request:\n%s\n", buffer);

        // 7. 返回固定响应
        const char *response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 13\r\n"
            "Connection: close\r\n"
            "\r\n"
            "Hello, world";

        write(client_fd, response, strlen(response));
        close(client_fd); // 关闭连接
    }

    return 0;
 }