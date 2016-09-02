
extern zend_class_entry *snailroute_dispatcher_regexbasedabstract_ce;

ZEPHIR_INIT_CLASS(SnailRoute_Dispatcher_RegexBasedAbstract);

PHP_METHOD(SnailRoute_Dispatcher_RegexBasedAbstract, dispatchVariableRoute);
PHP_METHOD(SnailRoute_Dispatcher_RegexBasedAbstract, dispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_dispatcher_regexbasedabstract_dispatchvariableroute, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_dispatcher_regexbasedabstract_dispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_dispatcher_regexbasedabstract_method_entry) {
	PHP_ME(SnailRoute_Dispatcher_RegexBasedAbstract, dispatchVariableRoute, arginfo_snailroute_dispatcher_regexbasedabstract_dispatchvariableroute, ZEND_ACC_PROTECTED|ZEND_ACC_ABSTRACT)
	PHP_ME(SnailRoute_Dispatcher_RegexBasedAbstract, dispatch, arginfo_snailroute_dispatcher_regexbasedabstract_dispatch, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
