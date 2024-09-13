#ifndef _DISK_UTILS_H
#define _DISK_UTILS_H

#include <stddef.h>
#include "../include/bitop.h"
#include <stdlib.h>
#include <math.h>

#define LIMITER 0x1
#define BYTE_SIZE 0x8 
#define MAX_LEN 0xA       ///MAX encode_size SEQ LEN.

#define MAX_FILE_NAME_LEN 16 

#define DISK_CAP_BLOCK_NO        0            // - 7
#define DISK_FREE_BLOCK_NO       8            // - 15
#define DISK_OCCU_BLOCK_NO       16           // - 23
#define DISK_FILE_COUNT_BLOCK_NO 24           // - 31
#define DISK_CURR_SIZE_BLOCK_NO  32           // - 39
#define DESK_CURR_DATA_BLOCK_NO  40           // - 47 
#define FIRST_SIZE_SEQ           48           // - 

// all attributies usable only for those vd which created using create_vdisk function of disk_utils 
typedef struct{
  FILE *vd;         // file pointer pointing to the disk image.
  size_t capacity;  // read firest 8 byte from the disk which indicate disk capacity.
  size_t free;
  size_t occupied;
  size_t curr_size_block_number;    //contain block index which is currently free to store size
  size_t curr_data_block_number;    //contain block index which is currently free to store data. 
  size_t file_count;              //number of file currently in the disk. 
} vdisk;

struct sequence{
  unsigned int arr[32];
  size_t bit_count;
  unsigned short counter:6;
};

typedef struct {
  void *buff;
  size_t size;
} dec_seq;
extern struct sequence seq;

/*
    create_vdisk : create the virtual disk of given lable or path of given ndiskb (n disk bytes).
    return true if disk creation is successful else false.
    NOTE: ASSERTION ENABLED, given path (char array) must not be NULL.
*/
bool create_vdisk(char *path, size_t ndiskb);

/*
    mount_vdisk : mount virtual disk image and return struct vdisk veriable which contain essential 
    disk attrib. , can only mount disk which created using create_vdisk function.
    ** At the end file pointer of vdisk will point to the first free size block where you can store
    the size of first file.
*/
vdisk mount_vdisk(char *path);

void print_disk_info(vdisk vd);

void set_seq(size_t num);

void* encode_size(size_t num, size_t *enc_seq_size);
size_t decode_size(void *bit_vec);
//to encode file size and actual file bytes, for size limiter = 0 and data actual bits seperated by 1.

size_t encode(void *res, size_t rnmemb, void *src, size_t snmemb);

dec_seq decode(void *src);

/*
  add_file: 
    parems: struct vdisk* , char* file_path
    returns bool variable true is insertion successied else false.
*/
bool add_file(vdisk *dsk, char *path);
/*
  update_disk:
    parems: vdisk *dsk.
    returns nothing.
  update_disk attributes, before using this method must update attr of struct vdisk.
  update in disk header.
*/
bool add_all_file(vdisk *dsk, char *path);
void update_disk(vdisk *dsk);


/*
  read_file:
    parems: struct vdisk, unsigned value indicating file number > 0
    returns char array.
*/



/*
  trim_fname:
    parems: char *destination , char *source
    return nothing.
    trim given string such that it removes all the path chars from the string.
*/
void trim_fname(char *dst, char *src);

/*
  get_file_name:
    parems: char *destination, vdisk dsk, size_t number_of_bytes_skip_from_EOF
    returns nothing.
    returns the file name of the file. 
*/
void get_file_name(char *dst, vdisk dsk, size_t skip_bytes);

/*
  list_file:
    parems: vdisk vd
    returns nothing
    print all the file present in given vdisk.
*/
void list_file(vdisk vd);


/*
    search_file_name:
      parems: vdisk dsk, char *file_name
      return signed long long value which indicate file size descluding file name size.
            rerun > 0 value if file exist.
            else return -1 if file does not exist.
            set file pointer at the beginning of the data.
*/
long long  search_file_name(vdisk dsk, char *file_name);


/*
  get_file:
    parems: vdisk disk, char *file_name
    returns nothing
    store given file in current directory if exist in vdisk.
*/
bool get_file(vdisk disk,  char *dst_name, char *file_name);


/*
  unmount_disk:
    parems: vdisk *dsk
    return nothing
    close all the open files.
*/
void unmount_disk(vdisk *dsk);

#endif //_DISK_UTILS_H
