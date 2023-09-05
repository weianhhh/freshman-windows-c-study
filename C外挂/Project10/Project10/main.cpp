#include <iostream>
#include <mysql/mysql.h>
#pragma comment("libmysql.lib")
int main() {
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    conn = mysql_init(nullptr);
    if (conn == nullptr) {
        std::cerr << "mysql_init failed" << std::endl;
        return 1;
    }

    if (mysql_real_connect(conn, "localhost", "username", "password", "database", 0, nullptr, 0) == nullptr) {
        std::cerr << "mysql_real_connect failed: " << mysql_error(conn) << std::endl;
        return 1;
    }

    if (mysql_query(conn, "SELECT * FROM your_table ORDER BY keyword_column DESC LIMIT 100000000")) {
        std::cerr << "mysql_query failed: " << mysql_error(conn) << std::endl;
        return 1;
    }

    res = mysql_store_result(conn);
    if (res == nullptr) {
        std::cerr << "mysql_store_result failed: " << mysql_error(conn) << std::endl;
        return 1;
    }

    int num_fields = mysql_num_fields(res);

    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < num_fields; i++) {
            if (row[i] != nullptr) {
                std::cout << row[i] << " ";
            }
            else {
                std::cout << "NULL ";
            }
        }
        std::cout << std::endl;
    }

    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
