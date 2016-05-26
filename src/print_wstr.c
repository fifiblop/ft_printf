
#include "printf.h"

int		print_wstr(t_opt *opt, va_list *args)
{
	wchar_t	*str;
	int		size;

	if ((str = va_arg(*args, wchar_t*)) == NULL)
		str = L"(null)";
	size = ft_wstrlen(str);
	if (opt->accu && opt->accu_v < size)
		size = opt->accu_v;
	print_width_before(opt, opt->min_w - size);
	ft_putwstr(str);
	print_width_after(opt, opt->min_w - size);
	if (opt->min_w > size)
		return (opt->min_w);
	return (size);
}
