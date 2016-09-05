
extern zend_class_entry *snailroute_testarraymapabstract_ce;

ZEPHIR_INIT_CLASS(SnailRoute_TestArrayMapAbstract);

PHP_METHOD(SnailRoute_TestArrayMapAbstract, process);
PHP_METHOD(SnailRoute_TestArrayMapAbstract, run);

ZEND_BEGIN_ARG_INFO_EX(arginfo_snailroute_testarraymapabstract_process, 0, 0, 1)
	ZEND_ARG_INFO(0, user)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(snailroute_testarraymapabstract_method_entry) {
	PHP_ME(SnailRoute_TestArrayMapAbstract, process, arginfo_snailroute_testarraymapabstract_process, ZEND_ACC_PROTECTED|ZEND_ACC_ABSTRACT)
	PHP_ME(SnailRoute_TestArrayMapAbstract, run, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
