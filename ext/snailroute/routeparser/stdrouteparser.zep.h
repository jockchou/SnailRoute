
extern zend_class_entry *snailroute_routeparser_stdrouteparser_ce;

ZEPHIR_INIT_CLASS(SnailRoute_RouteParser_StdRouteParser);

PHP_METHOD(SnailRoute_RouteParser_StdRouteParser, parse);
PHP_METHOD(SnailRoute_RouteParser_StdRouteParser, parsePlaceholders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_routeparser_stdrouteparser_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_routeparser_stdrouteparser_parseplaceholders, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_routeparser_stdrouteparser_method_entry) {
	PHP_ME(SnailRoute_RouteParser_StdRouteParser, parse, arginfo_snailroute_routeparser_stdrouteparser_parse, ZEND_ACC_PUBLIC)
	PHP_ME(SnailRoute_RouteParser_StdRouteParser, parsePlaceholders, arginfo_snailroute_routeparser_stdrouteparser_parseplaceholders, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
