
extern zend_class_entry *snailroute_route_ce;

ZEPHIR_INIT_CLASS(SnailRoute_Route);

PHP_METHOD(SnailRoute_Route, __construct);
PHP_METHOD(SnailRoute_Route, matches);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_route___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, regex)
	ZEND_ARG_ARRAY_INFO(0, variables, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_route_matches, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_route_method_entry) {
	PHP_ME(SnailRoute_Route, __construct, arginfo_snailroute_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailRoute_Route, matches, arginfo_snailroute_route_matches, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
