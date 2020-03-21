# SoalShiftSISOP20_modul2_T14

# Kelompok T14
- <strong>Fancista Syarif Hidayatullah    05311840000027 </strong>
- <strong>Agnes Lesmono                   05311840000044 </strong>


#1 [Source](https://github.com/lumbricina/SoalShiftSISOP20_modul2_T14/blob/master/soal1/soal1.c)

```
#define max_seconds 60
#define max_minutes 60
#define max_hours 24
#define max_days_week 8
#define max_days_months 32
#define max_months 12
#define INVALID_INSTANT ((time_t) -1)
#define date_format "%Y-%m-%d_%H:%M:%S"
```
Define sama seperti mendeklarasikan jadi dideklarasikan nilai maksimal detik = 60, menit = 60, jam = 24, hari dalam seminggu = 8, hari   bulan = 32, bulan = 12. Jika time_t – 1 juga akan invalid_instant.
Date format yang dideklarasikan : YEAR MONTH DAY HOUR MINUTE SECOND

```
#ifdef cron_test_malloc
static int cronalloc = 0;
static int crontotalalloc = 0;
static int maxalloc = 0;
void* cron_malloc(size_t a) {
cronalloc++;
crontotalalloc++;
if (cronalloc > maxalloc) {
maxalloc = cronalloc;
}
return malloc(a);
}
void cron_free(void* b) {
cronalloc--;
free(b);
}
#endif
```

Digunakan untuk mencoba mengetes cron malloc

```
uint8_t cron_get_bit (uint8_t* rbyte, int idx);
void cron_set_bit(uint8_t* rbyte, int idx);
void cron_del_bit(uint8_t* rbyte, int idx);
static crons_equal(cron_expr* cr1, cron_expr* cr2) {
unsigned int i;
for (i = 0; i < ARRAY_LEN(cr1->seconds); i++) {
if (cr1->seconds[i] != cr2->seconds[i]) {
printf("seconds not equal @%d %02x != %02x", i, cr1-
>seconds[i], cr2->seconds[i]);
return 0;
}
}
for (i = 0; i < ARRAY_LEN(cr1->minutes); i++) {
if (cr1->minutes[i] != cr2->minutes[i]) {
T14
printf("minutes not equal @%d %02x != %02x", i, cr1-
>minutes[i], cr2->minutes[i]);
return 0;
}
}
for (i = 0; i < ARRAY_LEN(cr1->hours); i++) {
if (cr1->hours[i] != cr2->hours[i]) {
printf("hours not equal @%d %02x != %02x", i, cr1->hours[i], cr2-
>hours[i]);
return 0;
}
}
for (i = 0; i < ARRAY_LEN(cr1->days_of_week); i++) {
if (cr1->days_of_week[i] != cr2->days_of_week[i]) {
printf("days_of_week not equal @%d %02x != %02x", i, cr1-
>days_of_week[i], cr2->days_of_week[i]);
return 0;
}
}
for (i = 0; i < ARRAY_LEN(cr1->days_of_month); i++) {
if (cr1->days_of_month[i] != cr2->days_of_month[i]) {
printf("days_of_month not equal @%d %02x != %02x", i, cr1-
>days_of_month[i], cr2->days_of_month[i]);
return 0;
}
}
for (i = 0; i < ARRAY_LEN(cr1->months); i++) {
if (cr1->months[i] != cr2->months[i]) {
printf("months not equal @%d %02x != %02x", i, cr1-
>months[i], cr2->months[i]);
return 0;
}
}
r
```

Bagian ini untuk mengetes benar salahnya nilai yang dimasukkan dan menloop cron sesuai yang telah di input. Input terdapat di main()

