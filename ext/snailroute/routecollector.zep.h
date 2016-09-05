
extern zend_class_entry *snailroute_routecollector_ce;

ZEPHIR_INIT_CLASS(SnailRoute_RouteCollector);

PHP_METHOD(SnailRoute_RouteCollector, __construct);
PHP_METHOD(SnailRoute_RouteCollector, addRoute);
PHP_METHOD(SnailRoute_RouteCollector, getData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_routecollector___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, routeParser, SnailRoute\\RouteParserInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dataGenerator, SnailRoute\\DataGeneratorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_routecollector_addroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, route)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_routecollector_method_entry) {
	PHP_ME(SnailRoute_RouteCollector, __construct, arginfo_snailroute_routecollector___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailRoute_RouteCollector, addRoute, arginfo_snailroute_routecollector_addroute, ZEND_ACC_PUBLIC)
	PHP_ME(SnailRoute_RouteCollector, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
