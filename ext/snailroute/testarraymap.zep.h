
extern zend_class_entry *snailroute_testarraymap_ce;

ZEPHIR_INIT_CLASS(SnailRoute_TestArrayMap);

PHP_METHOD(SnailRoute_TestArrayMap, process);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_testarraymap_process, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_testarraymap_method_entry) {
	PHP_ME(SnailRoute_TestArrayMap, process, arginfo_snailroute_testarraymap_process, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
