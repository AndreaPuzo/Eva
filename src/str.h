#ifndef __EVA_STR_H
# define __EVA_STR_H

# ifndef __EVA_API
#   define __EVA_API
# endif

__EVA_API void eva_chpres(char **str, long *len);
__EVA_API long eva_cpybuf(char *dst, const char *src, long len);
__EVA_API int eva_cmpbuf(const char *lbuf, const char *rbuf, long len);
__EVA_API long eva_lenstr(const char *src);
__EVA_API char *eva_dupstr(const char *src);
__EVA_API char *eva_dupnstr(const char *src, long len);
__EVA_API long eva_cpystr(char *dst, const char *src);
__EVA_API long eva_cpynstr(char *dst, const char *src, long len);
__EVA_API int eva_cmpstr(const char *lstr, const char *rstr);
__EVA_API int eva_cmpnstr(const char *lstr, const char *rstr, long len);
__EVA_API char *eva_ltrmstr(char *src, long *len);
__EVA_API char *eva_rtrmstr(char *src, long *len);
__EVA_API char *eva_trmstr(char *src, long *len);
__EVA_API char *eva_lchpstr(char *src, long *len, long n);
__EVA_API char *eva_rchpstr(char *src, long *len, long n);
__EVA_API char *eva_chpstr(char *src, long *len, char del);
__EVA_API char *eva_lchrstr(const char *src, long len, char chr);
__EVA_API char *eva_rchrstr(const char *src, long len, char chr);
__EVA_API char *eva_lstrstr(const char *src, long len, const char *str);
__EVA_API char *eva_rstrstr(const char *src, long len, const char *str);

# define eva_chrstr eva_lchrstr
# define eva_strstr eva_lstrstr

#endif
