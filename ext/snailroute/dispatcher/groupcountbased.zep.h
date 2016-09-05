
extern zend_class_entry *snailroute_dispatcher_groupcountbased_ce;

ZEPHIR_INIT_CLASS(SnailRoute_Dispatcher_GroupCountBased);

PHP_METHOD(SnailRoute_Dispatcher_GroupCountBased, __construct);
PHP_METHOD(SnailRoute_Dispatcher_GroupCountBased, dispatchVariableRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_dispatcher_groupcountbased___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_dispatcher_groupcountbased_dispatchvariableroute, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_dispatcher_groupcountbased_method_entry) {
	PHP_ME(SnailRoute_Dispatcher_GroupCountBased, __construct, arginfo_snailroute_dispatcher_groupcountbased___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(SnailRoute_Dispatcher_GroupCountBased, dispatchVariableRoute, arginfo_snailroute_dispatcher_groupcountbased_dispatchvariableroute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
