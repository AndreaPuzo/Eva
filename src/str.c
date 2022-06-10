#include <stdlib.h>
#include <ctype.h>
#include "str.h"

char *__chpres_str = NULL;
long __chpres_len = 0;

__EVA_API void eva_chpres(char **str, long *len) {
  *str = __chpres_str;
  *len = __chpres_len;
}

__EVA_API long eva_cpybuf(char *dst, const char *src, long len)
{
  long n = 0;
  
  while (n < len) {
    dst[n] = src[n];
    ++n;
  }
  
  return n;
}

__EVA_API int eva_cmpbuf(const char *lbuf, const char *rbuf, long len)
{
  long n = 0;
  
  while (lbuf[n] && lbuf[n] == rbuf[n] && n < len)
    ++n;

  return (int)lbuf[n] - (int)rbuf[n];
}

__EVA_API long eva_lenstr(const char *src)
{
  char *c = (char *)src;
  
  while (*c != 0)
    ++c;

  return (long)c - (long)src;
}

__EVA_API char *eva_dupstr(const char *src)
{
  long n = eva_lenstr(src), k = 0;
  char *str = malloc(n + 1);
  
  if (str) {
    while ((str[k] = src[k]) != 0)
      ++k;
  }

  return str;
}

__EVA_API char *eva_dupnstr(const char *src, long len)
{
  long n = 0;
  char *str = malloc(len + 1);
  
  if (str) {
    while (n < len) {
      str[n] = src[n];
      ++n;
    }
  }

  return str;
}

__EVA_API long eva_cpystr(char *dst, const char *src)
{
  long n = 0;
  
  while ((dst[n] = src[n]) != 0)
    ++n;
  
  return n;
}

__EVA_API long eva_cpynstr(char *dst, const char *src, long len)
{
  long n = 0;
  
  while (n < len && (dst[n] = src[n]) != 0)
    ++n;
  
  return n;
}

__EVA_API int eva_cmpstr(const char *lstr, const char *rstr)
{
  long n = 0;
  
  while (lstr[n] && lstr[n] == rstr[n])
    ++n;

  return (int)lstr[n] - (int)rstr[n];
}

__EVA_API int eva_cmpnstr(const char *lstr, const char *rstr, long len)
{
  long n = 0;
  
  while (lstr[n] && lstr[n] == rstr[n] && n < len)
    ++n;

  if (n == len)
    return 0;

  return (int)lstr[n] - (int)rstr[n];
}

__EVA_API char *eva_ltrmstr(char *src, long *len)
{
  long n = 0;
  
  while (n < *len && isspace(src[n]))
    ++n;
  
  src += n;
  *len -= n;
  
  return src;
}

__EVA_API char *eva_rtrmstr(char *src, long *len)
{
  long n = *len - 1;

  while (n != 0 && isspace(src[n]))
    --n;
  
  *len = n + 1;
  
  return src;
}


__EVA_API char *eva_trmstr(char *src, long *len)
{
  src = eva_ltrmstr(src, len);
  src = eva_rtrmstr(src, len);
  
  return src;
}

__EVA_API char *eva_lchpstr(char *src, long *len, long n)
{
  if (n > *len)
    n = *len;
  
  __chpres_str = src;
  __chpres_len = n;
  
  src += n;
  *len -= n;
  
  return src;
}

__EVA_API char *eva_rchpstr(char *src, long *len, long n)
{
  if (n > *len)
    n = *len;
  
  __chpres_str = src + *len - n;
  __chpres_len = n;
  
  *len -= n;
  
  return src;
}

__EVA_API char *eva_chpstr(char *src, long *len, char del)
{
  long n = 0;
  
  while (n < *len && src[n] != del)
    ++n;
  
  __chpres_str = src;
  __chpres_len = n;
  
  if (n < *len)
    ++n;
  
  src += n;
  *len -= n;
  
  return src;
}

__EVA_API char *eva_lchrstr(const char *src, long len, char chr)
{
  long n = 0;
  
  while (n < len && src[n] != chr)
    ++n;
  
  if (n < len)
    return (char *)src + n;
  
  return NULL;
}

__EVA_API char *eva_rchrstr(const char *src, long len, char chr)
{
  long n = len - 1;
  
  while (n != 0 && src[n] != chr)
    --n;
  
  if (n != 0)
    return (char *)src + n;
  
  return NULL;
}

__EVA_API char *eva_lstrstr(const char *src, long len, const char *str)
{
  long n = 0, k = 0, l = eva_lenstr(str);
  
  if (len < l)
    return NULL;
  
  if (len == l) {
    if (eva_cmpnstr(src, str, len) == 0)
      return (char *)src;
    
    return NULL;
  }    
  
  while (n < len) {    
    while (n < len && k < l && src[n] == str[k]) {
      ++n;
      ++k;
    }
    
    if (k == l)
      return (char *)src + (n - k);
    else {
      ++n;
      k = 0;
    }
  }
  
  return NULL;
}

__EVA_API char *eva_rstrstr(const char *src, long len, const char *str)
{
  long n = len - 1, k = 0, l = eva_lenstr(str);
  
  if (len < l)
    return NULL;
  
  if (len == l) {
    if (eva_cmpnstr(src, str, len) == 0)
      return (char *)src;
    
    return NULL;
  }    
  
  while (n >= 0) {
    if (eva_cmpnstr(src + n, str, l) == 0)
      return (char *)src + n;
    
    --n;
  }
  
  return NULL;
}
