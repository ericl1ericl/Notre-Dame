/*
   Main program for the virtual memory project.
   Make all of your modifications to this file.
   You may add or rearrange any code or data as you need.
   The header files page_table.h and disk.h explain
   how to use the page table and disk interfaces.
   */

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <queue>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include "page_table.h"
#include "disk.h"
#include "program.h"
#include <climits>

using namespace std;

int algorithmCode = 0;
int framesInTable = 0;  //keep track of how many pages have r/w bits set
char * phys_mem_pointer;
int count = 0;

int actualPageFaults = 0;
int syntheticPageFaults = 0;

int diskReads = 0;
int diskWrites = 0;

struct disk * diskPointer;

vector<int> occur; 
vector<tuple<int, int>> frameStatus;
queue<int> frameQ;
stack<int> frameS;

void page_fault_handler(struct page_table *pt, int page)
{
  int theframe = 0;
  int thebits = INT_MAX;
  int targetFrame;
  /*if(page >= global_pages){
    exit(1);
    }*/   

  page_table_get_entry(pt, page, &theframe, &thebits);

  cout << "Value of thebits=" << thebits << "\n";
  if (thebits == INT_MAX) {
    cerr << "Error calling page_table_get_entry: thebits not updated.\n";
  }

  cout << "ENTERING PAGE FAULT HANDLER WITH page: " << page << " thebits: " << thebits << endl;

  if (thebits == 0) { // if there are no frames in this entry, bits == 0 so we have to read
    cout << "framesintable: " << framesInTable << " pt_get_nframes: " << page_table_get_nframes(pt) << endl;
    if (framesInTable < page_table_get_nframes(pt)) {    //intent: put all pages in page table
      targetFrame = framesInTable;
      cout << "I'm adding page: " << page << " to frame: " << targetFrame << ", no conflict, no eviction" << endl;
      page_table_set_entry(pt, page, targetFrame, PROT_READ); //map page 0 -> frame 0
      disk_read(diskPointer, page, &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
      diskReads++;

      frameStatus[targetFrame] = make_tuple(page, PROT_READ);
      framesInTable++;
      // add the frame to the frame queue (used in fifo)
      frameQ.push(targetFrame);
      frameS.push(targetFrame);
    } 
    else {
      switch(algorithmCode) {
        case 0: //RAND
          targetFrame = rand() % page_table_get_nframes(pt); //get a random frame number to evict

          // write to disk and set the new frame table entry
          page_table_get_entry(pt, page, &theframe, &thebits);
          
          disk_write(diskPointer, get<0>(frameStatus[targetFrame]), &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);

          diskWrites++;
          page_table_set_entry(pt, get<0>(frameStatus[targetFrame]), 0, 0);

          // change the frame
          disk_read(diskPointer, page, &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
          diskReads++;
          page_table_set_entry(pt, page, targetFrame, PROT_READ);
          printf("frame changed: %i, total count: %i\n", targetFrame, framesInTable);
          frameStatus[targetFrame] = make_tuple(page, PROT_READ);
          break;

        case 1: // FIFO
          cout << "queue size: " << frameQ.size() << endl;
          targetFrame = frameQ.front(); // the frame that should be evicted is the first frame in the queue 
          frameQ.pop(); // remove first element from queue

          cout << "target frame from queue: " << targetFrame << endl;
          // write to disk, update page table
          disk_write(diskPointer, get<0>(frameStatus[targetFrame]), &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
          diskWrites++;
          page_table_set_entry(pt, get<0>(frameStatus[targetFrame]), 0, 0);

          // update the page table
          disk_read(diskPointer, page, &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
          diskReads++;
          page_table_set_entry(pt, page, targetFrame, PROT_READ);

          frameStatus[targetFrame] = make_tuple(page, PROT_READ); // add the new frame to the frame table 
          frameQ.push(targetFrame);    
          break;
        case 2: // LIFO -- custom algorithm
          //get rid of this when I figure it out
          targetFrame = rand() % page_table_get_nframes(pt);
          occur[targetFrame] += 1;
         
          for (int j = 0; j < occur.size(); j++) {
              cout << j << " : " << occur[j];
              
          }
          cout << "Occur[targetframe] " << occur[targetFrame] << endl;
                   
          for (int i = 0; i < occur.size(); i++) {
            if (occur[i] < occur[targetFrame]) {
              targetFrame = i;
            }
          }
          
          
          cout << "new occur: " << occur[targetFrame] << endl;

          //write to disk
          disk_write(diskPointer, get<0>(frameStatus[targetFrame]), &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
          diskWrites++;
          page_table_set_entry(pt, get<0>(frameStatus[targetFrame]), 0,0);

          //update the page table
          disk_read(diskPointer, page, &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
          diskReads++;
          page_table_set_entry(pt, page, targetFrame, PROT_READ);

          frameStatus[targetFrame] = make_tuple(page, PROT_READ);


          /*			cout << "queue size: " << frameS.size() << endl;
          //cout << actualPageFaults + syntheticPageFaults << " % " << 2*frameS.size() << " = " << ((actualPageFaults+syntheticPageFaults)%(2*frameS.size())) << endl;
          targetFrame = frameS.top();
          if ((actualPageFaults+syntheticPageFaults)%(2*frameS.size()) == 0) {
          cout << "popping off" << endl;
          for (int i = 0; i < (int)frameS.size(); i++) {
          frameS.pop();
          }
          }
          else {
          frameS.pop();
          }
          //					targetFrame = frameS.top(); // the frame that should be evicted is the last frame in the stack

          cout << "target frame from queue: " << targetFrame << endl;

          // write to disk, update page table
          disk_write(diskPointer, get<0>(frameStatus[targetFrame]), &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
          diskWrites++;
          page_table_set_entry(pt, get<0>(frameStatus[targetFrame]), 0, 0);

          // update the page table
          disk_read(diskPointer, page, &phys_mem_pointer[BLOCK_SIZE * (targetFrame)]);
          diskReads++;
          page_table_set_entry(pt, page, targetFrame, PROT_READ);

          frameStatus[targetFrame] = make_tuple(page, PROT_READ); // add the new frame to the frame table 
          frameS.push(targetFrame);    
          */

          break;
      }
    }   
    count++; 
    page_table_print(pt);
    actualPageFaults++;
  } 
  else if (thebits & PROT_READ) {
    //cout << "ADDING PROT_WRITE BIT\n";
    page_table_set_entry(pt, page, theframe, PROT_READ|PROT_WRITE);
    //  diskWrites++;	
    get<1>(frameStatus[theframe]) = PROT_READ|PROT_WRITE;
    syntheticPageFaults++;
  } 
  else {
    cout << "KEVIN SAID THIS IS REALLY BAD" << endl;
    exit(1);
  }

}

void usage() {
  printf ("use: virtmem <npages> <nframes> <rand|fifo|lru|custom> <sort|scan|focus>\n");
  exit (1);
}

int main(int argc, char *argv[])
{
  if (argc != 5) {
    usage();
  }

  int npages = atoi(argv[1]);
  int nframes = atoi(argv[2]);
  const char *program = argv[4];
  const char *algorithm = argv[3];

  if ((nframes < 3) || (npages < 1)) {
    usage();
  }

  occur.resize(npages, 0);

  frameStatus.resize(nframes, make_tuple(0, 0));
  //	srand(178747);

  struct disk *disk = disk_open("myvirtualdisk", npages);
  if (!disk) {
    fprintf(stderr, "couldn't create virtual disk: %s\n",
        strerror(errno));
    return 1;
  }

  diskPointer = disk;

  struct page_table *pt =
    page_table_create(npages, nframes, page_fault_handler);
  if (!pt) {
    fprintf(stderr, "couldn't create page table: %s\n",
        strerror(errno));
    return 1;
  }

  char *virtmem = page_table_get_virtmem(pt);
  char *physmem = page_table_get_physmem(pt);

  phys_mem_pointer = physmem;   

  if (!strcmp(algorithm, "rand")) {
    algorithmCode = 0;
  }
  else if (!strcmp(algorithm, "fifo")) {
    algorithmCode = 1;
  }
  else if(!strcmp(algorithm, "custom")) {
    algorithmCode = 2;
  }
  else {
    fprintf(stderr, "unknown algorithm: %s\n", argv[3]);
    return 1;
  }


  if (!strcmp(program, "sort")) {
    sort_program(virtmem, npages * PAGE_SIZE);

  } else if (!strcmp(program, "scan")) {
    scan_program(virtmem, npages * PAGE_SIZE);

  } else if (!strcmp(program, "focus")) {
    focus_program(virtmem, npages * PAGE_SIZE);

  } else {
    fprintf(stderr, "unknown program: %s\n", argv[3]);
    return 1;
  }

  cout << "Final Numbers:" << endl;
  cout << "\tsynthetic page faults: " << syntheticPageFaults << endl;
  cout << "\tactual page faults: " << actualPageFaults << endl;
  cout << "\ttotal page faults: " << syntheticPageFaults + actualPageFaults << endl;
  cout << "\tdisk reads: " << diskReads << endl;
  cout << "\tdisk writes: " << diskWrites << endl;


  page_table_delete(pt);
  disk_close(disk);

  return 0;
}
