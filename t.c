#include "init.h"


int main()
{
    char *hs = "42,0xff";

//    char *res = ft_strnstr(hs,"0x", ft_strlen(hs));
//    char  *res = ft_strtrim(hs, "0x");
    char *res = ft_strchr(hs, ',');
    printf("%s\n", ft_strtrim(res, ",0x"));
}