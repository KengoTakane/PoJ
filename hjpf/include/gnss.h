/*============================================================================*/
/*
 * @file    GNSS.h
 * @brief   GNSS management
 * @note    GNSS management
 * @date    2023/11/30
 */
/*============================================================================*/
#ifndef __GNSS_H
#define __GNSS_H

/*============================================================================*/
/* include */
/*============================================================================*/
#include <stdio.h>

/*============================================================================*/
/* define */
/*============================================================================*/
#define DEF_GNSS_TEST (0)               //テスト用
#define DEF_BUF_SIZE (256)              //バッファサイズ
#define DEF_FRAME_SIZE (2049)           //フレームサイズ
#define DEF_READ_SIZE (1024)            //読込サイズ
#define DEF_LATI_NORTH (0)              //北緯
#define DEF_LATI_SOUTH (1)              //南緯
#define DEF_LONG_EAST (0)               //東経
#define DEF_LONG_WEST (1)               //西経
#define DEF_GNSS_READ_NODATA (-2)		//read時空読み判定
#define DEF_GNSS_SHMEM_NAME "/gnss"     //GNSS共有メモリ名

#pragma pack(1)
/*============================================================================*/
/* typedef */
/*============================================================================*/
typedef struct _gga{
    double time;
    double latitude;
    int latitude_sign;
    double longitude;
    int longitude_sign;
    int mode_status;
    int satelite_num;
    double hdop;
    double height_sea;
    double height_geoid;
} GGA;

typedef struct _rmc{
    double time;
    double latitude;
    int latitude_sign;
    double longitude;
    int longitude_sign;
    double knots;
    int date;
    double azimuth;
    double mag_dec;
    int mag_dec_dir;
    char mode_status[4];
} RMC;

typedef struct _gsa{
    double pdop;
    double hdop;
} GSA;

typedef struct _gnssStat{
    int Stat;
    GGA gga;
    RMC rmc;
    GSA gsa;
} gnssStat;
#pragma pack()

/*============================================================================*/
/* enum */
/*============================================================================*/

/*============================================================================*/
/* struct */
/*============================================================================*/

/*============================================================================*/
/* func */
/*============================================================================*/

/*============================================================================*/
/* extern(val) */
/*============================================================================*/

/*============================================================================*/
/* extern(func) */
/*============================================================================*/
extern void* GNSSMain(void* arg);

/*============================================================================*/
/* Macro */
/*============================================================================*/

#endif	/* __GNSS_H */
