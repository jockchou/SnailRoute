
extern zend_class_entry *snailroute_routeparser_std_ce;

ZEPHIR_INIT_CLASS(SnailRoute_RouteParser_Std);

PHP_METHOD(SnailRoute_RouteParser_Std, parse);
PHP_METHOD(SnailRoute_RouteParser_Std, parsePlaceholders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_routeparser_std_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_routeparser_std_parseplaceholders, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_routeparser_std_method_entry) {
	PHP_ME(SnailRoute_RouteParser_Std, parse, arginfo_snailroute_routeparser_std_parse, ZEND_ACC_PUBLIC)
	PHP_ME(SnailRoute_RouteParser_Std, parsePlaceholders, arginfo_snailroute_routeparser_std_parseplaceholders, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
