# samp-fs
Simple file system for SA-MP

## Copy modes

| Name                  | Description                                                    |
| --------------------- | -------------------------------------------------------------- |
| fs_none               | Copies the file in default mode                                |
| fs_skip_existing      | Skips the copy process if a file with the same name exists in the path |
| fs_overwrite_existing  | Overwrites the existing file with the new one                  |
| fs_update_existing    | Updates the previous file in the path if a file with the same name exists |
| fs_recursive          | Recursively copies subdirectories and their files             |
| fs_copy_symlinks      | Copies symbolic links (e.g., Windows Shortcuts) without following the link target |
| fs_skip_symlinks       | Skips symbolic links (e.g., Windows Shortcuts)                 |

## File functions

### fs_fcreate - Creates a file

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path       | The path where the file will be created  |

### fs_fexists - Check if a file exists or not

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path       | The path of the file to be checked   |
| Returns    | 0 if the file does not exist, and 1 if the file exists |

### fs_count - Count how many files are in a folder

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path       | The path where the folder is located |
| Returns    | The number of files in the specified folder |

### fs_MoveFile - Moves a file from directory A to directory B

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path_from  | The path where the file is located   |
| path_to    | The path where the file will be moved to |

### fs_fcopy - Copies a file from directory A to directory B

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path_from  | The path where the file is located   |
| path_to    | The path where the file will be copied to |
| CopyMode   | The mode that the file will be copied  |

## Directory functions

### fs_CreateDirectory - Creates a folder/directory in the desired path

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path       | The path where the directory will be created  |

### fs_Directory_Exists - Check if a folder/directory exists or not

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path       | The path where the directory is located   |
| Returns    | false if the directory does not exist, and true if the directory exists |

### fs_DeleteDirectory - Deletes a folder/directory

| Name       | Description                         |
| ---------- | ----------------------------------- |
| path       | The path where the directory to be deleted is located  |