```
int main(){
printf("Masukkan detik menit jam tanggal bulan tahun. Untuk yang kosong be
ri tanda * dan diberi jarak spasi untuk setiap item");
scanf("%S %M %H %d %m %Y");
pid_t pid=fork();
if (pid==0) {
static char *argv[]={"echo","ciluk baa.",NULL};
execv("/bin/echo",argv);
exit(127);
}
else {
T14
waitpid(pid,0,0);
}
return 0;
}
```

}
Di int main() user diminta untuk memasukkan detik menit tanggal jam bulan tahun dan yang kosong diberi tanda * seperti cron biasanya.
Scanf digunakan untuk membaca input. Pid digunakan untuk menjalankan program (namun masih kesulitan).

#3 [Source](https://github.com/lumbricina/SoalShiftSISOP20_modul2_T14/blob/master/soal3.c)

```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <dirent.h>
#include <string.h>
```

Library yang digunakan adalah seperti diatas

Dalam soal ini ada 4 persoalan yaitu :
1. Membuat program yang membuat 2 direktori, direktori pertama bernama “Indomie” dan direktori kedua bernama “Sedaap”. Direktori kedua dibuat 5 detik setelah direktori pertama dibuat.

```
int main() {
  pid_t child = fork();
  int status;
  if (child < 0) 
  {
    exit(EXIT_FAILURE); 
  }

  if (child == 0) 
{
  	pid_t child_1 = fork();
  	
	  if (child_1 < 0)
  	{
  		exit(EXIT_FAILURE);
	}
    if (child_1 == 0)
    {
		char *mkd[] = {"mkdir", "-p", "/home/lumbricina/modul2/indomie", NULL};
    	execv("/bin/mkdir", mkd);
    }
}
	else 
  {
		while ((wait(&status)) > 0);
    	sleep(5);
    	char *mkd[] = {"mkdir","/home/lumbricina/modul2/sedaap", NULL};
    	execv("/bin/mkdir", mkd);
    }
  ```
  
```pid_t child = fork();``` bagian ini membuat fork agar bisa menjalankan banyak proses dalam sekali run.

```if (child < 0) exit(EXIT_FAILURE);``` bagian ini menunjukkan jika gagal dalam membuat proses baru, kemudian program akan berhenti.

```char *mkd[] = {"mkdir", "-p", "/home/lumbricina/modul2/indomie", NULL};``` bagian ini untuk membuat direktori pertama, ```"-p"``` maksudnya membuat parent direktori nya.

```while ((wait(&status)) > 0);``` bagian ini untuk delay suatu proses.

```sleep(5);``` bagian ini agar menjalankan proses selanjutnya setelah 5 detik.

```char *mkd[] = {"mkdir", "-p", "/home/lumbricina/modul2/sedaap", NULL};``` bagian ini untuk membuat direktori kedua.

2. Mengekstrak “jpg.zip” pada direktori

```
{
    	while ((wait(&status)) > 0);
    	pid_t child_2 = fork();
    	if (child_2 < 0){
      	exit(EXIT_FAILURE);
    }
    if (child_2 == 0)
	{
    	char *unzip[] = {"unzip", "/home/lumbricina/modul2/jpg.zip", NULL};
    	execv("/usr/bin/unzip", unzip);
    }
```

```pid_t child_2 = fork();``` bagian ini membuat fork agar bisa menjalankan banyak proses dalam sekalirun.

```if (child_unzip < 0) exit(EXIT_FAILURE);``` bagian ini menunjukkan jika gagal dalam membuat proses baru, kemudian program akan berhenti.

```char* unzip[] = {"unzip", "/home/lumbricina/modul2/jpg.zip", NULL};``` bagian ini untuk melakukanunzip “jpg.zip”.

3. Setelah meng-ekstrak file tersebut, hasil ekstrakan dipindahkan berdasarkan pengelompokkan. Jika hasil ekstrak berupa folder maka dimasukkan ke dalam "/indomie/" sedangkan hasil ekstrak selain folder maka dimasukkan ke dalam "/sedaap

