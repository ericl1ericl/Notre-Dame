
#include "fs.h"
#include "disk.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define FS_MAGIC           0xf0f03410
#define INODES_PER_BLOCK   128
#define POINTERS_PER_INODE 5
#define POINTERS_PER_BLOCK 1024

struct fs_superblock {
	int magic;
	int nblocks;
	int ninodeblocks;
	int ninodes;
};

struct fs_inode {
	int isvalid;
	int size;
	int direct[POINTERS_PER_INODE];
	int indirect;
};

union fs_block {
	struct fs_superblock super;
	struct fs_inode inode[INODES_PER_BLOCK];
	int pointers[POINTERS_PER_BLOCK];
	char data[DISK_BLOCK_SIZE];
};

int fs_format()
{
	return 0;
}

void fs_debug()
{
	union fs_block block;

	disk_read(0,block.data);

  printf("superblock:\n");
  
  if (block.super.magic == FS_MAGIC) {
    printf("    magic number is valid\n");
  } else {
    printf("    magic number is NOT valid\n"); // TODO add handler for invalid file system maybe
  }
	
	printf("    %d blocks on disk\n",block.super.nblocks);
	printf("    %d inode blocks\n",block.super.ninodeblocks);
	printf("    %d total inodes\n",block.super.ninodes);

  for (int i = 0; i < block.super.ninodes; i++) {
    int inodeblock = (i / INODES_PER_BLOCK) + 1;
    int inodeinblockindex = i % INODES_PER_BLOCK;

    union fs_block inode;
    disk_read(inodeblock, inode.data);

    if (inode.inode[inodeinblockindex].isvalid) {
      printf("    inode %d:\n", i);
      printf("    size: %d bytes\n", inode.inode[inodeinblockindex].size);
    }

  }
}

int fs_mount()
{
	// if the magic number is invald, fail because disk is not formatted/contains invalid data
	return 0;
}

int fs_create()
{
	return 0;
}

int fs_delete( int inumber )
{
	return 0;
}

int fs_getsize( int inumber )
{
	fs_block block;
	int b; // block for inode
	if(inumber > block.super.ninodes){
		printf("inode too large\n");
		exit(1);
	}

	b = INODEBLOCK(inumber);
	disk_read(b, block.data);
	int bVal = inumber % INODES_PER_BLOCK;
	*inode = block.inode[bVal];

	if(inode.isvald != NON_VALID)
		return inode.size;
	return -1;
}

int fs_read( int inumber, char *data, int length, int offset )
{
	return 0;
}

int fs_write( int inumber, const char *data, int length, int offset )
{
	return 0;
}
