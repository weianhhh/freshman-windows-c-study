#include <stdio.h>
#include <string.h>
#include <algorithm>
int main()
{

	return 0;
}
void parefile(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (!fp)
	{
		printf("%s open failed:%s\n",filename,strerror(errno));
		return;
	}
	char buf[BUFSIZ];
	while (!feof(fp)) 
	{
		if (fgets(buf, BUFSIZ, fp))
			break;
		printf("%s\n",buf);
	}
	fclose(fp);

}