```
{
    	while ((wait(&status)) > 0);
    	chdir("/home/lumbricina/modul2/jpg/");
    	DIR *directory;
    	directory = opendir ("jpg");
    	struct dirent *dir
    	if (dir)
    {
    	while((dir = readdir(directory)) != NULL)
		{
          pid_t child_3 = fork();
	        struct stat st;
	        stat(dir->d_name, &st);
	        if(child_3 < 0)
			{
	          exit(EXIT_FAILURE);
	        }
          if(child_3 == 0)
		  {
		  	struct stat info;
            char filename[1000];
            sprintf(filename, "/home/lumbricina/modul2/jpg/%s", dir->d_name);
            if (stat(filename, &info))
			{
              
		        exit(EXIT_FAILURE);
		    }
		    if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0);
              else
             {
              	pid_t child4 = fork();
              	if(child4 == 0)
              	{
				
              	char* move[] = {"mv", filename, "/home/lumbricina/modul2/indomie/", NULL};
                    execv("/bin/mv", move);
		             }
		    else
		    {
                char* move[] = {"mv", filename, "/home/lumbricina/modul2/sedaap/", NULL};
                execv("/bin/mv", move);
```

```while ((wait(&status)) > 0);``` bagian ini untuk delay suatu proses.

```chdir("/home/lumbricina/modul2/jpg/");``` bagian ini untuk mengubah direktori.

```DIR *directory;``` bagian ini pointer untuk menunjuk ke direktori.

```directory = opendir("jpg");``` bagian ini untuk membuka direktori handle.

```struct dirent *dir;``` bagian ini pointer untuk menunjukkan dalam direktori.

```if(dir)``` bagian ini untuk mengecek pointer yang ditunjuk benar sebuah direktori.

```while((dir = readdir(directory)) != NULL)``` bagian ini loop ketika sebuah direktori masih ada file/folder didalamnya.

```pid_t child_3 = fork();``` bagian ini membuat fork agar bisa menjalankan banyak proses dalam sekali run

```struct stat st;``` bagian ini pointer status dalam proses mengecek sebuah direktori.

```char filename[1000];``` bagian ini untuk menyimpan hasil pencarian.

```sprintf(path_file, "/home/lumbricina/modul2/jpg/%s", dir->d_name);``` bagian ini mencari file/folder yang ada dalam direktori.

```char* mv[] = {"mv", path_file, "/home/lumbricina/modul2/indomie/", NULL};``` bagian ini untuk memindahkan folder dalam direktori ke dalam direktori indomie. Selain itu akan dimasukkan ke dalam direktori sedaap.


4. Untuk setiap direktori yang sudah dipindahkan ke dalam direktori "/indomie" harus membuat 2
file kosong dengan penamaan "coba1.txt" dan "coba2.txt". Untuk file "coba2.txt" dibuat setelah 3
detik.

```
while ((wait(&status)) > 0);
pid_t child5 = fork ();
if (child_5 < 0) 
{
exit(EXIT_FAILURE); 
}
if(child_5 == 0)
{
char target[10000];
sprintf(target, "/home/lumbricina/modul2/indomie/%s/coba1.txt", dir->d_name);
char* file1[] = {"touch", target, NULL};
execv("/usr/bin/touch", file1);
                    
}
else 
{
while ((wait(&status)) > 0);
sleep(3);
char target[10000];
sprintf(target, "/home/lumbricina/modul2/indomie/%s/coba2.txt", dir->d_name);
char* file2[] = {"touch", target, NULL};
execv("/usr/bin/touch", file2);
}
```

```pid_t child_5 = fork();``` bagian ini membuat fork agar bisa menjalankan banyak proses dalam sekali run.

```char target[1000];``` bagian ini untuk menyimpan hasil pencarian.

```sprintf(target, "/home/lumbricina/modd2/indomie/%s/coba1.txt", dir->d_name);``` bagian ini mencari file/folder yang ada dalam direktori.

```Char* file1[] = {“touch”, target, NULL};``` bagian ini untuk membuat file1 (coba1).

```Char* file2[] = {“touch”, target, NULL};``` bagian ini untuk membuat file2 (coba2).


# KESULITAN
1. Soal sulit dimengerti, kurang memahami cara membuat cron di c lang
2. Soal sulit dimengerti
3. Soal sulit dimengerti
