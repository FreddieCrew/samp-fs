# samp-fs
Simple file system for SA-MP

# Open modes

| Name       | Description                    |
| ---------- | ------------------------------ |
| fs_append  | Open the file in append mode   |
| fs_io      | Open the file in I/O mode      |

# File functions

## fs_fcreate - Creates a file
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path where the file will be created  |
| openMode   | The mode that the file will be opened  |

## fs_fopen - Opens a file (W.I.P)
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path where the file will be opened  |
| openMode   | The mode that the file will be opened  |
| Work In Progress (W.I.P)  | This function is still being worked on, so I don't recommend using it for now |

## fs_fdel - Deletes a file
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path of the file to be deleted  |

## fs_fexists - Check if a file exists or not
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path of the file to be checked  |
| Returns    | 0 if the file does not exist, and 1 if the file exists |

## fs_count - Count how many files are in a folder
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path where the folder is located |
| Returns    | The number of files in the specified folder |

## fs_MoveFile - Moves a file from directory A to directory B
| Name       | Description                    |
| ---------- | ------------------------------ |
| path_from  | The path where the file is located  |
| path_to    | The path where the file will be moved to  |

## fs_fcopy - Copies a file from directory A to directory B
| Name       | Description                    |
| ---------- | ------------------------------ |
| path_from  | The path where the file is located  |
| path_to    | The path where the file will be copied to  |

# Directory functions

## fs_CreateDirectory - Creates a folder/directory in the desired path
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path where the directory will be created  |

## fs_Directory_Exists - Check if a folder/directory exists or not
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path where the directory is located  |
| Returns    | false if the directory does not exist, and true if the directory exists |

## fs_DeleteDirectory - Deletes a folder/directory
| Name       | Description                    |
| ---------- | ------------------------------ |
| path       | The path where the directory to be deleted is located  |
