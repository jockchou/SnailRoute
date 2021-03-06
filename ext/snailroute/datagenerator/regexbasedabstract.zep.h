
extern zend_class_entry *snailroute_datagenerator_regexbasedabstract_ce;

ZEPHIR_INIT_CLASS(SnailRoute_DataGenerator_RegexBasedAbstract);

PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, getApproxChunkSize);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, processChunk);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, addRoute);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, getData);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, generateVariableRouteData);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, computeChunkSize);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, isStaticRoute);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, addStaticRoute);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, addVariableRoute);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, buildRegexForRoute);
PHP_METHOD(SnailRoute_DataGenerator_RegexBasedAbstract, regexHasCapturingGroups);
zend_object_value zephir_init_properties_SnailRoute_DataGenerator_RegexBasedAbstract(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_processchunk, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, regexToRoutesMap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_addroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_computechunksize, 0, 0, 1)
	ZEND_ARG_INFO(0, count)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_isstaticroute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_addstaticroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_addvariableroute, 0, 0, 3)
	ZEND_ARG_INFO(0, httpMethod)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_buildregexforroute, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routeData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_datagenerator_regexbasedabstract_regexhascapturinggroups, 0, 0, 1)
	ZEND_ARG_INFO(0, regex)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_datagenerator_regexbasedabstract_method_entry) {
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, getApproxChunkSize, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, processChunk, arginfo_snailroute_datagenerator_regexbasedabstract_processchunk, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, addRoute, arginfo_snailroute_datagenerator_regexbasedabstract_addroute, ZEND_ACC_PUBLIC)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, generateVariableRouteData, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, computeChunkSize, arginfo_snailroute_datagenerator_regexbasedabstract_computechunksize, ZEND_ACC_PRIVATE)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, isStaticRoute, arginfo_snailroute_datagenerator_regexbasedabstract_isstaticroute, ZEND_ACC_PRIVATE)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, addStaticRoute, arginfo_snailroute_datagenerator_regexbasedabstract_addstaticroute, ZEND_ACC_PRIVATE)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, addVariableRoute, arginfo_snailroute_datagenerator_regexbasedabstract_addvariableroute, ZEND_ACC_PRIVATE)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, buildRegexForRoute, arginfo_snailroute_datagenerator_regexbasedabstract_buildregexforroute, ZEND_ACC_PRIVATE)
	PHP_ME(SnailRoute_DataGenerator_RegexBasedAbstract, regexHasCapturingGroups, arginfo_snailroute_datagenerator_regexbasedabstract_regexhascapturinggroups, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
