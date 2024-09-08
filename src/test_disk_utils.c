/*
  support updated:
    add file one by one.
    can mount any disk which created using create_vdisk utility of vdisk_utils.h
    bug fixes.
*/
#include "../include/disk_utils.h"
#include "/usr/include/stdio.h"
#include <string.h>
int main(){
  
  //  char arr[] = NULL;
  // char arr[] = "\n";
/*
  char arr[] = "saurabh gajanan gade"; 
   memprint(arr, sizeof(arr));
   printf("\n");
   size_t size = sizeof(arr);
   seq.bit_count = 0;
   set_seq(size * 8);
   size_t byte_count = (seq.bit_count / 8) + !(!(seq.bit_count % 8));
   void *buff = malloc(byte_count);
   encode(buff, byte_count, arr, size);
   memprint(buff, byte_count);

   printf("\tDECODING... \n");

   dec_seq dec;
   dec = decode(buff);
   memprint(dec.buff, dec.size);
   printf("%s\n", (char*)dec.buff);
  // return 0;
*/
/*
  // create_vdisk("../disk.vd", 4 * 1024 * 1024); // create vdisk of size 4MBytes.
  vdisk dsk = mount_vdisk("../disk.vd");
  print_disk_info(dsk);

  //  return 0;

  add_file(&dsk, "../test/test_file1.txt");
  
  // add_file(&dsk, "../test/test_file2.txt");
  // add_file(&dsk, "../test/test_file3.txt");

// return 0;
  // add_file(&dsk, "../test/test_file4.txt");
  // add_file(&dsk, "../test/test_file_image1.jpg");
  
  // add_file(&dsk, "../test/test_file5.c");
  // add_file(&dsk, "../test/test_file_exe.out");
  printf("EVERYTHING WORKING DISK_UTILS\n");
  return 0;
  */
  // size_t size;
  // void *buff = encode_size(100, &size);
  // char name[MAX_FILE_NAME_LEN];
  // trim_fname(name, "../somedir/../../somedir/f.txt");
  // trim_fname(name, "file_name.txt");

  vdisk dsk = mount_vdisk("disk.vd");
  list_file(dsk);
  return 0;
}
