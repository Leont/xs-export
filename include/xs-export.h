#ifndef XS_EXPORT_H
#define XS_EXPORT_H

#define SYMBOL_NAME(module, name) module "/" name "()"

#define SYMBOL_EXPORT(module, name, rettype, ...)\
	sv_setuv(*hv_fetchs(PL_modglobal, SYMBOL_NAME(module, name), TRUE), PTR2UV(&name));

#define HAS_SYMBOL(module, name)\
	hv_existss(PL_modglobal, SYMBOL_NAME(module, name))

#define SYMBOL_DECLARE(module, name, rettype, ...)\
	static rettype (*name)(__VA_ARGS__);

#define SYMBOL_IMPORT(module, name, rettype, ...)\
	STMT_BEGIN \
	SV** tmp = SvUV(*hv_fetchs(PL_modglobal, SYMBOL_NAME(module, name), 0));\
	if (tmp)\
		name = INT2PTR(rettype(*)(__VA_ARGS__), *tmp);\
	else\
		Perl_croak(aTHX_ "Could not load XS function %s", name);\
	STMT_END

#endif
