/*============================================================================*/
/*
 * @file    com_shmem.h
 * @brief   共有メモリ
 * @note    共有メモリ関連処理を行う。
 * @date    2013/09/29
 */
 /*============================================================================*/
#ifndef __COM_SHMEM_H
#define __COM_SHMEM_H

/*============================================================================*/
/* include */
/*============================================================================*/
#include <semaphore.h>
#include <stdint.h>

/*============================================================================*/
/* typedef */
/*============================================================================*/

/*============================================================================*/
/* define */
/*============================================================================*/
#define	DEF_COM_SHMEM_FALSE		(-1)	/* エラー */
#define	DEF_COM_SHMEM_TRUE		(0)		/* 正常終了 */
#define DEF_COM_SHMEM_MODE		(0666)	/* 共有メモリオープンモード */
#define DEF_COM_SHMEM_OFFSET	(0)		/* マッピングのオフセット */
#define DEF_COM_SHMEM_PATH_MAX	(100)	/* 保存ファイル名の最大サイズ */
#define DEF_COM_SHMEM_MAX		(128)	/* 共有メモリ数の最大値 */

/*============================================================================*/
/* enum */
/*============================================================================*/
enum shm_kind {
	SHM_KIND_NONE = 0,
	SHM_KIND_PLATFORM = 1,	/* 種別：PF */
	SHM_KIND_USER = 2,		/* 種別：ユーザプロセス */
	SHM_KIND_PROC = 3,
	SHM_KIND_MAX
};

/*============================================================================*/
/* struct */
/*============================================================================*/
typedef struct _shm_mng
{
	char name[256];			/* 共有メモリ名 */
	int32_t size;			/* サイズ */
	enum shm_kind kind;			/* 種別 */
	char path[DEF_COM_SHMEM_PATH_MAX];	/* 保存ファイル名 */
	sem_t* sem;				/* セマフォ */
	int32_t shmfd;			/* 共有メモリファイルディスクリプタ */
	enum shm_kind current;		/* カレント種別 */
	void* address;			/* アドレス */
	int32_t counter;		/* カウンタ */
} memoryInfo;
/*============================================================================*/
/* func */
/*============================================================================*/

/*============================================================================*/
/* extern(val) */
/*============================================================================*/

/*============================================================================*/
/* extern(func) */
/*============================================================================*/
int32_t com_shmem_init(void);
int32_t com_shmem_open(char*, enum shm_kind);
int32_t com_shmem_close(int32_t);
int32_t com_shmem_read(int32_t, void*, int32_t);
int32_t com_shmem_write(int32_t, void*, int32_t);
void com_shmem_destroy(void);
int32_t com_shmem_conf(char*);


/*============================================================================*/
/* Macro */
/*============================================================================*/

#endif	/* __COM_SHMEM_H */