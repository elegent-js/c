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
 #include <fcntl.h>
 #include <sys/stat.h>

 #define PORT 8080
 #define BUFFER_SIZE 8192

 // 判断当前文件类型，仅支持.html和.txt
 const char* get_mime_type(const char *path) {
    if (strstr(path, ".html")) return "text/html";
    if (strstr(path, ".txt")) return "text/plain";

    return "application/octet-stream";
 }

 void handle_request(int client_fd) {
    char buffer[BUFFER_SIZE] = {0};
    read(client_fd, buffer, sizeof(buffer) - 1);

    printf("=== Request ===\n%s\n", buffer);

    // 只解析第一行：GET /index.html HTTP/1.1
    char method[16], path[256];
    sscanf(buffer, "%s %s", method, path);

    // 只处理 GET 方法
    if (strcmp(method, "GET") != 0) {
        const char *err = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
        write(client_fd, err, strlen(err));
        close(client_fd);
        return;
    }

    // 默认路径为 /
    if (strcmp(path, "/") == 0) {
        strcpy(path, "/index.html");
    }

    // 去掉开头的 /
    char filepath[512] = "./www";
    strcat(filepath, path); // ./www/index.html

    // 检查文件是否存在
    if (access(filepath, F_OK) != 0) {
        const char *not_found =
            "HTTP/1.1 404 Not Found\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 45\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<html><body><h1>404 Not Found</h1></body></html>";
        write(client_fd, not_found, strlen(not_found));
        close(client_fd);
        return;
    }

    // 获取文件大小
    struct stat st;
    stat(filepath, &st);
    int filesize = st.st_size;

    // 打开文件读取
    int fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        close(client_fd);
        return;
    }

    // 构造响应头
    char header[512];
    snprintf(header, sizeof(header),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n"
        "\r\n",
        get_mime_type(filepath),
        filesize
    );

    write(client_fd, header, strlen(header));

    // 发送文件内容
    char file_buf[BUFFER_SIZE];
    int n;
    while ((n = read(fd, file_buf, sizeof(file_buf))) > 0) {
        write(client_fd, file_buf, n);
    }

    close(fd);
    close(client_fd);
}


 int main(int argc, char *argv[]) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 10);

    printf("Mini HTTP Server running on http://localhost:%d\n", PORT);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd >= 0) {
            handle_request(client_fd);
        }
    }

    return 0;
 }