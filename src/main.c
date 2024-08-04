#include "../include/header.h"


const char* get_Filetype(const char* filename) {
  char* ext = strrchr(filename,'.');
  if (!ext || ext == filename) return "Others";
  ext++; //to skip the . from the filename!
  if (strcmp(ext, "jpg") == 0 || strcmp(ext, "png") == 0) return "Images"; 
  if (strcmp(ext, "pdf") == 0 || strcmp(ext, "doc") == 0 || strcmp(ext, "txt") == 0) return "Documents";  
  if (strcmp(ext, "mp4") == 0 || strcmp(ext, "mkv") == 0) return "Videos";  
  return "Others";
}

void initialize_DIR(const char* dirname) {
  struct stat st = {0};
  if(stat(dirname, &st) == -1) {
    mkdir(dirname, 0700);
  }
}

void move_File(const char* filename, const char* destDIR) {
  char destPATH[PATH_MAX];
  snprintf(destPATH, sizeof(destPATH), "%s/%s", destDIR, filename);
  if (rename(filename, destPATH) != 0) { 
      perror("rename");  
  }
}

void organizeFiles(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;

    if (dir == NULL) {
        perror("opendir");
        return;
    }

    chdir(dirPath);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            const char *fileType = get_Filetype(entry->d_name);
            initialize_DIR(fileType);
            move_File(entry->d_name, fileType);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {

  if(argc < 1) {
   printf("Usage: <./filename> <directory path> if no path specified uses the current directory to organise!");
  }
   const char *dirPath = (argc > 1) ? argv[1] : ".";  
    organizeFiles(dirPath);  
    printf("Files organized successfully.\n"); 
    return 0;
}