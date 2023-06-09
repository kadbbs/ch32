#ifndef __FONT_H__
#define __FONT_H__	 





#define array_len(n) sizeof(n)
//常用ASCII表
//偏移量32
//ASCII字符集: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//PC2LCD2002取模方式设置：阴码+逐列式+顺向+C51格式
//总共：2个字符集（16*16和24*24），用户可以自行新增其他分辨率的字符集。
//每个字符所占用的字节数为:(size/8+((size%8)?1:0))*(size/2),其中size:是字库生成时的点阵大小(12/16/24...)
//1608 ASCII字符集点阵
extern const unsigned char asc2_1608[95][16]; 
//2412 ASICII字符集点阵
extern const unsigned char asc2_2412[95][36];
//3216 ASICII字符集点阵
extern const unsigned char asc2_3216[95][64];
//4824 数码管字体ASICII字符集点阵
extern const unsigned char asc2_4824[95][144];

/* 中文字符 */
extern const unsigned char pandora_ch[];
extern const unsigned char my_name[];
extern const unsigned char yun[];
extern const unsigned char win_sign[];
extern unsigned char yehuo[];
extern const unsigned char  bitmap_wd_bytes[];
extern unsigned char bitmap_sd_bytes[];
extern unsigned char ye[];
extern unsigned char huo[];
extern unsigned char shao[];
extern unsigned char bu[];
extern unsigned char jin[];
extern unsigned char chun[];
extern unsigned char chunfeng[];
extern unsigned char dao[];

extern unsigned char hello[];
void zhuanhua(unsigned char *a,int n);
#endif

