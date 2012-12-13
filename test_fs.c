#include "fs.h"
#include <string.h>
#include <stdio.h>
#define TEST_SIZE LOC_LIMIT_DOUBLE_INDIRECT

int main () {

	fs_t *fs = init_fs ();


	// int i;
	// for (i = 0; i < 1025; i++) {
	// 	char buffer[20];
	// 	sprintf (buffer, "/file%2d", i);
	// 	int status = fs_mk (fs, buffer, "reg");
	// 	if (status < 0)
	// 		printf ("%d\n", i);
	// }

	// inode_shrink (fs->super_block, 0, 2048);

	// for (i = 0; i < 1025; i++) {
	// 	char buffer[20];
	// 	sprintf (buffer, "/file%2d", i);
	// 	int status = fs_rm (fs, buffer);
	// 	if (status < 0)
	// 		printf ("%d\n", i);
	// }
	
	fs_mk (fs, "/hello", "reg");

	int index = inode_lookup_full (fs->super_block, "/hello");

	char buffer[TEST_SIZE];
	int i = 0;
	for (i = 0; i < TEST_SIZE; i++) {
		buffer[i] = i % 10 + '0';
	}

	fs_write (fs, index, 0, buffer, TEST_SIZE);
	// memset (buffer, 0, TEST_SIZE);
	// fs_read (fs, index, 0, buffer, TEST_SIZE);

	// printf ("%d", strlen(buffer));

	inode_shrink (fs->super_block, index, 0);

	destroy_fs (fs);
}