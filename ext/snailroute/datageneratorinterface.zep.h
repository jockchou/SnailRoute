
extern zend_class_entry *snailroute_datageneratorinterface_ce;

ZEPHIR_INIT_CLASS(SnailRoute_DataGeneratorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datageneratorinterface_addroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_datageneratorinterface_method_entry) {
	PHP_ABSTRACT_ME(SnailRoute_DataGeneratorInterface, addRoute, arginfo_snailroute_datageneratorinterface_addroute)
	PHP_ABSTRACT_ME(SnailRoute_DataGeneratorInterface, getData, NULL)
	PHP_FE_END
};
