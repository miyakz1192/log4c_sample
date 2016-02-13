#include <stdio.h>
#include <unistd.h>

#include "log4c.h"

int main(int argc, char** argv){
	int ret = 0;
	int i   = 0;
	char buf[256];
	log4c_category_t* mycat = NULL;
  
	ret = log4c_init();
	if (ret != 0) {
		printf("log4c_init() failed\n");
		return ret;
	}

	mycat = log4c_category_get("log4c.examples.sample");

        for(i = 0 ; i < 10240 ; i ++ ){
		sprintf(buf, "logging %d", i);
		printf("%s\n", buf);		
		
		log4c_category_log(mycat, LOG4C_PRIORITY_INFO, buf);
		//log4c_category_log(mycat, LOG4C_PRIORITY_FATAL, "This is test log!");
		//log4c_category_log(mycat, LOG4C_PRIORITY_ALERT, "This is test log!");
		//log4c_category_log(mycat, LOG4C_PRIORITY_CRIT, "This is test log!");
		//log4c_category_log(mycat, LOG4C_PRIORITY_ERROR, "This is test log!");
		//log4c_category_log(mycat, LOG4C_PRIORITY_WARN, "This is test log!");
		//log4c_category_log(mycat, LOG4C_PRIORITY_NOTICE, "This is test log!");
		//log4c_category_log(mycat, LOG4C_PRIORITY_DEBUG, "This is test log!");
		//log4c_category_log(mycat, LOG4C_PRIORITY_TRACE, "This is test log!");
		//sleep(1);
	}

	ret = log4c_fini();
	if (ret != 0) {
		printf("log4c_fini() failed\n");
		return ret;
	}

	return 0;
}
