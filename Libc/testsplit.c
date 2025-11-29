#include <stdlib.h>
 
 int sep(char c)
 {
 if (c == '\n' || c == '\t' || c == ' ' || c == '\0')
 return (1);
 return (0);
 }
 
 int words(char *str)
 {
 int i;
 int j;
 
 i = 0;
 j = 0;
 while (str[i])
 {
 if (!sep(str[i]))
 {
 i++;
 j++;
 while (str[i] && !sep(str[i]))
 i++;
 }
 }
 return (j);
 }
 
 int get_len(char *str)
 {
 int i;
 int j;
 
 i = 0;
 j = 0;
 while (str[i])
 {
 if (!sep(str[i]))
 j++;
 i++;
 }
 return (j);
 }
 
 char **ft_split(char *str)
 {
 char **c;
 int wc;
 int i;
 int l;
 int j;
 int k;
 
 wc = words(str);
 c = malloc((wc + 1) * sizeof(char *));
 l = get_len(str);
 
 i = 0;
 while (i < wc)
 {
 c[i] = malloc(l + 1);
 i++;
 }
 
 i = 0;
 j = 0;
 k = 0;
 while (str[i])
 {
 if (!sep(str[i]))
 {
 c[j][k] = str[i];
 k++;
 }
 else if (k > 0)
 {
 c[j][k] = '\0';
 j++;
 k = 0;
 }
 i++;
 }
 if (k > 0)
 {
 c[j][k] = '\0';
 j++;
 }
 c[j] = NULL;
 return (c);
 }
