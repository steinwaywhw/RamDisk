#include "fs.h"

int main () {

	fs_t *fs = init_fs ();
	fs_mk (fs, "/hello", "reg");

	int index = inode_lookup_full (fs->super_block, "/hello");

	char buffer[4] = "HHH";
	fs_write (fs, index, 0, buffer, 4);
	fs_read (fs, index, 0, buffer, 4);

	

	destroy_fs (fs);
}