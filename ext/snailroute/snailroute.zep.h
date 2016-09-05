
extern zend_class_entry *snailroute_snailroute_ce;

ZEPHIR_INIT_CLASS(SnailRoute_SnailRoute);

PHP_METHOD(SnailRoute_SnailRoute, simpleDispatcher);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_snailroute_simpledispatcher, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_snailroute_method_entry) {
	PHP_ME(SnailRoute_SnailRoute, simpleDispatcher, arginfo_snailroute_snailroute_simpledispatcher, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
