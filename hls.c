#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void _ls(const char *dir, int op_a, int op_l)
{
	struct dirent *d;
	DIR *dh = opendir(dir);
	if(!dh)
{
		if(errno == ENOENT)
{
			perror("Directory does not exist");
}
		else
{
			perror("Unabke to read directory");
}
		return;
}
	while((d = readdir(dh)) != NULL)
{
		if(!op_a && d->d_name[0] == '.') continue;
		printf("%s ", d->d_name);
		if(op_l) printf("\n");
}
	if(!op_l) printf("\n");
}

int main(int argc, const char *argv[])	
{ int op_a, op_l;
	char *p;

	if(argc == 1)
{
		_ls(".", 0, 0);
}
	else if(argc == 2)
{
		if(argv[1][0] == '-')
{
	op_a = 0;
 op_l = 0;
 *p = (argv[1]+1);
			while(*p) 
{
				if(*p == 'a') op_a = 1;
				else if(*p == 'l') op_l = 1;
				else {
					perror("unknown option error");
					exit(0);
}
				p++;
}
			_ls(".", op_a, op_l);
}
		else 
{
			_ls(argv[1], 0, 0);
}

}
	else if(argc == 3) 
{
		if(argv[1][0] != '-')
{
			perror("incorrect usage error");
			exit(0);
}
		op_a = 0;
 op_l = 0;
 *p = (argv[1]+1);
		while(*p)
{
			if(*p == 'a') op_a = 1;
			else if(*p == 'l') op_l = 1;
			else
{
				perror("Unknown option error");
				exit(0);
}
			p++;
}
		_ls(argv[2], op_a, op_l);
}
	return 0;
}

