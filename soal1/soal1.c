#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "ccronexpr.h"

#define max_seconds 60
#define max_minutes 60
#define max_hours 24
#define max_days_week 8
#define max_days_months 32
#define max_months 12

#define INVALID_INSTANT ((time_t) -1)
#define date_format "%Y-%m-%d_%H:%M:%S"

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

uint8_t cron_get_bit (uint8_t* rbyte, int idx);
void cron_set_bit(uint8_t* rbyte, int idx);
void cron_del_bit(uint8_t* rbyte, int idx);

static crons_equal(cron_expr* cr1, cron_expr* cr2) {
    unsigned int i;
    for (i = 0; i < ARRAY_LEN(cr1->seconds); i++) {
        if (cr1->seconds[i] != cr2->seconds[i]) {
            printf("seconds not equal @%d %02x != %02x", i, cr1->seconds[i], cr2->seconds[i]);
            return 0;
        }
    }
    for (i = 0; i < ARRAY_LEN(cr1->minutes); i++) {
        if (cr1->minutes[i] != cr2->minutes[i]) {
            printf("minutes not equal @%d %02x != %02x", i, cr1->minutes[i], cr2->minutes[i]);
            return 0;
        }
    }
    for (i = 0; i < ARRAY_LEN(cr1->hours); i++) {
        if (cr1->hours[i] != cr2->hours[i]) {
            printf("hours not equal @%d %02x != %02x", i, cr1->hours[i], cr2->hours[i]);
            return 0;
        }
    }
    for (i = 0; i < ARRAY_LEN(cr1->days_of_week); i++) {
        if (cr1->days_of_week[i] != cr2->days_of_week[i]) {
            printf("days_of_week not equal @%d %02x != %02x", i, cr1->days_of_week[i], cr2->days_of_week[i]);
            return 0;
        }
    }
    for (i = 0; i < ARRAY_LEN(cr1->days_of_month); i++) {
        if (cr1->days_of_month[i] != cr2->days_of_month[i]) {
            printf("days_of_month not equal @%d %02x != %02x", i, cr1->days_of_month[i], cr2->days_of_month[i]);
            return 0;
        }
    }
    for (i = 0; i < ARRAY_LEN(cr1->months); i++) {
        if (cr1->months[i] != cr2->months[i]) {
            printf("months not equal @%d %02x != %02x", i, cr1->months[i], cr2->months[i]);
            return 0;
        }
    }
    return 1;
}

int main(){
    printf("Masukkan detik menit jam tanggal bulan tahun. Untuk yang kosong beri tanda * dan diberi jarak spasi untuk setiap item");
    scanf("%S %M %H %d %m %Y");
    if ()
}
