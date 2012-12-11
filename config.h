
#define BLOCK_SIZE_IN_B 	256
#define INODE_SIZE_IN_B		64
#define DISK_SIZE_IN_KB 	2048

#define LOC_NR_OF_DIRECT			8
#define LOC_NR_OF_SINGLE_INDIRECT	1
#define LOC_NR_OF_DOUBLE_INDIRECT	1
#define LOC_POINTER_PER_BLOCK		(BLOCK_SIZE_IN_B / sizeof (void *))
#define LOC_LIMIT_DIRECT			(LOC_NR_OF_DIRECT * BLOCK_SIZE_IN_B)
#define LOC_LIMIT_SINGLE_INDIRECT 	(LOC_LIMIT_DIRECT + LOC_NR_OF_SINGLE_INDIRECT * LOC_POINTER_PER_BLOCK * BLOCK_SIZE_IN_B)
#define LOC_LIMIT_DOUBLE_INDIRECT	(LOC_LIMIT_SINGLE_INDIRECT + LOC_NR_OF_DOUBLE_INDIRECT * LOC_POINTER_PER_BLOCK * LOC_POINTER_PER_BLOCK * BLOCK_SIZE_IN_B)
#define LOC_SIZE_1_LEVEL			BLOCK_SIZE_IN_B
#define LOC_SIZE_2_LEVEL			(BLOCK_SIZE_IN_B * LOC_POINTER_PER_BLOCK)
#define LOC_SIZE_3_LEVEL			(BLOCK_SIZE_IN_B * LOC_POINTER_PER_BLOCK * LOC_POINTER_PER_BLOCK)

#define OFFSET_SUPER_BLOCK	0
#define OFFSET_INODE_ARRAY	1
#define OFFSET_BLOCK_BITMAP	257
#define OFFSET_FREE_BLOCK	261
#define OFFSET_LIMIT		DISK_SIZE_IN_KB * 1024 / BLOCK_SIZE_IN_B


#define INODE_TYPE_SIZE				4
#define INODE_TYPE_DIR				"dir"
#define INODE_TYPE_REG				"reg"
#define INODE_ARRAY_SIZE_IN_BLOCK	(OFFSET_BLOCK_BITMAP - OFFSET_INODE_ARRAY)
#define INODE_ARRAY_SIZE 			(BLOCK_SIZE_IN_B * INODE_ARRAY_SIZE_IN_BLOCK / INODE_SIZE_IN_B)
#define INODE_ARRAY_INDEX_LIMIT		(INODE_ARRAY_SIZE - 1)
#define INODE_ROOT_INDEX			0

#define MAX_NR_OF_FILES		INODE_ARRAY_SIZE
#define MAX_FILE_COMPONENT	13
#define MAX_FILE_FULL		256
#define MAX_FILE_SIZE		LOC_LIMIT_DOUBLE_INDIRECT

#define PATH_DELIMITER_CHAR	'/'
