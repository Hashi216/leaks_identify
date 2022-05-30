
// #define LEAKS_IDENTIFY
// #ifdef LEAK_IDENTIFY
#include "leaks_identify.h"
#define init leaks_identify_init
#define malloc(s) leaks_identify_malloc(s, __FILE__, __LINE__)
#define free leaks_identify_free
#define check leaks_identify_check
// #else
// #define init()
// #define check()
// #endif

int main(void){
    int *p[8];

    /* メモリ管理配列の初期化 */
    init();

    /* メモリの確保 */
    p[0] = (int*)malloc(sizeof(int));
    p[1] = (int*)malloc(sizeof(int));
    p[2] = (int*)malloc(sizeof(int));
    p[3] = (int*)malloc(sizeof(int));
    p[4] = (int*)malloc(sizeof(int));
    p[5] = (int*)malloc(sizeof(int));
    p[6] = (int*)malloc(sizeof(int));
    p[7] = (int*)malloc(sizeof(int));

    /* メモリの解放 */
    free(p[4]);
    free(p[7]);

    /* メモリの解放忘れを表示 */
    check();

    return 0;
}