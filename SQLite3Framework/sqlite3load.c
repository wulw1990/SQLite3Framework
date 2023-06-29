//
//  sqlite3load.c
//  SQLite3Framework
//
//  Created by MacBook Air on 2023/6/29.
//

#include "sqlite3load.h"
#include <stdio.h>


int my_sqlite_test(void) {
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open(":memory:", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n",
        sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    rc = sqlite3_enable_load_extension(db, 1);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot enable LOAD EXTENSION: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    rc = sqlite3_load_extension(db, "/path/to/your/extension.so", 0, &err_msg);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot load extension: %s\n",
                err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    }
    
    // Use the extension...
    
    sqlite3_close(db);
    
    return 0;
}
